#include "gtest/gtest.h"
#include "Date.h"

// Test Date

TEST(DateTest,DefaultConstructor){
    Date d;
    EXPECT_EQ(d.GetDay(), 1);
    EXPECT_EQ(d.GetMonth(), 1);
    EXPECT_EQ(d.GetYear(), 2000);
}
