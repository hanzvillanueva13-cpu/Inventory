//
// Created by Hanz on 06/15/26.
//

// ========== Helper Methods: String Manipulation ==========

void trim(std::string &s) {
    const std::string whitespaces = " \t\r\n";
    const auto start = s.find_first_not_of(whitespaces);
    s.erase(0, start);

    const auto end = s.find_last_not_of(whitespaces);
    s.erase(end - 1);
}

// ========== Helper Methods: Get User Input ==========

int get_int(const std::string &prompt) {
    int input;
    while (true) {
        std::cout << prompt;

        if (!(std::cin >> input)) {
            // Throw on unrecoverable errors
            if (std::cin.eof()) {
                throw std::runtime_error("Input interrupted.");
            }

            if (std::cin.bad()) {
                throw std::runtime_error("Stream failed.");
            }

            // Clean up on recoverable errors like
            // Invalid data type (e.g., abc, ab3)
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            print_error("Invalid input. Try again.");
            continue;
        }

        // Return the valid result to the user
        return input;
    }
}

int get_uint(const std::string &prompt) {
    int input;
    while (true) {
        std::cout << prompt;

        if (!(std::cin >> input)) {
            // Throw on unrecoverable errors
            if (std::cin.eof()) {
                throw std::runtime_error("Input interrupted.");
            }

            if (std::cin.bad()) {
                throw std::runtime_error("Stream failed.");
            }

            // Clean up on recoverable errors like
            // Invalid data type (e.g., abc, ab3)
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            print_error("Invalid input. Must be a positive number. Try again.");
            continue;
        }

        // Make sure the value is positive
        if (input < 0) {
            print_error("Invalid input. Must be a positive number. Try again.");
            continue;
        }

        // Return the valid result to the user
        return input;
    }
}

char get_char(const std::string &prompt) {
    char input;
    while (true) {
        std::cout << prompt;

        if (!(std::cin >> input)) {
            // Throw on unrecoverable errors
            if (std::cin.eof()) {
                throw std::runtime_error("Input interrupted.");
            }

            if (std::cin.bad()) {
                throw std::runtime_error("Stream failed.");
            }

            // Clean up on recoverable errors like
            // Invalid data type (e.g., abc, ab3)
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            print_error("Invalid input. Must be a single char. Try again.");
            continue;
        }

        // Make sure the value is positive
        if (input < 0) {
            print_error("Invalid input. Must be a single char. Try again.");
            continue;
        }

        // Return the valid result to the user
        return input;
    }
}

std::string get_string(const std::string &prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;

        if (!(std::getline(std::cin, input))) {
            // Throw on unrecoverable errors
            if (std::cin.eof()) {
                throw std::runtime_error("Input interrupted.");
            }

            if (std::cin.bad()) {
                throw std::runtime_error("Stream failed.");
            }

            // Clean up on recoverable errors like
            // To be honest I don't know what kind of error is this for
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            print_error("Invalid input. Must be a valid string. Try again.");
            continue;
        }

        // Trim the string of whitespaces
        trim(input);

        // Check if empty
        if (input.empty()) {
            print_error("Invalid input. Must NOT be empty. Try again.");
            continue;
        }

        // Return the valid result to the user
        return input;
    }
}
