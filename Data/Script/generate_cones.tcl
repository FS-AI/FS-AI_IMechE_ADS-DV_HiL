proc addLargeOrangeCone {fileID n id s t} {
	# Add large organe cone to the opened infofile with handle fileID
	# The cone is added as a traffic object number $n
	# The cone is added to the main route at offset ($s %t)
	puts $fileID "Traffic.$n.Name = CN$n"
	puts $fileID "Traffic.$n.DetectMask = 1 1"
	puts $fileID "Traffic.$n.UpdRate = 200"
	puts $fileID "Traffic.$n.AutoDrv.UpdRate = 200"
	puts $fileID "Traffic.$n.Lighting = 0"
	puts $fileID "Traffic.$n.FreeMotion = 0"
	puts $fileID "Traffic.$n.TrailerName = "
	puts $fileID "Traffic.$n.Template.FName = TrafficCone_Large_Orange"
	puts $fileID "Traffic.$n.AutoDriver.FName = "
	puts $fileID "Traffic.$n.Routing.Type = Route"
	puts $fileID "Traffic.$n.Routing.ObjId = $id"
	puts $fileID "Traffic.$n.StartPos.Type = Route"
	puts $fileID "Traffic.$n.StartPos.ObjId = $id"
	puts $fileID "Traffic.$n.StartPos = $s $t"
	puts $fileID "Traffic.$n.StartPos.Orientation.Type = Relative"
	puts $fileID "Traffic.$n.StartPos.Orientation = 0.0 0.0 0.0"
	puts $fileID "Traffic.$n.nMan = 0"
	puts $fileID "Traffic.$n.Man.Start.Velocity = 0.0"
	puts $fileID "Traffic.$n.Man.TreatAtEnd = FreezePos"
}

proc addOrangeCone {fileID n id s t} {
	# Add small organe cone to the opened infofile with handle fileID
	# The cone is added as a traffic object number $n
	# The cone is added to the main route at offset ($s %t)
    puts $fileID "Traffic.$n.Name = CN$n"
	puts $fileID "Traffic.$n.DetectMask = 1 1"
	puts $fileID "Traffic.$n.UpdRate = 200"
	puts $fileID "Traffic.$n.AutoDrv.UpdRate = 200"
	puts $fileID "Traffic.$n.Lighting = 0"
	puts $fileID "Traffic.$n.FreeMotion = 0"
	puts $fileID "Traffic.$n.TrailerName = "
	puts $fileID "Traffic.$n.Template.FName = TrafficCone_Small_Orange"
	puts $fileID "Traffic.$n.AutoDriver.FName = "
	puts $fileID "Traffic.$n.Routing.Type = Route"
	puts $fileID "Traffic.$n.Routing.ObjId = $id"
	puts $fileID "Traffic.$n.StartPos.Type = Route"
	puts $fileID "Traffic.$n.StartPos.ObjId = $id"
	puts $fileID "Traffic.$n.StartPos = $s $t"
	puts $fileID "Traffic.$n.StartPos.Orientation.Type = Relative"
	puts $fileID "Traffic.$n.StartPos.Orientation = 0.0 0.0 0.0"
	puts $fileID "Traffic.$n.nMan = 0"
	puts $fileID "Traffic.$n.Man.Start.Velocity = 0.0"
	puts $fileID "Traffic.$n.Man.TreatAtEnd = FreezePos"
}

proc addBlueCone {fileID n id s t} {
	# Add small blue cone to the opened infofile with handle fileID
	# The cone is added as a traffic object number $n
	# The cone is added to the main route at offset ($s %t)
	puts $fileID "Traffic.$n.Name = CN$n"
	puts $fileID "Traffic.$n.DetectMask = 1 1"
	puts $fileID "Traffic.$n.UpdRate = 200"
	puts $fileID "Traffic.$n.AutoDrv.UpdRate = 200"
	puts $fileID "Traffic.$n.Lighting = 0"
	puts $fileID "Traffic.$n.FreeMotion = 0"
	puts $fileID "Traffic.$n.TrailerName = "
	puts $fileID "Traffic.$n.Template.FName = TrafficCone_Small_Blue"
	puts $fileID "Traffic.$n.AutoDriver.FName = "
	puts $fileID "Traffic.$n.Routing.Type = Route"
	puts $fileID "Traffic.$n.Routing.ObjId = $id"
	puts $fileID "Traffic.$n.StartPos.Type = Route"
	puts $fileID "Traffic.$n.StartPos.ObjId = $id"
	puts $fileID "Traffic.$n.StartPos = $s $t"
	puts $fileID "Traffic.$n.StartPos.Orientation.Type = Relative"
	puts $fileID "Traffic.$n.StartPos.Orientation = 0.0 0.0 0.0"
	puts $fileID "Traffic.$n.nMan = 0"
	puts $fileID "Traffic.$n.Man.Start.Velocity = 0.0"
	puts $fileID "Traffic.$n.Man.TreatAtEnd = FreezePos"
}

