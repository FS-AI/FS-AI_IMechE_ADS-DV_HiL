subs = []; % used to store componets that will be replaced/reconnected
opts = [];

sys = 'DrivMan';
ModifiedPort = 1;
PortKind = 'Inport';
blck = 'DrivMan.Out';
ModSys = 'BusCreator';

subs_add = FindSubsFromParentSys(blck, sys, ModSys, ModifiedPort,PortKind);
subs     = [subs, subs_add];

opts.OldPortNumsIn  = [1:8, -ones(1, 3), 9:17]; % Numbers of old ports on new block
opts.OldPortNumsOut = [1];
% opts.FontSizeLabel  = 2;
opts.AddTerms       = 1;

ReplaceAndReconnect(subs, opts);

clear opts subs;
