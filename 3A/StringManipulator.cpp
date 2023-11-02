#include "StringManipulator.h"
#include "EmptyStringException.h"
#include <cctype>

int StringManipulator::countCharacters(const std::string& str) {
    return str.length();
}

std::string StringManipulator::removeSpaces(const std::string& str) {
    std::string result;
    for (char c : str) {
        if (!std::isspace(c)) {
            result += c;
        }
    }
    return result;
}

std::string StringManipulator::convertToLowercase(const std::string& str) {
    std::string result;
    for (char c : str) {
        result += std::tolower(c);
    }
    return result;
}

int StringManipulator::countNumberOfWords(const std::string& str) {
    if (str.empty()) {
        throw EmptyStringException();
    }

    int wordCount = 0;
    bool insideTheWord = false;

    for (char c : str) {
        if (std::isalnum(c)) {
            if (!insideTheWord) {
                wordCount++;
                insideTheWord = true;
            }
        } else {
            insideTheWord = false;
        }
    }

    return wordCount;
}