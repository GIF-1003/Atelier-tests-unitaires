#include "ShoppingCart.h"
#include <stdexcept>

void ShoppingCart::addItem(const std::string& itemName, double price) {
    items.push_back({itemName, price});
}

void ShoppingCart::applyDiscount(const std::string& itemName, double discountPercentage) {
    for (auto& item : items) {
        if (item.name == itemName) {
            item.price = item.price - (item.price * discountPercentage / 100);
            break;
        }
    }
}

double ShoppingCart::getTotalCost() const {
    double total = 0.0;
    for (const auto& item : items) {
        total += item.price;
    }

    return total;
}

const std::vector<Item>& ShoppingCart::getItems() const {
    return items;
}

void ShoppingCart::removeItem(const std::string& itemName) {
    bool itemFound = false;

    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->name == itemName) {
            items.erase(it);
            itemFound = true;
            break;
        }
    }

    if (!itemFound) {
        throw std::runtime_error("The article to be deleted does not exist in the shopping cart.");
    }
}