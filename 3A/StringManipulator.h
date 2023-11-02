#ifndef ATELIER_TESTS_UNITAIRES_STRINGMANIPULATOR_H
#define ATELIER_TESTS_UNITAIRES_STRINGMANIPULATOR_H

#include <string>

class StringManipulator {
    public:
        static int countCharacters(const std::string& str);
        static std::string removeSpaces(const std::string& str);
        static std::string convertToLowercase(const std::string& str);
        static int countNumberOfWords(const std::string& str);
};

#endif //ATELIER_TESTS_UNITAIRES_STRINGMANIPULATOR_H
