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
    std::cout << "1) Create a new ToDoList." << std::endl;
    std::cout << "2) Add a new Activity." << std::endl;
    std::cout << "3) Remove an Activity." << std::endl;
    std::cout << "4) Modify an Activity." << std::endl;
    std::cout << "5) Mark Activity as Completed." << std::endl;
    std::cout << "6) Mark Activity as ToDo (not completed)." << std::endl;
    std::cout << "7) Display all Activities." << std::endl;
    std::cout << "8) Display uncompleted Activities." << std::endl;
    std::cout << "9) Display completed Activities." << std::endl;
    std::cout << "10) Check if a single Activity is completed." << std::endl;
    std::cout << "11) Save Activities to File." << std::endl;
    std::cout << "12) Load Activities from File." << std::endl;
    std::cout << "0) Exit.\n" << std::endl;

    do{
        std::cout << "***************************************************************" << std::endl;
        std::cout << "Choose your option: ";
        std::cin >> option;

        switch(option){
            case 0:
                stop=true;
                std::cout << "**** Thanks for using My ToDoList. GOODBYE!! ****" << std::endl;
                break;

            case 1:{
                std::string title;
                std::cout << "Enter the title of the new ToDoList: ";
                std::cin.ignore();
                std::getline(std::cin,title);
                MyList.SetTitle(title);
                MyList.ClearAllActivities();
                std::cout << "New ToDo List: " << MyList.GetTitle() << " created!" << std::endl;
                break;
            }
            case 2:{
                std::string description;
                int day,month,year;
                Date date;
                std::cout << "Enter activity description: ";
                std::cin.ignore();
                std::getline(std::cin,description);

                do{
                    std::cout << "Enter date (day month year): ";
                    std::cin >> day >> month >> year;
                    std::cin.ignore();
                    if (month < 1 || month > 12) {
                        std::cout << "Invalid month! Must be 1-12. Try again." << std::endl;
                        continue;
                    }
                    // Controllo giorno valido
                    date.SetYear(year);
                    int maxday = date.DaysAvailable(month,year);
                    if (day<1 || day>maxday) {
                        std::cout << "Invalid day for this month! Try again." << std::endl;
                        continue;
                    }
                    break;
                }while(true);

                date.SetDay(day);
                date.SetMonth(month);
                date.SetYear(year);
                Activity act(description,date);
                MyList.AddActivity(act);
                std::cout << "Activity added successfully." << std::endl;
                break;
            }
            case 3:{
                std::string description;
                std::cout << "Enter description of activity to remove: " << std::endl;
                std::cin.ignore();
                std::getline(std::cin,description);
                if(MyList.RemoveActivity(description)) {
                    std::cout << "Activity remove successfully." << std::endl;
                }else{
                    std::cout << "No activity found with that description." << std::endl;
                }
                break;
            }



        }
    }while(!stop);

    return 0;

};
