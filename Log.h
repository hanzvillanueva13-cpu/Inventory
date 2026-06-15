//
// Created by Hanz on 06/15/26.
//

#ifndef INVENTORY_LOG_H
#define INVENTORY_LOG_H

#include <string>

void print_message(const std::string &message);

/**
 * @brief Print a success message to console
 * @param message The message to show
 */
void print_success(const std::string &message);

/**
 * @brief Print an information message to console
 * @param message The message to show
 */
void print_info(const std::string &message);

/**
 * @brief Print a warning message to console
 * @param message The message to show
 */
void print_warning(const std::string &message);

/**
 * @brief Print an error message to console
 * @param message The message to show
 */
void print_error(const std::string &message);

#endif //INVENTORY_LOG_H
