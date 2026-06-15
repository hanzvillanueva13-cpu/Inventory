//
// Created by Hanz on 06/15/26.
//

#include <filesystem>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>

#include "Color.h"
#include "Log.h"

std::filesystem::path audit_file = "audit.log";

void view_audit_logs() {
    std::cout << Color::CYAN << Color::BOLD << "[ Audit Log ]\n" << Color::RESET;

    // Check for file existence
    if (!std::filesystem::exists(audit_file)) {
        print_info("File not found. Starting a new log file.");
    }

    // Open the file
    std::ifstream f(audit_file, std::ios::in);

    if (!f.is_open()) {
        print_error("Unable to open the file.");
        return;
    }

    // Read the file line-by-line
    for (std::string line; std::getline(f, line);) {
        // Display each line
        std::cout << line << '\n';
    }

    // Show a completion message
    if
}

void save_audit_logs(std::string message) {
}
