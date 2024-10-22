# Enterprise Network Simulation

Enterprise Network Simulation is a network simulation project designed to model various network devices and security features. This project allows users to create virtual networks, simulate traffic, and test security measures in a controlled environment.

## Features

- **Network Device Simulation**: Simulate various devices such as routers, switches, firewalls, and servers.
- **Traffic Simulation**: Generate and manage network traffic for testing.
- **Security Testing**: Implement and evaluate security measures, including firewalls and intrusion detection systems.
- **VPN Support**: Simulate VPN functionalities including tunneling and encryption.
- **Custom Configurations**: Load configurations for networks, firewalls, and QoS policies.
- **Attack Simulations**: Model various network attacks such as Smurf attacks and Man-in-the-Middle (MITM) attacks.

## Getting Started

To get started, clone this repository and build the project:

```bash
git clone https://github.com/yourusername/Enterprise-Network-Simulation.git
cd Enterprise-Network-Simulation
# Build instructions
```

### Project Structure

```plaintext
.
├── docs/                             # Documentation for the project
│   ├── architecture_diagrams/        # Network topology and system architecture diagrams
│   ├── usage_guide.md                # Guide for users on how to run and configure the simulation
│   ├── api_reference.md              # API Reference for the simulation
│   └── changelog.md                  # Project change log
│
├── src/                              # Core source code for the simulation
│   ├── clients/                      # VPN clients and remote devices
│   │   ├── notebook_client.cpp        # Simulated notebook VPN client
│   │   ├── smartphone_client.cpp      # Simulated smartphone VPN client
│   │   └── client_base.hpp           # Base class for all clients
│   │
│   ├── devices/                      # Simulated network devices
│   │   ├── computer_device.cpp        # Simulated computer
│   │   ├── printer_device.cpp         # Simulated printer
│   │   ├── router_device.cpp          # Simulated router with dynamic routing (e.g., OSPF, RIP)
│   │   ├── firewall_device.cpp        # Simulated firewall with advanced packet filtering
│   │   ├── file_server.cpp            # File server implementation
│   │   ├── web_server.cpp             # Web server for static website hosting
│   │   ├── database_server.cpp        # Simulated database server
│   │   ├── mail_server.cpp            # Secure mail server implementation
│   │   └── vpn_server.cpp             # VPN server implementation
│   │
│   ├── security/                     # Security implementations
│   │   ├── firewall/                 # Firewall rules, packet filtering, IDS/IPS
│   │   │   ├── layer2_filter.cpp     # OSI Layer 2 filtering
│   │   │   ├── tcp_udp_limits.cpp    # Limit TCP/UDP access
│   │   │   ├── qos_management.cpp     # Quality of Service simulation
│   │   │   └── vpn_encryption.cpp     # VPN encryption and tunneling logic
│   │   ├── ids.cpp                   # Intrusion Detection System (IDS)
│   │   ├── threat_detection.cpp      # Threat detection and anomaly monitoring
│   │   ├── encryption.cpp            # Encryption algorithms (latest technologies)
│   │   ├── smurf_attack.cpp          # Simulated Smurf attack
│   │   └── mitm_attack.cpp           # Man-in-the-Middle (MITM) attack simulation
│   │
│   ├── network/                      # Networking components and configurations
│   │   ├── routing/                  # Routing algorithms (e.g., RIP, OSPF)
│   │   │   ├── rip_routing.cpp       # RIP implementation
│   │   │   └── ospf_routing.cpp      # OSPF implementation
│   │   ├── packets/                  # Simulated network packets and protocols
│   │   │   ├── tcp_packet.cpp        # TCP packet simulation
│   │   │   ├── udp_packet.cpp        # UDP packet simulation
│   │   │   └── packet_handler.cpp    # Packet handler and parser
│   │   ├── switch_device.cpp         # Simulated network switch
│   │   └── vpn_tunnel.cpp            # VPN tunneling logic (encryption/decryption)
│   │
│   └── os_simulation/                # Operating System simulation on network devices
│       ├── process_management.cpp    # Simulate process management (creation, termination)
│       ├── file_system.cpp           # Simple file system implementation
│       ├── threading.cpp             # Multi-threading simulation for processes
│       └── command_line_interface.cpp # Command-line interface for OS interaction
│
├── config/                           # Configuration files
│   ├── network_config.json           # Network topology configuration (IP addresses, subnets, devices)
│   ├── firewall_rules.json           # Custom firewall rules and security policies
│   ├── vpn_config.json               # VPN configuration for site-to-site and remote access VPN
│   └── qos_config.json               # Quality of Service (QoS) configuration file
│
├── tests/                            # Unit and integration tests
│   ├── security_tests.cpp            # Tests for security features (firewall, VPN, IDS)
│   ├── network_tests.cpp             # Tests for network devices (routers, switches, packets)
│   ├── os_tests.cpp                  # Tests for the OS simulation (file system, processes)
│   ├── vpn_tests.cpp                 # Tests for VPN encryption, authentication, and tunneling
│   └── integration_tests/            # End-to-end simulation tests
│
├── scripts/                          # Utility scripts
│   ├── start_simulation.sh           # Bash script to start the simulation
│   ├── stop_simulation.sh            # Bash script to stop the simulation
│   └── network_attack_simulator.sh   # Script to simulate attacks (e.g., Smurf, MITM)
│
├── logs/                             # Log files for network events, attacks, VPN connections
│   ├── firewall.log                  # Log of firewall actions and blocked traffic
│   ├── vpn_connections.log           # Log of VPN connection attempts and encryption status
│   └── attack_detection.log          # Log of detected network attacks
│
├── README.md                         # General project overview and instructions
├── LICENSE                           # License file for the project
├── CONTRIBUTING.md                   # Guidelines for contributing to the project
└── .gitignore                        # Files and directories to ignore in Git
```

## Running the Simulation

To run the simulation, use the following command:

```bash
./start_simulation.sh
```

To stop the simulation, execute:

```bash
./stop_simulation.sh
```

## Testing

To run the tests, navigate to the `tests` directory and use your preferred testing framework to execute the test files.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
