#include "ToDoList.h"

ToDoList::ToDoList(const std::string& title) : Title(title) {}

void ToDoList::SetTitle(const std::string &title) {
    Title=title;
}
const std::string &ToDoList::GetTitle() const {
    return Title;
}