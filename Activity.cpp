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

const std::string &Activity::GetDescription(){
    return Description;
}
void Activity::SetDescription(const std::string &NewDescription) {
    Description = NewDescription;
}

const Date& Activity::GetDate() {
    return date;
}
void Activity::SetDate(const Date& newDate) {
    date = newDate;
}