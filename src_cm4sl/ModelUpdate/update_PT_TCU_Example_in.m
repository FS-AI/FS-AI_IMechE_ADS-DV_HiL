subs = [];
opts = [];


sfunparam    = 'cm_pttransmcu_in';
ModSys       = 'ignored';
ModifiedPort = -1; % replace the S-Function itself
PortKind     = 'ignored';

subs_add = FindSubsFromSFun (sfunparam, ModSys, ModifiedPort, PortKind);
subs     = [subs, subs_add];

opts.OldPortNumsIn  = [1];
opts.OldPortNumsOut = [1:6, -1, -1, -1, -1, -1, -1, -1, 7:12, -1, -1, -1, -1, -1, -1, -1, 13:17, -1, -1, -1, -1, -1, -1, -1, 18, 20:23, -1, -1, -1, -1, -1, -1, -1, 19, 24:27, -1, -1, -1, -1, -1, -1, -1,];
% opts.FontSizeLabel  = 2;
opts.AddTerms       = 1;

ReplaceAndReconnect(subs, opts);

clear opts subs;