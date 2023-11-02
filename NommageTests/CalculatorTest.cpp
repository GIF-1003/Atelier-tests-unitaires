#include <gtest/gtest.h>
#include "Calculator.h"

/*
 * Exercices Nommage des tests
 * */
class CalculatorTest : public ::testing::Test {

};

TEST_F(CalculatorTest, GivenTwoNumbers_WhenAdding_ThenSumIsCorrect) {
// Given
int firstNumber = 5;
int secondNumber = 10;

// When
int result = Calculator::add(firstNumber, secondNumber);

// Then
EXPECT_EQ(result, 15);
}

TEST_F(CalculatorTest, GivenTwoNumbers_WhenSubtracting_ThenDifferenceIsCorrect) {
// Given
int firstNumber = 10;
int secondNumber = 5;

// When
int result = Calculator::subtract(firstNumber, secondNumber);

// Then
EXPECT_EQ(result, 5);
}

TEST_F(CalculatorTest, GivenTwoNumbers_WhenMultiplying_ThenProductIsCorrect) {
// Given
int firstFactor = 5;
int secondFactor = 10;

// When
int result = Calculator::multiply(firstFactor, secondFactor);

// Then
EXPECT_EQ(result, 50);
}

TEST_F(CalculatorTest, GivenTwoNumbers_WhenDividing_ThenQuotientIsCorrect) {
// Given
int dividend = 10;
int divisor = 2;

// When
int result = Calculator::divide(dividend, divisor);

// Then
EXPECT_EQ(result, 5);
}

TEST_F(CalculatorTest, GivenDividendAndZeroDivisor_WhenDividing_ThenExceptionIsThrown) {
// Given
int dividend = 10;
int divisor = 0;

// When + Then
EXPECT_THROW(Calculator::divide(dividend, divisor), std::runtime_error);
}
