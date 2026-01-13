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