proc addYellowCone {fileID n id s t} {
	# Add small yellow cone to the opened infofile with handle fileID
	# The cone is added as a traffic object number $n
	# The cone is added to the main route at offset ($s %t)
    puts $fileID "Traffic.$n.Name = CN$n"
	puts $fileID "Traffic.$n.DetectMask = 1 1"
	puts $fileID "Traffic.$n.UpdRate = 200"
	puts $fileID "Traffic.$n.AutoDrv.UpdRate = 200"
	puts $fileID "Traffic.$n.Lighting = 0"
	puts $fileID "Traffic.$n.FreeMotion = 0"
	puts $fileID "Traffic.$n.TrailerName = "
	puts $fileID "Traffic.$n.Template.FName = TrafficCone_Small_Yellow"
	puts $fileID "Traffic.$n.AutoDriver.FName = "
	puts $fileID "Traffic.$n.Routing.Type = Route"
	puts $fileID "Traffic.$n.Routing.ObjId = $id"
	puts $fileID "Traffic.$n.StartPos.Type = Route"
	puts $fileID "Traffic.$n.StartPos.ObjId = $id"
	puts $fileID "Traffic.$n.StartPos = $s $t"
	puts $fileID "Traffic.$n.StartPos.Orientation.Type = Relative"
	puts $fileID "Traffic.$n.StartPos.Orientation = 0.0 0.0 0.0"
	puts $fileID "Traffic.$n.nMan = 0"
	puts $fileID "Traffic.$n.Man.Start.Velocity = 0.0"
	puts $fileID "Traffic.$n.Man.TreatAtEnd = FreezePos"
}


proc cleanUp {fileName} {
	# Programtically remove all traffic objects from the TestRun infofile
	
	# Read all lines from the infofile
	set fileID [open Data/TestRun/$fileName r]
	set fc [read $fileID]
	
	# Seek all Traffic.NUM lines and delete them
	regsub -all -line {Traffic\.\d.+\n} $fc {} fc
	
	# Re-open file and clear its contents
	set fileID [open Data/TestRun/$fileName w]
	
	# Re-insert the old TestRun minus all the traffic data
	puts -nonewline $fileID $fc
	close $fileID
}

# Get the relative name of the current TestRun
set fileName [SimInfo testrun]
set fileNameBak Data/TestRun/
append fileNameBak $fileName _bak
file copy -force Data/TestRun/$fileName $fileNameBak

# Clean ALL traffic objects from the TestRun
cleanUp $fileName

# Get the route length+ID and set the number of cones accordingly
set routeLen [IFileValue Road Route.0.Length]
set routeID [IFileValue Road Route.0.ID]
set coneDist 5
set nCones [expr "int($routeLen/$coneDist)"]

# Write the number of cones to the TestRun infofile
IFileModify TestRun Traffic.N [expr "2*$nCones+4"]

# Open TestRun infofile and get a handle to it
set fileID [open Data/TestRun/$fileName a]

# Add 2x2 large orange cones at the start
addLargeOrangeCone $fileID 0 $routeID 0 1.5
addLargeOrangeCone $fileID 1 $routeID 0 -1.5
addLargeOrangeCone $fileID 2 $routeID 0.5 1.5
addLargeOrangeCone $fileID 3 $routeID 0.5 -1.5

# Add blue/yellow cones on the left/right side of the track
for {set i 0} {$i < $nCones} {incr i} {
    addBlueCone $fileID [expr "2*$i+4"] $routeID [expr "5*$i+5"] 1.5
	addYellowCone $fileID [expr "2*$i+5"] $routeID [expr "5*$i+5"] -1.5
}

# Close and flush the IFile to apply changes
close $fileID
IFileFlush
