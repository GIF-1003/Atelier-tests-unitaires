#include <gtest/gtest.h>
#include "StringManipulator.h"
#include "EmptyStringException.h"

/*
 * Exercises 3A
 * */
class StringManipulatorTest : public ::testing::Test {
    protected:
        const std::string EMPTY_STRING = "";
        const std::string NON_EMPTY_STRING = "Hello";
        const std::string STRING_WITH_SPACES = "Hello, World!";
        const std::string STRING_WITHOUT_SPACES = "Hello,World!";
        const std::string STRING_IN_UPPERCASE = "HELLO, WORLD!";
        const std::string STRING_IN_LOWERCASE = "hello, world!";
        const std::string STRING_WITH_SPECIAL_CHARACTERS = "Hello,;World!";
};

TEST_F(StringManipulatorTest, GivenEmptyString_WhenCountCharacters_ThenResultIsZero) {
    // Arrange
    std::string str = EMPTY_STRING;

    // Act
    int numCharacters = StringManipulator::countCharacters(str);

    // Assert
    EXPECT_EQ(numCharacters, 0);
}

TEST_F(StringManipulatorTest, GivenNonEmptyString_WhenCountCharacters_ThenResultIsCorrect) {
    // Arrange
    std::string str = NON_EMPTY_STRING;

    // Act
    int numCharacters = StringManipulator::countCharacters(str);

    // Assert
    EXPECT_EQ(numCharacters, 5);
}

TEST_F(StringManipulatorTest, GivenStringWithSpaces_WhenRemoveSpaces_ThenSpacesAreRemoved) {
    // Arrange
    std::string str = STRING_WITH_SPACES;

    // Act
    std::string result = StringManipulator::removeSpaces(str);

    // Assert
    EXPECT_EQ(result, STRING_WITHOUT_SPACES);
}

TEST_F(StringManipulatorTest, GivenStringWithoutSpaces_WhenRemoveSpaces_ThenStringRemainsUnchanged) {
    // Arrange
    std::string str = STRING_WITHOUT_SPACES;

    // Act
    std::string result = StringManipulator::removeSpaces(str);

    // Assert
    EXPECT_EQ(result, STRING_WITHOUT_SPACES);
}

TEST_F(StringManipulatorTest, GivenStringWithUppercaseLetters_WhenConvertToLowercase_ThenStringIsConvertedToLowercase) {
    // Arrange
    std::string str = STRING_IN_UPPERCASE;

    // Act
    std::string result = StringManipulator::convertToLowercase(str);

    // Assert
    EXPECT_EQ(result, STRING_IN_LOWERCASE);
}

TEST_F(StringManipulatorTest, GivenStringInLowercase_WhenConvertToLowercase_ThenStringRemainsUnchanged) {
    // Arrange
    std::string str = STRING_IN_LOWERCASE;

    // Act
    std::string result = StringManipulator::convertToLowercase(str);

    // Assert
    EXPECT_EQ(result, STRING_IN_LOWERCASE);
}

TEST_F(StringManipulatorTest, GivenEmptyString_WhenCountNumberOfWords_ThenExceptionIsThrown) {
    // Arrange
    std::string str = EMPTY_STRING;

    // Act + Assert
    EXPECT_THROW(StringManipulator::countNumberOfWords(str), EmptyStringException);
}

TEST_F(StringManipulatorTest, GivenStringWithOneWord_WhenCountNumberOfWords_ThenCountIsOne) {
    // Arrange
    std::string str = NON_EMPTY_STRING;

    // Act
    int wordCount = StringManipulator::countNumberOfWords(str);

    // Assert
    EXPECT_EQ(wordCount, 1);
}

TEST_F(StringManipulatorTest, GivenStringWithWordsSeparatedBySpaces_WhenCountNumberOfWords_ThenCountIsCorrect) {
    // Arrange
    std::string str = STRING_WITH_SPACES;

    // Act
    int wordCount = StringManipulator::countNumberOfWords(str);

    // Assert
    EXPECT_EQ(wordCount, 2);
}

TEST_F(StringManipulatorTest, GivenStringWithWordsSeparatedBySpecialCharacters_WhenCountNumberOfWords_ThenCountIsCorrect) {
    // Arrange
    std::string str = STRING_WITH_SPECIAL_CHARACTERS;

    // Act
    int wordCount = StringManipulator::countNumberOfWords(str);

    // Assert
    EXPECT_EQ(wordCount, 2);
}
