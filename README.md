# Enterprise Network Simulation

**Enterprise Network Simulation** is a comprehensive network simulation project designed to model various network devices, simulate traffic, and test security features within a controlled virtual environment. This project allows users to design, test, and validate networking setups, security configurations, and attack scenarios, making it an ideal tool for network engineers, cybersecurity professionals, and anyone interested in networking concepts.

## Features

- **Network Device Simulation**: Simulate a variety of network devices including routers, switches, firewalls, servers, and more.
- **Traffic Simulation**: Generate and manage network traffic to test network performance, stress scenarios, and capacity.
- **Security Testing**: Implement and evaluate security measures like advanced firewalls, intrusion detection systems (IDS), and attack simulations.
- **VPN Support**: Simulate VPN functionalities, including tunneling, encryption, and remote access.
- **Custom Configurations**: Load custom configurations for network devices, firewalls, and Quality of Service (QoS) policies.
- **Attack Simulations**: Model and simulate real-world network attacks such as Smurf attacks and Man-in-the-Middle (MITM) attacks.
- **OS Simulation**: Simulate operating system environments on network devices with process management, file systems, and multi-threading.

## Getting Started

To get started with the simulation, follow the steps below to clone the repository, install dependencies, and build the project.

### Prerequisites

Make sure you have the following tools installed:
- **Visual Studio Community Edition 2022** (IDE)
- **C++ Compiler** (GCC, Clang, or equivalent)
- **CMake** (for building the project)
- **Google Test** (for unit testing)
- **spdlog** (for logging)

### Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/yourusername/Enterprise-Network-Simulation.git
   cd Enterprise-Network-Simulation
   ```

2. Install dependencies (if not already installed):

   For Ubuntu-based systems:
   ```bash
   sudo apt-get install cmake g++ libgtest-dev libspdlog-dev
   ```

3. Build the project:

   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

4. To run the simulation, use the following command:

   ```bash
   ./main
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
│   │   │   ├── qos_management.cpp    # Quality of Service simulation
│   │   │   └── vpn_encryption.cpp    # VPN encryption and tunneling logic
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
└── main.cpp                          # Entry point for running the network simulation
```

## Running the Simulation

To run the simulation, execute the following command:

```bash
./main
```

This will start the simulation and display logs based on your network configuration, devices, and security settings.

## Running Tests

To run unit tests, navigate to the `tests` directory and compile the test files using CMake or any suitable build system.

```bash
cd tests
g++ -std=c++11 -lgtest -pthread *.cpp -o test_runner
./test_runner
```

Alternatively, if you have CMake configured for testing:

```bash
cd build
cmake --build . --target tests
./tests
```

### Unit Tests

The project includes unit tests for various components of the simulation, such as:

- **Security Tests**: Tests for firewalls, VPN, intrusion detection systems, and attacks.
- **Network Tests**: Tests for devices like routers, switches, and packet handlers.
- **OS Simulation Tests**: Tests for file system management, process creation, and threading.
- **VPN Tests**: Tests for VPN tunneling, encryption, and decryption.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
