#include <iostream>
#include "ToDoList.h"
#include "Activity.h"
#include "Date.h"

int main(){
    ToDoList MyList;
    bool stop=false;
    int option;

    std::cout << "     *********** Welcome in My ToDoList!! ***********     " << std::endl;
    std::cout << "Choose an option from the list to star:" << std::endl;
    std::cout << "1) Create a new ToDoList" << std::endl;
    std::cout << "2) Add a new Activity" << std::endl;
    std::cout << "3) Remove an Activity" << std::endl;
    std::cout << "4) Modify an Activity" << std::endl;
    std::cout << "5) Mark Activity as Completed" << std::endl;
    std::cout << "6) Mark Activity as ToDo (not completed)" << std::endl;
    std::cout << "7) Display all Activities" << std::endl;
    std::cout << "8) Display uncompleted Activities" << std::endl;
    std::cout << "9) Display completed Activities" << std::endl;
    std::cout << "10) Check if a single Activity is completed" << std::endl;
    std::cout << "11) Save Activities to File" << std::endl;
    std::cout << "12) Load Activities from File" << std::endl;
    std::cout << "0) Exit" << std::endl;


    return 0;
};
