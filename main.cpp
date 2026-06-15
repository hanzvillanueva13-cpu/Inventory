#include <iostream>
#include <string>

#include "Audit.h"
#include "Color.h"

/**
 * @brief Show a title screen to the console
 */
void title();

/**
 * @brief Show credits to the console
 */
void credits();

int main() {
    view_audit_logs();
    return 0;
}

// ========== Credits ==========

void title() {
    std::cout << '\n'
            << Color::CYAN << Color::BOLD
            << "┎──────────────────────────┒\n"
            << "┃    Inventory System <3   ┃\n"
            << "┖──────────────────────────┚\n"
            << Color::RESET;
}

void credits() {
    std::cout << '\n'
            << Color::CYAN << Color::BOLD
            << "Credits:\n"
            << "  - Hanz\n"
            << "  - Jay\n"
            << "  - Louis\n"
            << "  - Brix\n"
            << "  - Eli <3\n"
            << Color::RESET;
}
