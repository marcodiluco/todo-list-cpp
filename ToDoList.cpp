#include "ToDoList.h"
#include "Activity.h"

#include <iostream>
#include <string>

ToDoList::ToDoList(const std::string& title) : Title(title) {}

void ToDoList::SetTitle(const std::string &title) {
    Title=title;
}
const std::string &ToDoList::GetTitle() const {
    return Title;
}

const std::list<Activity> &ToDoList::GetToDoList() const {
    return TodoList;
}

void ToDoList::AddActivity(const Activity &activity) {
    TodoList.push_back(activity);
}
void ToDoList::RemoveActivity(const std::string &description) {
    for(auto flag=TodoList.begin(); flag!=TodoList.end(); ){             //preferisco mettere flag++ nell if per evitare problemi iteratori
        if(flag->GetDescription()==description){                                                   //non validi
            TodoList.erase(flag);
        }else{
            flag++;
        }
    }
}