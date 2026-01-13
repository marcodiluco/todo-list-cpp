#ifndef TODOLIST_DATE_H
#define TODOLIST_DATE_H

class Date {
private:
    int Day;
    int Month;
    int Year;
public:
    Date() : Day(0),Month(0),Year(0){}

    int GetDay() const;
    int GetMonth() const;
    int GetYear() const;


};















#endif
