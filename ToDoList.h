#ifndef TODOLIST_TODOLIST_H
#define TODOLIST_TODOLIST_H

#include "Activity.h"
#include <list>
#include <string>

class ToDoList{

private:
    std::list<Activity> TodoList;
    std::string Title;

public:
    ToDoList(const std::string& title);

    //setter and getter title
    void SetTitle(const std::string &title);
    const std::string &GetTitle() const;

    //getter TodoList
    const std::list<Activity> &GetToDoList() const;

    //operazioni sulla lista
    void AddActivity(const Activity &activity);
    void RemoveActivity(const std::string &description);


};

#endif
