//
// Created by Hanz on 06/15/26.
//

#ifndef INVENTORY_COLOR_H
#define INVENTORY_COLOR_H

#include <string>

namespace Color {
    // Foreground colors
    const std::string RED = "\033[31m";
    const std::string GREEN = "\033[32m";
    const std::string YELLOW = "\033[33m";
    const std::string BLUE = "\033[34m";
    const std::string MAGENTA = "\033[35m";
    const std::string CYAN = "\033[36m";

    // Reset to default terminal color
    const std::string RESET = "\033[0m";
    const std::string BOLD = "\033[1m";
}

#endif //INVENTORY_COLOR_H
