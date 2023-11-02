#include <gtest/gtest.h>
#include "ShoppingCart.h"
#include "ConfigReader.cpp"

/*
 * Exercices FIRST
 * */
class ShoppingCartTest : public ::testing::Test {
    protected:
        const double ITEM_PRICE = 100.0;
        const double ITEM_PRICE_2 = 50.0;
        const double ITEM_PRICE_3 = 75.0;
        const double DISCOUNT_PERCENTAGE = 20.0;
        const double EXPECTED_DISCOUNTED_PRICE = ITEM_PRICE - (ITEM_PRICE * DISCOUNT_PERCENTAGE / 100);
        const double EXPECTED_TOTAL_COST_ZERO = 0.0;
        const double EXPECTED_TOTAL_COST = 225.0;

        const std::string ITEM_NAME = "Item X";
        const std::string ITEM_NAME_2 = "Item Y";
        const std::string ITEM_NAME_3 = "Item Z";

        ShoppingCart cart;
};

TEST_F(ShoppingCartTest, GivenItems_WhenAddingItems_ThenItemsAreAddedToCart) {
    // Act
    cart.addItem(ITEM_NAME, ITEM_PRICE);
    cart.addItem(ITEM_NAME_2, ITEM_PRICE);

    // Assert
    int expectedCount = 2;
    EXPECT_EQ(expectedCount, cart.getItems().size());
}

TEST_F(ShoppingCartTest, GivenACartAndAnItem_WhenApplyDiscount_ThenItemPriceIsDiscounted) {
    // Arrange
    cart.addItem(ITEM_NAME, ITEM_PRICE);

    // Act
    cart.applyDiscount(ITEM_NAME, DISCOUNT_PERCENTAGE);

    const std::vector<Item>& items = cart.getItems();
    Item itemDiscounted;
    for (const auto& item : items) {
        if (item.name == ITEM_NAME) {
            itemDiscounted = item;
        }
    }

    EXPECT_EQ(itemDiscounted.price, EXPECTED_DISCOUNTED_PRICE);
}

TEST_F(ShoppingCartTest, GivenEmptyCart_WhenGetTotalCost_ThenTotalCostIsZero) {
    // Act
    double totalCost = cart.getTotalCost();

    // Assert
    EXPECT_EQ(totalCost, EXPECTED_TOTAL_COST_ZERO);
}

TEST_F(ShoppingCartTest, GivenCartWithMultipleItems_WhenGetTotalCost_ThenTotalCostIsSumOfItemPrices) {
    // Arrange
    cart.addItem(ITEM_NAME, ITEM_PRICE);
    cart.addItem(ITEM_NAME_2, ITEM_PRICE_2);
    cart.addItem(ITEM_NAME_3, ITEM_PRICE_3);

    // Act
    double totalCost = cart.getTotalCost();

    // Assert
    EXPECT_DOUBLE_EQ(totalCost, EXPECTED_TOTAL_COST);
}

TEST_F(ShoppingCartTest, GivenShoppingCartWithAnItem_WhenRemoveItem_ThenItemIsRemoved) {
    // Arrange
    cart.addItem(ITEM_NAME, ITEM_PRICE);

    // Act
    cart.removeItem(ITEM_NAME);

    // Assert
    const std::vector<Item>& items = cart.getItems();
    EXPECT_EQ(items.size(), 0);
}

TEST_F(ShoppingCartTest, GivenEmptyShoppingCart_WhenRemoveItem_ThenExceptionIsThrown) {
    // Act & Assert
    EXPECT_THROW(cart.removeItem(ITEM_NAME), std::runtime_error);
}
