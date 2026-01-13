#ifndef TODOLIST_ACTIVITY_H
#define TODOLIST_ACTIVITY_H

#include <string>
#include "Date.h"

class Activity{

private:
    std::string Description;
    Date date;
    bool Complete;

public:
    Activity(const std::string &Description,const Date &date) : Description(Description),date(date),Complete(false){}

    bool IsComplete() const;
    void SetComplete();
    void SetUnComplete();     //nel caso si voglia rifare
};











#endif
