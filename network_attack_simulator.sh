#!/bin/bash

echo "Starting Network Attack Simulator..."

# Change directory to where the compiled executable is located
cd ./bin || { echo "Error: Directory './bin' not found!"; exit 1; }

# Check if the attack simulator executable exists before attempting to run it
if [[ -x ./attack_simulator ]]; then
    echo "Starting attack simulator..."
    ./attack_simulator &

    # Wait for the simulator to complete
    wait
    echo "All attacks simulated successfully!"
else
    echo "Error: 'attack_simulator' not found or not executable in the './bin' directory!"
    exit 1
fi
