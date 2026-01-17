#include <cassert>
#include <iostream>
#include "ToDoList.h"
#include "Activity.h"
#include "Date.h"

void TestConstructorAndTitle() {
    ToDoList t("My List");
    assert(t.GetTitle() == "My List");
    t.SetTitle("New Title");
    assert(t.GetTitle() == "New Title");
}
void TestAddAndRemoveActivity() {
    ToDoList t("Test");
    Date d;
    Activity a("Studiare", d);
    t.AddActivity(a);

    assert(t.GetToDoList().size() == 1);
    bool removed = t.RemoveActivity("Studiare");
    assert(removed == true);
    assert(t.GetToDoList().empty());
    assert(t.RemoveActivity("Non esiste") == false);
}
