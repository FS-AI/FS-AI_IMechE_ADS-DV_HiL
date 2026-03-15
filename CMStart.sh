# !/bin/bash

# Processes called inside CM GUI will inherit environment variables!
# - Ensure ros workspace is already built!
source ros_setup.bash ${1:-2}

CM_Office-14.1.1 . -apphost localhost -ext GUI/CMExt-CMRosIF.mod -debuggpu
