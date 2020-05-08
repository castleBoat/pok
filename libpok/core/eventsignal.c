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

#if defined(POK_NEEDS_EVENTS) || defined(POK_NEEDS_BUFFERS) ||                 \
    defined(POK_NEEDS_BLACKBOARDS)

#include <core/event.h>
#include <core/lockobj.h>
#include <core/syscall.h>
#include <errno.h>
#include <types.h>

pok_ret_t pok_event_signal(pok_event_id_t id) {
  pok_lockobj_lockattr_t lockattr;
  lockattr.operation = LOCKOBJ_OPERATION_SIGNAL;
  lockattr.obj_kind = POK_LOCKOBJ_KIND_EVENT;
  return pok_syscall2(POK_SYSCALL_LOCKOBJ_OPERATION, (uint32_t)id,
                      (uint32_t)&lockattr);
}

#endif
