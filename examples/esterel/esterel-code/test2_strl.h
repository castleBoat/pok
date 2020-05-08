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
 * Created by julien on Tue Mar 10 14:26:18 2009
 */

/*
  File: C:\DOCUME~1\ADMINI~1\Bureau\Default\Code/test2_strl.h
  Date: Tue Mar 10 13:06:58 2009

  Unit: divider

  Generated by eicfastc:
               version: v7_51i24
               released: 17/07/2008
               rcs name: p288r13
    With libraries: eic (p882r14), BigNum (p38r1)
*/

#ifndef divider_STRL_HEADER
#define divider_STRL_HEADER

/* Basic types */

/* Bit type */
typedef char _BIT_TYPE;
#define _true 1
#define _false 0

typedef char boolean;
typedef int integer;
#ifndef STRLEN
#define STRLEN 81
#endif
typedef char *string;
typedef unsigned int unsigned_int_type;
typedef signed int signed_int_type;
typedef unsigned_int_type strl_unsigned;
typedef signed_int_type strl_signed;
typedef unsigned_int_type strl_bitvector;

/* Enum types */

/* Type definitions */

/* Universal reactive API */

/* Input signals with status functions */
extern void divider_I_nb(strl_unsigned);

/* Input value-only signals functions */

/* Output signals with status functions */
#ifndef divider_O_res
extern void divider_O_res(int);
#endif

/* Output value-only signals functions */

/* init */
extern int divider_init();

/* end */
extern int divider_end();

/* reset */
extern int divider_reset();

/* reaction */
extern int divider();
extern int divider_run();

#endif
