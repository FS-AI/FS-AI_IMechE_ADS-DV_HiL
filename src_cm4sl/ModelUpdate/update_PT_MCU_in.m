subs = [];
opts = [];


sfunparam    = 'cm_ptmotorcu_in';
ModSys       = 'CreateBus MCU_Cfg ISG';
ModifiedPort = 2;
PortKind     = 'Outport';

subs_add = FindSubsFromSFun (sfunparam, ModSys, ModifiedPort, PortKind);
subs     = [subs, subs_add];


sfunparam    = 'cm_ptmotorcu_in';
ModSys       = 'CreateBus MCU_Cfg Motor0';
ModifiedPort = 3;
PortKind     = 'Outport';

subs_add = FindSubsFromSFun (sfunparam, ModSys, ModifiedPort, PortKind);
subs     = [subs, subs_add];


sfunparam    = 'cm_ptmotorcu_in';
ModSys       = 'CreateBus MCU_Cfg Motor1';
ModifiedPort = 4;
PortKind     = 'Outport';

subs_add = FindSubsFromSFun (sfunparam, ModSys, ModifiedPort, PortKind);
subs     = [subs, subs_add];


sfunparam    = 'cm_ptmotorcu_in';
ModSys       = 'CreateBus MCU_Cfg Motor2';
ModifiedPort = 5;
PortKind     = 'Outport';

subs_add = FindSubsFromSFun (sfunparam, ModSys, ModifiedPort, PortKind);
subs     = [subs, subs_add];


sfunparam    = 'cm_ptmotorcu_in';
ModSys       = 'CreateBus MCU_Cfg Motor3';
ModifiedPort = 6;
PortKind     = 'Outport';

subs_add = FindSubsFromSFun (sfunparam, ModSys, ModifiedPort, PortKind);
subs     = [subs, subs_add];


sfunparam    = 'cm_ptmotorcu_in';
ModSys       = 'CreateBus MCU ISGIn';
ModifiedPort = 8;
PortKind     = 'Outport';

subs_add = FindSubsFromSFun (sfunparam, ModSys, ModifiedPort, PortKind);
subs     = [subs, subs_add];


sfunparam    = 'cm_ptmotorcu_in';
ModSys       = 'CreateBus MCU MotorIn0';
ModifiedPort = 10;
PortKind     = 'Outport';

subs_add = FindSubsFromSFun (sfunparam, ModSys, ModifiedPort, PortKind);
subs     = [subs, subs_add];


sfunparam    = 'cm_ptmotorcu_in';
ModSys       = 'CreateBus MCU MotorIn1';
ModifiedPort = 11;
PortKind     = 'Outport';

subs_add = FindSubsFromSFun (sfunparam, ModSys, ModifiedPort, PortKind);
subs     = [subs, subs_add];


sfunparam    = 'cm_ptmotorcu_in';
ModSys       = 'CreateBus MCU MotorIn2';
ModifiedPort = 12;
PortKind     = 'Outport';

subs_add = FindSubsFromSFun (sfunparam, ModSys, ModifiedPort, PortKind);
subs     = [subs, subs_add];


sfunparam    = 'cm_ptmotorcu_in';
ModSys       = 'CreateBus MCU MotorIn3';
ModifiedPort = 13;
PortKind     = 'Outport';

subs_add = FindSubsFromSFun (sfunparam, ModSys, ModifiedPort, PortKind);
subs     = [subs, subs_add];


opts.OldPortNumsIn  = [1];
opts.OldPortNumsOut = [1];
% opts.FontSizeLabel  = 2;
opts.AddTerms       = 1;

ReplaceAndReconnect(subs, opts);

clear opts subs;
