#ifndef TODOLIST_DATE_H
#define TODOLIST_DATE_H


class Date {

private:
    int Day;
    int Month;
    int Year;

    bool IsBisestile(int Year) const;

public:
    Date() : Day(1),Month(1),Year(2000){}

    //Getter
    int GetDay() const;
    int GetMonth() const;
    int GetYear() const;

    //Setter
    void SetDay(int day);
    void SetMonth(int month);
    void SetYear(int year);

    void PrintCurrentDate() const;
    int DaysAvailable(int Month,int Year) const;
};

#endif
