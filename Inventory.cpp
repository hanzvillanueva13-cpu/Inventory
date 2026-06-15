//
// Created by Hanz on 06/15/26.
//

#include "Inventory.h"

#include <format>
#include <iostream>

#include "Audit.h"
#include "Color.h"
#include "Log.h"
#include "Utils.h"

int generate_id(Inventory& inventory) {
    return inventory.next_id++;
}

// ========== Menu Options: Item ==========

void add_item(Inventory &inventory) {
    std::cout << Color::CYAN << Color::BOLD << "[ Add Item ]\n" << Color::RESET;

    // Ask what kind of item the user want to create
    std::cout << '\n'
            << Color::CYAN
            << "What kind of item do you want to create?\n"
            << "[1] Food\n"
            << "[2] Beverage\n";

    const int item_type = get_uint("Choose [1/2]: ");

    if (item_type == 1) {
        // Food
        const auto name = get_string(std::format("{:<{}}: ", "Enter food name", prompt_width));
        const auto base_price = get_uint(std::format("{:<{}}: ", "Enter base price", prompt_width));

        // Construct the food
        const auto new_food = Food{name, base_price};
        const auto new_entry = FoodEntry{
            inventory.next_id++,
            new_food,
            false,
        };

        const char proceed = get_char(std::format("{:<{}}: ", "Proceed? (Y/n)", prompt_width));
        if (tolower(proceed) == 'y') {
            // Add inventory
            inventory.foods.push_back(new_entry);

            // Add to audit the ID created
            save_audit_logs("Id = " + std::to_string(new_entry.id));
        } else {
            std::cout << "Alright. Scrapping this food...\n";
        }
    } else if (item_type == 2) {
        // Beverage
        const auto name = get_string(std::format("{:<{}}: ", "Enter beverage name", prompt_width));
        const auto base_price = get_uint(std::format("{:<{}}: ", "Enter base price", prompt_width));

        // Construct the food
        const auto new_beverage = Beverage{name, base_price};
        auto new_entry = BeverageEntry{
            inventory.next_id++,
            new_beverage,
            false,
        };

        const char proceed = get_char(std::format("{:<{}}:", "Proceed? (Y/n)", prompt_width));
        if (tolower(proceed) == 'y') {
            // Add inventory
            inventory.beverages.push_back(new_entry);
        } else {
            std::cout << "Alright. Scrapping this beverage...\n";
        }
    }
}

void remove_item(Inventory &inventory) {
    std::cout << Color::CYAN << Color::BOLD << "[ Add Item ]\n" << Color::RESET;

    // Ask what kind of item the user want to create
    std::cout << '\n'
            << Color::CYAN
            << "What kind of item do you want to remove?\n"
            << "[1] Food\n"
            << "[2] Beverage\n";

    const int item_type = get_uint("Choose [1/2]: ");

    if (item_type == 1) {
        // Ask for id
        int id = get_uint(std::format("{:>{}}: ", "Enter id", prompt_width));

        // Find the food in foods using id
        const auto it = std::ranges::find_if(inventory.foods.begin(), inventory.foods.end(), [&id](auto& f) -> bool {
            return f.id == id;
        });

        if (it != inventory.foods.end()) {
            // Archive it
            it->is_archive = true;
        } else {
            print_error("Invalid id. Did not find a food with matching id.");
        }
    } else if (item_type == 2) {
        // Beverage
        int id = get_uint(std::format("{:>{}}: ", "Enter id", prompt_width));

        // Find the beverage in beverages using id
        const auto it = std::ranges::find_if(inventory.beverages.begin(), inventory.beverages.end(), [&id](auto& f) -> bool {
            return f.id == id;
        });

        if (it != inventory.beverages.end()) {
            // Archive it
            it->is_archive = true;
        } else {
            print_error("Invalid ID. Did not find a beverage with matching id.");
        }
    }
}

void edit_item(Inventory &inventory) {
    std::cout << Color::CYAN << Color::BOLD << "[ Add Item ]\n" << Color::RESET;
}

void find_item(const Inventory &inventory) {

}