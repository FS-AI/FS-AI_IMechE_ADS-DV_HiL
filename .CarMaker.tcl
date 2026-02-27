##
## .CarMaker.tcl 
##
## FSAI project startup script
## Loads the provided basic test run at startup.

Project::CheckProject

## If the following line is not present, and the Test Run 'FS_autonomous_Straight_001' is not available, a FATAL ERROR results...
LoadTestRun "FS_autonomous_Straight_001"

##::CMRosIF::ROS_Launch -mode launch
Application connect
##Application start
