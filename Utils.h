//
// Created by Hanz on 06/15/26.
//

#ifndef INVENTORY_UTIL_H
#define INVENTORY_UTIL_H

#include <string>

/**
 * @brief Remove trailing and leading whitespaces
 * @param s The string to change
 */
void trim(std::string &s);

// ===== Helper Method In Getting User Input =====

/**
 * @brief Helper function get a signed integer from the user
 *
 * @param prompt The prompt to show to the user
 * @return The integer user input
 */
int get_int(const std::string &prompt);

/**
 * @brief Helper function get a positive integer from the user
 *
 * @param prompt The prompt to show to the user
 * @return The integer user input
 */
int get_uint(const std::string &prompt);

/**
 * @brief Helper function get a char from the user
 *
 * @param prompt The prompt to show to the user
 * @return The char user input
 */
char get_char(const std::string &prompt);

/**
 * @brief Helper function to get string from the user.
 *        Keep trying while empty or invalid.
 *
 * @param prompt The prompt to show to the user
 * @return The string user input
 */
std::string get_string(const std::string &prompt);

/**
 * @brief Helper function to get string from the user or skip
 *
 * @param prompt The prompt to show to the user
 * @param current_value The current value to use when skipping
 * @return The string user input
 */
std::string get_string_or_skip(const std::string &prompt, const std::string &current_value);

#endif //INVENTORY_UTIL_H
