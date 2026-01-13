#include Date.h

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
int Date::DaysAvaible(int Month,int Year) const {
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
            return 30;       // se qualcuno passa un numero maggiore di 12
    }
}

int Date::GetDay() const {
    return Day;
}
int Date::GetMonth() const {
    return Month;
}
int Date::getYear() const {
    return Year;
}

void Date::SetDay(int Day){

}