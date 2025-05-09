#include <gtest/gtest.h>
#include "../polecenia.h"

TEST(intTestFunction, intTest)
{
    EXPECT_EQ(toInt("123"), 123);
    EXPECT_EQ(toInt("23400"), 23400);
    EXPECT_EQ(toInt("1"), 1);
}