% Update Trailer
subs = [];
opts = [];


sfunparam    = 'cm_ptcontrol_in';
ModSys       = 'ignored';
ModifiedPort = -1; % replace the S-Function itself
PortKind     = 'ignored';

subs_add = FindSubsFromSFun (sfunparam, ModSys, ModifiedPort, PortKind);
subs     = [subs, subs_add];

opts.OldPortNumsIn  = [1];
opts.OldPortNumsOut = [1:11, -1, -1, -1, -1, -1, -1, -1, 12:20, -1, -1, -1, -1, -1, -1, -1, -1, 21:25, -1, -1, -1, -1, -1, -1, -1, 26:30, -1, -1, -1, -1, -1, -1, -1, 31:35];
% opts.FontSizeLabel  = 2;
opts.AddTerms       = 1;

ReplaceAndReconnect(subs, opts);

clear opts subs;