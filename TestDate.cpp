#include "Date.h"
#include <cassert>
#include <iostream>

void TestDefaultConstructor() {
    Date d;
    assert(d.GetDay() == 1);
    assert(d.GetMonth() == 1);
    assert(d.GetYear() == 2000);
    std::cout << "Test OK!!" << std::endl;
}
void TestDaysInMonths() {
    Date d;
    assert(d.DaysAvailable(1, 2023) == 31); // gennaio
    assert(d.DaysAvailable(4, 2023) == 30); // aprile
    std::cout << "Test OK!!" << std::endl;
}
//testo setter and getter
void TestSetAndGet() {
    Date d;
    d.SetYear(2023);
    d.SetMonth(5);
    d.SetDay(15);

    assert(d.GetDay() == 15);
    assert(d.GetMonth() == 5);
    assert(d.GetYear() == 2023);
    std::cout << "Test OK!!" << std::endl;
}
void TestInvalidDay() {
    Date d;
    d.SetMonth(2);
    d.SetYear(2023); // febbraio non bisestile
    d.SetDay(30);    // giorno non valido

    assert(d.GetDay() != 30);
    std::cout << "Test OK!!" << std::endl;
}
void TestInvalidMonth() {
    Date d;
    d.SetMonth(13);

    assert(d.GetMonth() >= 1 && d.GetMonth() <= 12);
    std::cout << "Test OK!!" << std::endl;
}

int main(){

    TestDefaultConstructor();
    TestDaysInMonths();
    TestSetAndGet();
    TestInvalidDay();
    TestInvalidMonth();

    return 0;

};