% Update cm_ptmotorcu_out
subs = [];


sfunparam    = 'cm_ptmotorcu_out';
ModSys       = 'Adapt MCU ISGOut from CM12 to CM13';
ModifiedPort = 2;
PortKind     = 'Inport';

subs_add = FindSubsFromSFun (sfunparam, ModSys, ModifiedPort, PortKind);
subs     = [subs, subs_add];


sfunparam    = 'cm_ptmotorcu_out';
ModSys       = 'Adapt MCU MotorOut0 from CM12 to CM13';
ModifiedPort = 3;
PortKind     = 'Inport';

subs_add = FindSubsFromSFun (sfunparam, ModSys, ModifiedPort, PortKind);
subs     = [subs, subs_add];


sfunparam    = 'cm_ptmotorcu_out';
ModSys       = 'Adapt MCU MotorOut1 from CM12 to CM13';
ModifiedPort = 4;
PortKind     = 'Inport';

subs_add = FindSubsFromSFun (sfunparam, ModSys, ModifiedPort, PortKind);
subs     = [subs, subs_add];


sfunparam    = 'cm_ptmotorcu_out';
ModSys       = 'Adapt MCU MotorOut2 from CM12 to CM13';
ModifiedPort = 5;
PortKind     = 'Inport';

subs_add = FindSubsFromSFun (sfunparam, ModSys, ModifiedPort, PortKind);
subs     = [subs, subs_add];


sfunparam    = 'cm_ptmotorcu_out';
ModSys       = 'Adapt MCU MotorOut3 from CM12 to CM13';
ModifiedPort = 6;
PortKind     = 'Inport';

subs_add = FindSubsFromSFun (sfunparam, ModSys, ModifiedPort, PortKind);
subs     = [subs, subs_add];


AddAndReconnect(subs);

clear subs;
