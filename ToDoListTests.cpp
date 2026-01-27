#include "gtest/gtest.h"
#include "Date.h"

// ----------  TEST DATE  ----------

TEST(DateTest,DefaultConstructor){
    Date d;
    EXPECT_EQ(d.GetDay(), 1);
    EXPECT_EQ(d.GetMonth(), 1);
    EXPECT_EQ(d.GetYear(), 2000);
}
TEST(DateTest,Setters){
    Date d;
    d.SetDay(15);
    d.SetMonth(5);
    d.SetYear(2024);
    EXPECT_EQ(d.GetDay(), 15);
    EXPECT_EQ(d.GetMonth(), 5);
    EXPECT_EQ(d.GetYear(), 2024);
}
TEST(DateTest,SetDayInvalid){
    Date d;
    d.SetMonth(4); // aprile ne ha 30
    d.SetDay(31);
    EXPECT_NE(d.GetDay(), 31);
}
TEST(DateTest,SetMonthInvalid){
    Date d;
    d.SetMonth(13);
    EXPECT_NE(d.GetMonth(), 13);
}
TEST(DateTest,SetYearInvalid){
    Date d;
    d.SetYear(-5);
    EXPECT_NE(d.GetYear(), -5);
}
TEST(DateTest,DaysAvailable){
    Date d;
    EXPECT_EQ(d.DaysAvailable(1, 2023), 31);
    EXPECT_EQ(d.DaysAvailable(2, 2023), 28); // non bisestile
    EXPECT_EQ(d.DaysAvailable(2, 2024), 29); // bisestile
    EXPECT_EQ(d.DaysAvailable(4, 2023), 30);
    EXPECT_EQ(d.DaysAvailable(12, 2023), 31);
}
