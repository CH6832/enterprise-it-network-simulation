#!/bin/bash

echo "Stopping Network Simulation..."

# Change directory to where the compiled executable is located
cd ./bin || { echo "Error: Directory './bin' not found!"; exit 1; }

# Check if the simulation is running and use pkill to stop it
if pgrep -f netlab_simulation > /dev/null; then
    pkill -f netlab_simulation
    echo "Network Simulation stopped successfully!"
else
    echo "Warning: Network Simulation is not running."
fi
