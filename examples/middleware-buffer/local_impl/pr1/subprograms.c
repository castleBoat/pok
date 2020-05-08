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

#include "types.h"

void user_do_ping_spg(simple_type *data_source);

void user_send(uint8_t *);
void user_receive(uint8_t);
/*****************/
/* do_ping_spg   */
/*****************/

void do_ping_spg(simple_type *data_source) { user_send(data_source); }

void user_ping_spg(simple_type data_source);

/*****************/
/* do_ping_spg   */
/*****************/

void ping_spg(simple_type data_source) { user_receive(data_source); }
