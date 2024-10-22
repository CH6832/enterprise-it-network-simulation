@echo off
echo Initializing Network Simulation...

REM Change directory to where the compiled executable is located
cd ./bin || (
    echo Error: Directory './bin' not found!
    exit /b 1
)

REM Check if the simulation executable exists before attempting to run it
if exist netlab_simulation.exe (
    echo Starting Network Simulation...
    start netlab_simulation.exe
    echo Network Simulation started successfully!
) else (
    echo Error: 'netlab_simulation.exe' not found in the './bin' directory!
    exit /b 1
)

pause
