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

bool ToDoList::CheckActivity(const std::string &description) const {
    for (auto flag=TodoList.begin(); flag!=TodoList.end(); flag++){
        if (flag->GetDescription()==description){
            return flag->IsComplete();
        }
    }
    std::cout << "attività non trovata!!" << std::endl;
    return false;
}
void ToDoList::SetActivityComplete(const std::string &description) {
    for (auto flag=TodoList.begin(); flag!=TodoList.end(); flag++){
        if (flag->GetDescription()==description){
            flag->SetComplete();
            break;
        }
    }
}
void ToDoList::SetActivityUnComplete(const std::string &description) {
    for (auto flag=TodoList.begin(); flag!=TodoList.end(); flag++){
        if (flag->GetDescription()==description) {
            flag->SetComplete();
            break;
        }
    }
}

bool ToDoList::ModifyActDescription(const std::string &oldDescription, const std::string &newDescription) {
    for (auto flag=TodoList.begin(); flag!=TodoList.end(); flag++){
        if(flag->GetDescription()==oldDescription){
            flag->SetDescription(newDescription);
            std::cout << "descrizione modificata" << std::endl;
            return true;
        }
    }
    std::cout << "descrizione non trovata!!" << std::endl;
    return false;
}
bool ToDoList::ModifyActDate(const std::string &description, const Date &Newdate) {
    for (auto flag=TodoList.begin(); flag!=TodoList.end(); flag++){
        if(flag->GetDescription()==description){
            flag->SetDate(Newdate);
            std::cout << "data modificata" << std::endl;
            return true;
        }
    }
    std::cout << "descrizione non trovata!!" << std::endl;
    return false;
}

void ToDoList::PrintAllActivity() const {
    std::cout << "<<<<<<<   " << Title << "   >>>>>>>" << std::endl;
    if(TodoList.empty()){
        std::cout << "nessuna attività ancora presente!!" << std::endl;
    }
    int i=1;
    for(const auto &activity : TodoList){
        std::cout << i << ") ";
        activity.PrintActivity();
        i++;
    }
}
void ToDoList::PrintCompletedActivities() const {
    std::cout << "<<<<<<<   " << Title << ", completate!" << "   >>>>>>>" << std::endl;
    bool j=false;
    for(const auto &activity : TodoList){
        if (activity.IsComplete()) {
            activity.PrintActivity();
            j=true;
        }
    }
    if(j==false){
        std::cout << "nessuna attività completata!!" << std::endl;
    }
}
void ToDoList::PrintUnCompleteActivities() const {
    std::cout << "<<<<<<<   " << Title << ", da fare!" << "   >>>>>>>" << std::endl;
    bool j=false;
    for(const auto &activity : TodoList){
        if (!activity.IsComplete()) {
            activity.PrintActivity();
            j=true;
        }
    }
    if(j==false){
        std::cout << "nessuna attività da fare!!" << std::endl;
    }
}