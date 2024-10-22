@echo off
echo Stopping Network Simulation...

REM Change directory to where the compiled executable is located
cd ./bin
IF ERRORLEVEL 1 (
    echo Error: Directory './bin' not found!
    pause
    exit /B
)

REM Check if the simulation executable is running
tasklist /FI "IMAGENAME eq netlab_simulation.exe" | find /I "netlab_simulation.exe" >nul
IF %ERRORLEVEL% EQU 0 (
    REM Use taskkill to stop the simulation
    taskkill /IM netlab_simulation.exe /F
    echo Network Simulation stopped successfully!
) ELSE (
    echo Warning: Network Simulation is not running.
)

pause
