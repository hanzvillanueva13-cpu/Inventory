//
// Created by Hanz on 06/15/26.
//

#include <iostream>
#include <string>

#include "Color.h"

void print_message(const std::string &message) {
    std::cout << Color::GREEN << "[ MESSAGE ] " << message << '\n' << Color::RESET;
}

void print_success(const std::string &message) {
    std::cout << Color::GREEN << "[ SUCCESS ] " << message << '\n' << Color::RESET;
}

void print_info(const std::string &message) {
    std::cout << Color::CYAN << "[ INFO ] " << message << '\n' << Color::RESET;
}

void print_warning(const std::string &message) {
    std::cout << Color::YELLOW << "[ WARNING ] " << message << '\n' << Color::RESET;
}

void print_error(const std::string &message) {
    std::cout << Color::RED << "[ ERROR ] " << message << '\n' << Color::RESET;
}