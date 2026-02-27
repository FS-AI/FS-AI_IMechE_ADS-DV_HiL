function [] = update_HydBrakeCtrlOutIF_Demux(trg_mdl)
subs = []; % used to store componets that will be replaced/reconnected
opts = [];

sys = 'CreateBus HydBrakeCU';
ModifiedPort = 1;
PortKind = 'Outport';
blck = 'In';
ModSys = 'Demux';

Parent_src = 'generic_src/CarMaker/IPG Vehicle/Brake/HydBrakeCU Example';
Parent_trg = append(trg_mdl,'/CarMaker/IPG Vehicle/Brake/HydBrakeCU Example');

subs_add = FindSubsFromParentSys_wPath(blck, sys, ModSys, ModifiedPort, PortKind, Parent_src, Parent_trg);
subs     = [subs, subs_add];

opts.OldPortNumsIn  = [1]; % Numbers of old ports on new block
opts.OldPortNumsOut = [1:28, -ones(1,12)];
% opts.FontSizeLabel  = 2;
opts.AddTerms       = 1;

ReplaceAndReconnect(subs, opts);

clear opts subs;
