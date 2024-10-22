#!/bin/bash

echo "Initializing Network Simulation..."

# Change directory to where the compiled executable is located
cd ./bin || {
    echo "Error: Directory './bin' not found!"
    exit 1
}

# Check if the simulation executable exists before attempting to run it
if [[ -f "netlab_simulation" ]]; then
    echo "Starting Network Simulation..."
    ./netlab_simulation &
    echo "Network Simulation started successfully!"
else
    echo "Error: 'netlab_simulation' executable not found in the './bin' directory!"
    exit 1
fi

# Optionally, you can wait for background processes to finish
# wait
