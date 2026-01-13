#include "Date.h"
#include <iostream>

bool Date::IsBisestile(int Year) const {
    if (Year % 4 == 0) {
        if (Year % 100 == 0) {
            if (Year % 400 == 0)
                return true;
            else
                return false;   //non bisestile perchè è divisibile per 100 e non per 400
        } else
            return true;
    }
    return false;            //non bisestile perchè non è divisibile per 4
}
int Date::DaysAvailable(int Month,int Year) const {
    switch (Month){
        case 1: case 3: case 5: case 7:
        case 8: case 10: case 12:         //gennaio,marzo,maggio,luglio,agosto,ottobre,dicembre ne hanno 31
            return 31;
        case 4: case 6: case 9: case 11:    //aprile,giugno,settembre,novembre ne hanno 30
            return 30;
        case 2:
            if (IsBisestile(Year)) {
                return 29;
            } else {
                return 28;
            }
        default:
            return 30;       // se qualcuno passa un numero maggiore di 12 o 0
    }
}

int Date::GetDay() const {
    return Day;
}
int Date::GetMonth() const {
    return Month;
}
int Date::GetYear() const {
    return Year;
}

void Date::SetDay(int day){
    if(day>=1 && day<=DaysAvailable(Month,Year))
        Day=day;
    else
        std::cout << "errore!!,giorno non valido per questo mese e anno!!" << std::endl;
}
void Date::SetMonth(int month){
    if(month>=1 && month<=12) {
        Month = month;
        if (Day>DaysAvailable(Month, Year)) {                      //controllo che il giorno corrente vada bene per il mese scelto ora
            std::cout << "errore!!,giorno attuale non valido per questo mese!!" << std::endl;
        }
    }else{
        std::cout << "errore!!,mese non valido!!" << std::endl;
    }
}
void Date::SetYear(int year){
    if(year>0){
        Year=year;
        if(Month==2 && Day>DaysAvailable(Month, Year)){             //controlliamo solo febbraio perchè cambiando l'anno solo febbraio cambia i giorni
            std::cout << "errore!!,ti ricordo che febbraio è bisestile!!" << std::endl;                           //gli altri sono fissi
        }
    }else{
        std::cout << "errore!!,anno non valido!!" << std::endl;
    }
}

void Date::PrintCurrentDate(){
    std::cout << "Data corrente : ";
    if(Day<10){
        std::cout << "0" << Day << "/";
    }else{
        std::cout << Day << "/";
    }
    if(Month<10){
        std::cout << "0" << Month << "/";
    }else{
        std::cout << Month << "/";
    }
    std::cout << Year << std::endl;
}