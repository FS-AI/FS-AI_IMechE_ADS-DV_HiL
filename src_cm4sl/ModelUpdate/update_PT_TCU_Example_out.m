% Update Trailer
subs = [];
opts = [];


sfunparam    = 'cm_pttransmcu_out';
ModSys       = 'ignored';
ModifiedPort = -1; % replace the S-Function itself
PortKind     = 'ignored';

subs_add = FindSubsFromSFun (sfunparam, ModSys, ModifiedPort, PortKind);
subs     = [subs, subs_add];

opts.OldPortNumsIn  = [1:6, -1, -1, -1, -1, -1, -1, -1,7:11, -1, -1, -1, -1, -1, -1, -1];
opts.OldPortNumsOut = [];
% opts.FontSizeLabel  = 2;
opts.AddTerms       = 1;

ReplaceAndReconnect(subs, opts);

clear opts subs;