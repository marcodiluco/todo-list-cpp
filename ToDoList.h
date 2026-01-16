#ifndef TODOLIST_TODOLIST_H
#define TODOLIST_TODOLIST_H

#include "Activity.h"
#include <list>
#include <fstream>

class ToDoList{

private:
    std::list<Activity> TodoList;
    std::string Title;

public:
    ToDoList(const std::string& title);
    ToDoList()=default;

    //setter and getter title
    void SetTitle(const std::string &title);
    const std::string &GetTitle() const;

    //getter TodoList
    const std::list<Activity> &GetToDoList() const;

    //operazioni sulla lista
    void AddActivity(const Activity &activity);
    bool RemoveActivity(const std::string &description);
    void ClearAllActivities();

    //operazioni di check delle attività: sono state fatte?,la spunto perchè fatta o tolgo spunta perchè da fare o rifare
    bool CheckActivity(const std::string &description, bool &found) const;
    bool SetActivityComplete(const std::string &description);
    bool SetActivityUnComplete(const std::string &description);

    //operazioni di modifica
    bool ModifyActDescription(const std::string &oldDescription, const std::string &newDescription);
    bool ModifyActDate(const std::string &description, const Date &Newdate);

    //scrittura
    void PrintAllActivity() const;
    void PrintCompletedActivities() const;
    void PrintUnCompleteActivities() const;

    //scrittura e lettura su disco
    bool SaveToFile(const std::string &Filename) const;
    bool LoadToFile(const std::string &Filename);

};

#endif
