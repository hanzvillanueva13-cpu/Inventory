//
// Created by Hanz on 06/15/26.
//

#ifndef INVENTORY_INVENTORY_H
#define INVENTORY_INVENTORY_H

#include <vector>

#include "Beverage.h"
#include "Food.h"

constexpr int prompt_width = 25;

struct FoodEntry {
    int id{};

    // Item data
    Food food;

    // To track current_stock over allotted_stock
    int current_stock{};
    int target_stock{};

    // To track whether the item is "removed"
    bool is_archive{};
};

struct BeverageEntry {
    int id{};

    // Item data
    Beverage beverage;

    // To track current_stock over allotted_stock
    int current_stock{};
    int target_stock{};

    // To track whether the item is "removed"
    bool is_archive{};
};

struct Order {
    int item_id{};
    int amount{};
};

struct Inventory {
    // The id to use
    int next_id = 1;

    // The inventory for foods and beverages
    std::vector<FoodEntry> foods;
    std::vector<BeverageEntry> beverages;

    // For tracking current orders
    std::vector<Order> orders;
};

/**
 * @brief Load the inventory from file
 * @param inventory The inventory to populate
 */
void load_inventory(Inventory &inventory);

/**
 * @brief Generate the id to use
 * @param inventory The inventory that tracks the IDs
 * @return The id to be used
 */
int generate_id(Inventory &inventory);

/**
 * @brief Add an item based from user input
 * @param inventory The inventory to add the item to
 */
void add_item(Inventory &inventory);

/**
 * @brief Remove an item based from user input
 * @param inventory The inventory to remove the item from
 */
void remove_item(Inventory &inventory);

/**
 * @brief Edit an item data based from user input
 * @param inventory The inventory of the item to edit
 */
void edit_item(Inventory &inventory);

/**
 * @brief Find an item based from user input
 * @param inventory
 */
void find_item(const Inventory &inventory);

// ========== Menu Options: Inventory ==========

/**
 * @brief View the inventory content in detailed form
 * @param inventory The inventory to show
 */
void view_inventory(const Inventory &inventory);

/**
 * @brief View inventory stock content
 * @param inventory The inventory to show
 */
void view_stocks(const Inventory &inventory);

/**
 * @brief Save the inventory to file
 * @param inventory The inventory to save
 */
void save_inventory(Inventory &inventory);

// ========== Menu Options: Inventory ==========

/**
 * @brief To view orders in table-like form
 * @param inventory The inventory containing the order list
 */
void view_orders(Inventory &inventory);

/**
 * @brief Add new order to the list
 * @param inventory The inventory containing the order list
 */
void add_order(Inventory &inventory);

#endif //INVENTORY_INVENTORY_H
