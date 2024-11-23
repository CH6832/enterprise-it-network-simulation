#include <iostream>
#include <spdlog/spdlog.h>
#include <gtest/gtest.h> // Include Google Test header

// Include client and device headers
#include "src/clients/smartphone_client.hpp"
#include "src/clients/notebook_client.hpp"
#include "src/devices/web_server.hpp"
#include "src/devices/database_server.hpp"
#include "src/devices/mail_server.hpp"
#include "src/devices/vpn_server.hpp"

int main(int argc, char** argv) {
    // Initialize Google Test framework
    ::testing::InitGoogleTest(&argc, argv);

    // Log using spdlog
    spdlog::info("Starting the Enterprise IT Network Simulation...");

    // Run NotebookClient tests
    spdlog::info("Running NotebookClient tests...");
    int notebookTestResult = RUN_ALL_TESTS();  // Run all NotebookClient-related tests
    if (notebookTestResult == 0) {
        spdlog::info("NotebookClient tests completed successfully.");
    }
    else {
        spdlog::error("NotebookClient tests failed.");
    }

    // Run SmartphoneClient tests
    spdlog::info("Running SmartphoneClient tests...");
    int smartphoneTestResult = RUN_ALL_TESTS();  // Run all SmartphoneClient-related tests
    if (smartphoneTestResult == 0) {
        spdlog::info("SmartphoneClient tests completed successfully.");
    }
    else {
        spdlog::error("SmartphoneClient tests failed.");
    }

    // Run WebServer tests
    spdlog::info("Running WebServer tests...");
    int webServerTestResult = RUN_ALL_TESTS();  // Run all WebServer-related tests
    if (webServerTestResult == 0) {
        spdlog::info("WebServer tests completed successfully.");
    }
    else {
        spdlog::error("WebServer tests failed.");
    }

    // Run DatabaseServer tests
    spdlog::info("Running DatabaseServer tests...");
    int databaseServerTestResult = RUN_ALL_TESTS();  // Run all DatabaseServer-related tests
    if (databaseServerTestResult == 0) {
        spdlog::info("DatabaseServer tests completed successfully.");
    }
    else {
        spdlog::error("DatabaseServer tests failed.");
    }

    // Run MailServer tests
    spdlog::info("Running MailServer tests...");
    int mailServerTestResult = RUN_ALL_TESTS();  // Run all MailServer-related tests
    if (mailServerTestResult == 0) {
        spdlog::info("MailServer tests completed successfully.");
    }
    else {
        spdlog::error("MailServer tests failed.");
    }

    // Run VPNServer tests
    spdlog::info("Running VPNServer tests...");
    int vpnServerTestResult = RUN_ALL_TESTS();  // Run all VPNServer-related tests
    if (vpnServerTestResult == 0) {
        spdlog::info("VPNServer tests completed successfully.");
    }
    else {
        spdlog::error("VPNServer tests failed.");
    }

    // Log simulation completion
    spdlog::info("Simulation completed successfully.");

    return 0;
}
