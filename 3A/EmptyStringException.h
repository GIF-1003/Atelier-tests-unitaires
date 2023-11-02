#ifndef EMPTY_STRING_EXCEPTION_H
#define EMPTY_STRING_EXCEPTION_H

#include <stdexcept>

class EmptyStringException : public std::exception {
public:
    const char* what() const noexcept override {
        return "The string is empty";
    }
};

#endif // EMPTY_STRING_EXCEPTION_H
