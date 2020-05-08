/*
 *                               POK header
 *
 * The following file is a part of the POK project. Any modification should
 * made according to the POK licence. You CANNOT use this file or a part of
 * this file is this part of a file for your own project
 *
 * For more information on the POK licence, please see our LICENCE FILE
 *
 * Please follow the coding guidelines described in doc/CODING_GUIDELINES
 *
 *                                      Copyright (c) 2007-2009 POK team
 *
 * Created by julien on Thu Jan 15 23:34:13 2009
 */

/**
 * \file loader.c
 * \author Julian Pidancet
 * \author Julien Delange
 * \date 2008-2009
 *
 * Contains all needed stuff to load partitions (elf files).
 * This needs the partitioning service (POK_NEEDS_PARTITIONS must
 * be defined) to work.
 */

#ifdef POK_NEEDS_PARTITIONS

#include <core/cpio.h>
#include <core/error.h>
#include <core/partition.h>
#include <elf.h>
#include <errno.h>
#include <libc.h>
#include <types.h>

/**
 * part_sizes is automatically generated by the build process and contains the
 * size of the elf file of the partitions.
 */
extern uint32_t part_sizes[];

/**
 * Load an ELF file.
 * \warning Shoud be not used alone, called by pok_loader_load_partition
 */
static pok_ret_t pok_loader_elf_load(char *file, uint32_t offset,
                                     void **entry) {
  Elf32_Ehdr *elf_header;
  Elf32_Phdr *elf_phdr;
  unsigned int i;
  char *dest;

  elf_header = (Elf32_Ehdr *)file;

  if (elf_header->e_ident[0] != 0x7f || elf_header->e_ident[1] != 'E' ||
      elf_header->e_ident[2] != 'L' || elf_header->e_ident[3] != 'F') {
    return POK_ERRNO_NOTFOUND;
  }

  *entry = (void *)elf_header->e_entry;

  elf_phdr = (Elf32_Phdr *)(file + elf_header->e_phoff);

  for (i = 0; i < elf_header->e_phnum; ++i) {
    dest = (char *)elf_phdr[i].p_vaddr + offset;

    memcpy(dest, elf_phdr[i].p_offset + file, elf_phdr[i].p_filesz);
    memset(dest + elf_phdr[i].p_filesz, 0,
           elf_phdr[i].p_memsz - elf_phdr[i].p_filesz);
  }

  return POK_ERRNO_OK;
}

void pok_loader_load_partition(const uint8_t part_id, uint32_t offset,
                               uint32_t *entry) {
  void *elf_entry = NULL;
  extern char __archive2_begin;
  uint32_t size;
  uint8_t t;

  size = 0;
  t = 0;

  while (t < part_id) {
    size += part_sizes[t];
    t++;
  }

  if (pok_partitions[part_id].size < part_sizes[part_id]) {
#ifdef POK_NEEDS_ERROR_HANDLING
    pok_partition_error(part_id, POK_ERROR_KIND_PARTITION_CONFIGURATION);
#else
#ifdef POK_NEEDS_DEBUG
    /* We consider that even if errors are not raised, we must print an error
     * for such error
     * So, when we are using the debug mode, we print a fatal error.
     */
#include <core/debug.h>
#include <libc.h>
    printf("Declared size for partition %d : %d\n", part_id,
           pok_partitions[part_id].size);
    printf("Real size for partition %d     : %d\n", part_id,
           part_sizes[part_id]);
    pok_fatal("Partition size is not correct\n");
#endif
#endif
  }
  /*
   *  FIXME : current debug session about exceptions-handled
  printf ("Will load partition at offset 0x%x\n", offset);
  */
  pok_loader_elf_load((&__archive2_begin) + size, offset, &elf_entry);

  *entry = (uint32_t)elf_entry;
}

#endif /* POK_NEEDS_PARTITIONS */
