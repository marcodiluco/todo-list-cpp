#ifndef TODOLIST_DATE_H
#define TODOLIST_DATE_H

class Date {
private:
    int Day;
    int Month;
    int Year;

    bool IsBisestile(int Year) const;
    int DaysAvaible(int Month,int Year) const;

public:
    Date() : Day(0),Month(0),Year(0){}

    int GetDay() const;
    int GetMonth() const;
    int GetYear() const;

    void SetDay(int Day);
    void SetMonth(int Month);
    void SetYear(int Year);


};















#endif
