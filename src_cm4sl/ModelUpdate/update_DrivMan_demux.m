subs = []; % used to store componets that will be replaced/reconnected
opts = [];


sfunparam    = 'DrivMan';
ModSys       = 'Demux';
ModifiedPort = 2; % [FL SpringFrc, ...]
PortKind     = 'Outport';

subs_add = FindSubsFromSFun (sfunparam, ModSys, ModifiedPort, PortKind);
subs     = [subs, subs_add];

opts.OldPortNumsIn  = [1]; % Numbers of old ports on new block
opts.OldPortNumsOut = [1:8, -ones(1,3), 9:17];
opts.FontSizeLabel  = 2;
opts.AddTerms       = 1;

ReplaceAndReconnect(subs, opts);

clear opts subs;
