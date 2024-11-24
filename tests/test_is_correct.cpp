// Copyright 2024 Kirill Remizov

#include <gtest.h>
#include "../lib_Parser/Parser.h"
#include "../lib_CString/CString.h"
#include <stdexcept>

TEST(IsCorrectTest, CorrectBrackets) {
    CString str1("([{}])");
    EXPECT_TRUE(is_correct(&str1));

    CString str2("{[()]}");
    EXPECT_TRUE(is_correct(&str2));
}

TEST(IsCorrectTest, MismatchedBrackets) {
    CString str("([)]");
    EXPECT_THROW(is_correct(&str), std::logic_error);
}

TEST(IsCorrectTest, UnmatchedClosingBracket) {
    CString str("{[()]}]");
    EXPECT_THROW(is_correct(&str), std::logic_error);
}

TEST(IsCorrectTest, UnmatchedOpeningBracket) {
    CString str("{[()]}(");
    EXPECT_THROW(is_correct(&str), std::logic_error);
}

TEST(IsCorrectTest, EmptyString) {
    CString str("");
    EXPECT_TRUE(is_correct(&str));
}

TEST(IsCorrectTest, NoBrackets) {
    CString str("abcdef");
    EXPECT_TRUE(is_correct(&str));
}

TEST(IsCorrectTest, SingleBrackets) {
    CString str1("()");
    EXPECT_TRUE(is_correct(&str1));

    CString str2("[]");
    EXPECT_TRUE(is_correct(&str2));

    CString str3("{}");
    EXPECT_TRUE(is_correct(&str3));
}

// Тесты для скобок модуля (|)
TEST(IsCorrectTest, CorrectModuleBrackets) {
    CString str1("(|)");
    EXPECT_ANY_THROW(is_correct(&str1));

    CString str2("(|(|)|)");
    EXPECT_ANY_THROW(is_correct(&str2));

    CString str3("{[(|)]}");
    EXPECT_ANY_THROW(is_correct(&str3));
}

TEST(IsCorrectTest, MismatchedModuleBrackets) {
    CString str1("(|)");
    EXPECT_ANY_THROW(is_correct(&str1));

    CString str2("(|(|)|)");
    EXPECT_ANY_THROW(is_correct(&str2));

    CString str3("{[(|)]}");
    EXPECT_ANY_THROW(is_correct(&str3));

    CString str4("(|)");
    EXPECT_ANY_THROW(is_correct(&str4));

    CString str5("(|(|)|)");
    EXPECT_ANY_THROW(is_correct(&str5));

    CString str6("{[(|)]}");
    EXPECT_ANY_THROW(is_correct(&str6));
}

TEST(IsCorrectTest, UnmatchedClosingModuleBracket) {
    CString str1("(||)");
    EXPECT_TRUE(is_correct(&str1));

    CString str2("(|(|)|)|");
    EXPECT_TRUE(is_correct(&str2));

    CString str3("{[(|)]|");
    EXPECT_ANY_THROW(is_correct(&str3));
}

TEST(IsCorrectTest, UnmatchedOpeningModuleBracket) {
    CString str1("(|");
    EXPECT_THROW(is_correct(&str1), std::logic_error);

    CString str2("(|(|)|");
    EXPECT_THROW(is_correct(&str2), std::logic_error);

    CString str3("{[(|]");
    EXPECT_THROW(is_correct(&str3), std::logic_error);
}

TEST(IsCorrectTest, MixedBrackets) {
    CString str1("(|[{}])");
    EXPECT_ANY_THROW(is_correct(&str1));

    CString str2("{[(|)]}");
    EXPECT_ANY_THROW(is_correct(&str2));

    CString str3("(|[{()}]|)");
    EXPECT_TRUE(is_correct(&str3));
}

TEST(IsCorrectTest, MixedMismatchedBrackets) {
    CString str1("(|[{)}]");
    EXPECT_THROW(is_correct(&str1), std::logic_error);

    CString str2("{[(|)]}");
    EXPECT_ANY_THROW(is_correct(&str2));

    CString str3("(|[{()}]|)");
    EXPECT_TRUE(is_correct(&str3));
}
