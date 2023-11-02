#include "Calculator.h"
#include <stdexcept>

int Calculator::add(int firstNumber, int secondNumber) {
    return firstNumber + secondNumber;
}

int Calculator::subtract(int firstNumber, int secondNumber) {
    return firstNumber - secondNumber;
}

int Calculator::multiply(int firstFactor, int secondFactor) {
    return firstFactor * secondFactor;
}

int Calculator::divide(int dividend, int divisor) {
    if (divisor == 0) {
        throw std::runtime_error("Division by zero is not allowed.");
    }
    return dividend / divisor;
}
