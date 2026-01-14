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
    Activity(const std::string &description,const Date &date) : Description(description),date(date),Complete(false){}

    bool IsComplete() const;
    void SetComplete();
    void SetUnComplete();     //nel caso si voglia rifare l'attività

    const std::string &GetDescription();
    void SetDescription(const std::string &NewDescription);

    const Date& GetDate();
    void SetDate(const Date& NewDate);

    void PrintActivity() const;        //stampo attività

};

#endif
