@echo off
echo Starting Network Attack Simulator...

REM Change directory to where the compiled executable is located
cd ./bin || (echo Directory not found! & exit /b)

REM Check if the attack simulator executable exists before attempting to run it
if exist attack_simulator.exe (
    echo Starting attack simulator...
    start "" attack_simulator.exe
    echo All attacks simulated successfully!
) else (
    echo Error: attack_simulator.exe not found in the ./bin directory!
)

pause
