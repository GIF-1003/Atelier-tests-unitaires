#ifndef ATELIER_TESTS_UNITAIRES_SHOPPINGCART_H
#define ATELIER_TESTS_UNITAIRES_SHOPPINGCART_H

#include <string>
#include <vector>

struct Item {
    std::string name;
    double price;
};

class ShoppingCart {
    public:
        void addItem(const std::string& itemName, double price);
        void applyDiscount(const std::string& itemName, double discountPercentage);
        void removeItem(const std::string& itemName);
        double getTotalCost() const;
        const std::vector<Item>& getItems() const;

    private:
        std::vector<Item> items;
};


#endif //ATELIER_TESTS_UNITAIRES_SHOPPINGCART_H
