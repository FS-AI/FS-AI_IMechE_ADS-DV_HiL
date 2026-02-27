% Update Trailer
subs = [];
opts = [];


sfunparam    = 'cm_ptcontrol_out';
ModSys       = 'ignored';
ModifiedPort = -1; % replace the S-Function itself
PortKind     = 'ignored';

subs_add = FindSubsFromSFun (sfunparam, ModSys, ModifiedPort, PortKind);
subs     = [subs, subs_add];

opts.OldPortNumsIn  = [1:7, -1,-1,-1,-1,-1,-1,-1,-1, 8:12, -1, -1, -1, -1, -1, -1, -1, 13:17, -1, -1, -1, -1, -1, -1, -1, 18:21];
opts.OldPortNumsOut = [];
% opts.FontSizeLabel  = 2;
opts.AddTerms       = 1;

ReplaceAndReconnect(subs, opts);

clear opts subs;