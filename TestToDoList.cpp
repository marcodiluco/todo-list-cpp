#include <cassert>
#include <iostream>
#include "ToDoList.h"
#include "Activity.h"
#include "Date.h"

void TestConstructorAndTitle(){
    ToDoList t("Test");
    assert(t.GetTitle() == "Test");
    t.SetTitle("New Test");
    assert(t.GetTitle() == "New Test");
}
void TestAddAndRemoveActivity(){
    ToDoList t("Test");
    Date d;
    Activity a("Studiare",d);
    t.AddActivity(a);

    assert(t.GetToDoList().size() == 1);
    bool removed = t.RemoveActivity("Studiare");
    assert(removed == true);
    assert(t.GetToDoList().empty());
    assert(t.RemoveActivity("Non esiste") == false);
}
void TestClearAllActivities(){
    ToDoList t("Test");
    Date d;
    t.AddActivity(Activity("A",d));
    t.AddActivity(Activity("B",d));

    t.ClearAllActivities();
    assert(t.GetToDoList().empty());
}
void TestSetComplete(){
    ToDoList t("Test");
    Date d;
    t.AddActivity(Activity("Studiare",d));

    bool found;
    assert(t.CheckActivity("Studiare",found) == false);
    assert(found == true);
    t.SetActivityComplete("Studiare");
    assert(t.CheckActivity("Studiare",found) == true);
    t.SetActivityUnComplete("Studiare");
    assert(t.CheckActivity("Studiare",found) == false);
}
void TestModifyDescription(){
    ToDoList t("Test");
    Date d;
    t.AddActivity(Activity("Studiare",d));

    bool modified = t.ModifyActDescription("Studiare","Mangiare");
    assert(modified == true);
    bool found;
    t.CheckActivity("Mangiare",found);
    assert(found == true);
}
void TestModifyDate(){
    ToDoList t("Test");
    Date d1;
    d1.SetDay(1);
    d1.SetMonth(1);
    d1.SetYear(2025);
    t.AddActivity(Activity("Studiare",d1));

    Date d2;
    d2.SetDay(20);
    d2.SetMonth(12);
    d2.SetYear(2026);
    bool modified = t.ModifyActDate("Studiare",d2);
    assert(modified == true);

    const auto& list = t.GetToDoList();
    auto it = list.begin();
    assert(it->GetDate().GetDay() == 20);
    assert(it->GetDate().GetMonth() == 12);
    assert(it->GetDate().GetYear() == 2026);
}

int main(){

    TestConstructorAndTitle();
    TestAddAndRemoveActivity();
    TestClearAllActivities();
    TestSetComplete();
    TestModifyDescription();
    TestModifyDate();

    return 0;

}

