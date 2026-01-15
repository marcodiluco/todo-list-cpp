#include "Activity.h"
#include "Date.h"
#include <iostream>
#include <string>

bool Activity::IsComplete() const {
    return Complete;
}
void Activity::SetComplete() {
    Complete = true;
}
void Activity::SetUnComplete() {
    Complete = false;
}

const std::string &Activity::GetDescription() const{
    return Description;
}
void Activity::SetDescription(const std::string &NewDescription) {
    Description = NewDescription;
}

const Date& Activity::GetDate() const{
    return date;
}
void Activity::SetDate(const Date& newDate) {
    date = newDate;
}

void Activity::PrintActivity() const {
    if(Complete){
        std::cout << "[X] : ";
    }else{
        std::cout << "[] : ";
    }
    std::cout << Description << " - scadenza: ";
    date.PrintCurrentDate();
    std::cout << std::endl;
}