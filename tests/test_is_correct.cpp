// Copyright 2024 Kirill Remizov

#include <gtest.h>
#include "../lib_Parser/Parser.h"
#include "../lib_CString/CString.h"


#define EPSILON 0.000001


TEST(IsCorrectTest, ValidExpression) {
    CString valid_exp("(a+b)*[c-d]/{e*f}");
    EXPECT_TRUE(is_correct(&valid_exp));
}

TEST(IsCorrectTest, UnmatchedOpeningBracket) {
    CString unmatched_opening("(a+b)*[c-d]/{e*f");
    EXPECT_FALSE(is_correct(&unmatched_opening));
}

TEST(IsCorrectTest, UnmatchedClosingBracket) {
    CString unmatched_closing("(a+b)*[c-d]/e*f]");
    EXPECT_FALSE(is_correct(&unmatched_closing));
}

TEST(IsCorrectTest, EmptyString) {
    CString empty_exp("");
    EXPECT_TRUE(is_correct(&empty_exp));
}

TEST(IsCorrectTest, OnlyOpeningBrackets) {
    CString only_opening("({[");
    EXPECT_FALSE(is_correct(&only_opening));
}

TEST(IsCorrectTest, OnlyClosingBrackets) {
    CString only_closing(")}]");
    EXPECT_FALSE(is_correct(&only_closing));
}

TEST(IsCorrectTest, MixedValidExpression) {
    CString mixed_valid("a+(b*c)-[d/{e}]");
    EXPECT_TRUE(is_correct(&mixed_valid));
}
