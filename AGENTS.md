# AGENTS.md

## Project Context

This repository is an FS-AI ADS-DV hardware-in-the-loop CarMaker project. It is primarily maintained for the Windows version of IPG CarMaker Extended 14.1.1. The CarMaker C code is compiled through an MSYS environment and compiler, even though Linux-derived build and ROS files remain in the tree.

The project was derived from a Linux and ROS upstream project. Some Linux/ROS files are kept for backward compatibility with that upstream project and to make pulling upstream changes easier. Do not assume those files define the main supported workflow unless a task explicitly targets Linux or ROS.

The main engineering focus is debugging `CarMaker.win64.exe`. That executable is compiled from the C/C++ code in `src/`, so debugging work should usually start by inspecting `src/` sources, the `src/Makefile`, and the MSYS/CarMaker build output.

The project combines CarMaker project data, C/C++ application sources, generated vehicle/model code, ROS2 packages, CAN database files, and documentation. Be conservative with generated or simulator-owned files.

## Key Layout

- `src/`: CarMaker application sources, Visual Studio project files, and the main CarMaker `Makefile`.
  - `User.c`, `IO.c`, `CM_Main.c`, `CM_Vehicle.c`, `MyVehicleControl.c`: primary CarMaker application hooks and vehicle-control integration points.
  - `ExtraModels/`: CarMaker extra model sources.
  - `ZF_src/Vehicle_Model/`: vehicle model sources and headers; treat as generated/model-owned unless the task explicitly targets them.
  - `RBS_0/`: generated CAN/RBS-related C sources.
  - `_clang-format`: IPG C/C++ formatting style for this tree.
- `src_cm4sl/`: CarMaker for Simulink build files.
- `ros/ros2_ws/`: ROS2 workspace using `colcon`.
  - `hellocm`, `hellocm_cmnode`, `cmrosutils`, `carmaker_rsds_client`: CarMaker ROS interface nodes/utilities.
  - `vehiclecontrol_msgs`, `camera_msgs`, `hellocm_msgs`: ROS message/service packages.
- `CANdb/`: CAN database files.
- `Data/`, `GUI/`, `Movie/`, `MovieNX/`, `Plugins/`, `InstrumentDesignerFiles/`: CarMaker project assets and configuration.
- `doc/`: user guide, generated API docs, images, and tutorials.

## Environment Assumptions

- Windows CarMaker build files reference `C:/IPG/carmaker/win64-14.1.1`.
- The primary development/build environment is Windows with MSYS tooling for compiling the CarMaker code.
- Linux ROS2 docs assume Ubuntu 22.04, ROS2 Humble, `colcon`, and CarMaker 14.1.1.
- Treat Linux and ROS workflows as inherited compatibility/upstream-sync paths unless the task says otherwise.
- Large optional Dynamic Driving Area assets can be fetched with `fetch_assets.ps1`; do not assume they are present.
- Build products and simulator outputs may already exist in the tree. Avoid deleting or regenerating them unless needed for the task.

## Common Commands

- Build the CarMaker app with the top-level helper, defaulting to ROS2 and `src`:
  ```bash
  ./build.sh
  ```
- Build the ROS2 workspace directly:
  ```bash
  cd ros/ros2_ws
  ./build.sh
  ```
- Source the ROS workspace environment from the repo root:
  ```bash
  source ros_setup.bash 2
  ```
- Start CarMaker from the repo root after the ROS workspace is built:
  ```bash
  ./CMStart.sh
  ```
- Build the CarMaker app directly from `src` when the CarMaker make environment is available:
  ```bash
  make -C src
  ```
- Run a verbose CarMaker make build when diagnosing compiler/linker issues:
  ```bash
  make -C src V=1
  ```

## Coding Guidelines

- Follow existing CarMaker/IPG C style. For C/C++ changes under `src/`, use `src/_clang-format` where practical.
- Keep generated/model-owned sources stable unless the task is specifically about generated output, model integration, or CAN/RBS regeneration.
- Prefer small, localized changes in CarMaker hooks and ROS node/package code over broad refactors.
- Preserve CarMaker plugin marker blocks such as `@@PLUGIN-BEGIN-*@@` / `@@PLUGIN-END@@`; they are simulator-managed.
- Do not commit or add generated build artifacts, simulator output, logs, or large environment files. `.gitignore` already excludes common examples such as `ros/ros2_ws/build/`, `ros/ros2_ws/install/`, `ros/ros2_ws/log/`, `SimOutput/`, `Movie/.road_cache/`, `src/*.o`, and `MovieNX/data_FS_AI_Circuit`.

## Verification

- There is no obvious standalone automated test suite in the repo. Verification is usually build-based and simulator-based.
- For ROS2 package changes, use `colcon build` from `ros/ros2_ws` or the workspace `build.sh`.
- For CarMaker C changes, rebuild `CarMaker.win64.exe` from `src/` with the MSYS/CarMaker make environment. Use `make -C src` or the Visual Studio solution under `src/`, depending on the target platform and task.
- For simulation behavior, follow `doc/FSAI_UsersGuide.md` and run the relevant CarMaker TestRun from the GUI.
