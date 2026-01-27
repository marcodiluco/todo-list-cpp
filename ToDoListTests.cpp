#include "gtest/gtest.h"
#include "Date.h"
#include "Activity.h"
#include "ToDoList.h"

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
    d.SetYear(-2);
    EXPECT_NE(d.GetYear(), -2);
}
TEST(DateTest,DaysAvailable){
    Date d;
    EXPECT_EQ(d.DaysAvailable(1, 2023), 31);
    EXPECT_EQ(d.DaysAvailable(2, 2023), 28); // non bisestile
    EXPECT_EQ(d.DaysAvailable(2, 2024), 29); // bisestile
    EXPECT_EQ(d.DaysAvailable(4, 2023), 30);
    EXPECT_EQ(d.DaysAvailable(12, 2023), 31);
}



// ----------  TEST ACTIVITY  ----------

TEST(ActivityTest,ConstructorAndGetters){
    Date d;
    Activity a("Test.1", d);
    EXPECT_EQ(a.GetDescription(), "Test.1");
    EXPECT_EQ(a.GetDate().GetDay(), d.GetDay());
    EXPECT_EQ(a.GetDate().GetMonth(), d.GetMonth());
    EXPECT_EQ(a.GetDate().GetYear(), d.GetYear());
    EXPECT_FALSE(a.IsComplete());
}
TEST(ActivityTest,CompleteStatus){
    Date d;
    Activity a("Test.2", d);
    a.SetComplete();
    EXPECT_TRUE(a.IsComplete());
    a.SetUnComplete();
    EXPECT_FALSE(a.IsComplete());
}
TEST(ActivityTest,SetDescription){
    Date d;
    Activity a("Test.3a", d);
    a.SetDescription("Test.3b");
    EXPECT_EQ(a.GetDescription(), "Test.3b");
}
TEST(ActivityTest,SetDate){
    Date d1;
    Date d2;
    d2.SetDay(15);
    d2.SetMonth(8);
    d2.SetYear(2025);
    Activity a("Test.4", d1);
    a.SetDate(d2);
    EXPECT_EQ(a.GetDate().GetDay(), 15);
    EXPECT_EQ(a.GetDate().GetMonth(), 8);
    EXPECT_EQ(a.GetDate().GetYear(), 2025);
}



// ----------  TEST TODOLIST  ----------


