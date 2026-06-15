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
        return; // Exit cleanly
    }

    // Open the file
    std::ifstream f(audit_file, std::ios::in);

    if (!f.is_open()) {
        print_error("Unable to open the file.");
        return; // Exit cleanly
    }

    // Read the file line-by-line
    for (std::string line; std::getline(f, line);) {
        // Display each line
        std::cout << line << '\n';
    }

    // Close the file stream
    f.close();
}

void save_audit(const std::string &message) {
    // Create and open file - Append to last line
    std::ofstream f(audit_file, std::ios::app);

    if (!f.is_open()) {
        print_error("Unable to open the file.");
        return; // Exit cleanly
    }

    // Append the message to the file
    f << message << '\n';

    // Close the file stream
    f.close();
}
