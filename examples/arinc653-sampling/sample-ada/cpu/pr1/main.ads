--                               POK header
--
-- The following file is a part of the POK project. Any modification should
-- be made according to the POK licence. You CANNOT use this file or a part
-- of a file for your own project.
--
-- For more information on the POK licence, please see our LICENCE FILE
--
-- Please follow the coding guidelines described in doc/CODING_GUIDELINES
--
--                                      Copyright (c) 2007-2021 POK team

pragma No_Run_Time;

with Interfaces.C;
with APEX;
use APEX;
with APEX.Processes;
use APEX.Processes;
with APEX.Partitions;
use APEX.Partitions;
with APEX.Timing;
use APEX.Timing;
with APEX.Sampling_Ports;
use APEX.Sampling_Ports;

package Main is
   procedure Send;
   procedure Main;
   pragma Export (C, Main, "main");
end Main;
