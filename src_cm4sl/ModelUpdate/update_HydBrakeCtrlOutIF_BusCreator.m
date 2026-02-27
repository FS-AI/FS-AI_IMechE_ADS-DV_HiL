function [] = update_HydBrakeCtrlOutIF_BusCreator(trg_mdl)
subs = []; % used to store componets that will be replaced/reconnected
opts = [];

sys = 'CreateBus HydBrakeCU';
ModifiedPort = 1;
PortKind = 'Inport';
blck = 'Out';
ModSys = 'BusCreator';

Parent_src = 'generic_src/CarMaker/IPG Vehicle/Brake/HydBrakeCU Example';
Parent_trg = append(trg_mdl,'/CarMaker/IPG Vehicle/Brake/HydBrakeCU Example');

subs_add = FindSubsFromParentSys_wPath(blck, sys, ModSys, ModifiedPort, PortKind, Parent_src, Parent_trg);
subs     = [subs, subs_add];

opts.OldPortNumsIn  = [1:28, -ones(1,12)]; % Numbers of old ports on new block
opts.OldPortNumsOut = [1];
% opts.FontSizeLabel  = 2;
opts.AddTerms       = 1;

ReplaceAndReconnect(subs, opts);

clear opts subs;
