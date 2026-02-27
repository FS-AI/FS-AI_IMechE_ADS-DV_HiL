subs = []; % used to store componets that will be replaced/reconnected
opts = [];

sys = 'CreateBus HydBrakeCU_Cfg';
ModifiedPort = 1;
PortKind = 'Outport';
blck = 'In';
ModSys = 'Demux';

subs_add = FindSubsFromParentSys(blck, sys, ModSys, ModifiedPort,PortKind);
subs     = [subs, subs_add];

opts.OldPortNumsIn  = [1]; % Numbers of old ports on new block
opts.OldPortNumsOut = [1:3, -1];
% opts.FontSizeLabel  = 2;
opts.AddTerms       = 1;

ReplaceAndReconnect(subs, opts);

clear opts subs;
