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
    std::cout << "4) Modify an Activity (date or description)." << std::endl;
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
                if(MyList.RemoveActivity(description))
                    std::cout << "Activity removed successfully." << std::endl;
                else
                    std::cout << "No activity found with that description." << std::endl;
                break;
            }
            case 4: {
                std::string description,NewDescription;
                int day, month, year;
                Date newDate;
                char choice;

                std::cout << "Enter description of activity to modify: ";
                std::cin.ignore();
                std::getline(std::cin,description);
                std::cout << "What do you want to modify?" <<std::endl;
                std::cout << "a) Description or b) Date" <<std::endl;
                std::cout << "Choose option: ";
                std::cin >> choice;

                if (choice == 'a') {
                    std::cout << "Enter new description: ";
                    std::cin.ignore();
                    std::getline(std::cin,NewDescription);
                    MyList.ModifyActDescription(description,NewDescription);
                    std::cout << "Description modified successfully." << std::endl;
                }
                else if(choice == 'b'){
                    do {
                        std::cout << "Enter new date (day month year): ";
                        std::cin >> day >> month >> year;
                        std::cin.ignore();
                        if (month < 1 || month > 12) {
                            std::cout << "Invalid month! Must be 1-12. Try again." << std::endl;
                            continue;
                        }

                        newDate.SetYear(year);
                        int maxDay = newDate.DaysAvailable(month, year);
                        if (day < 1 || day > maxDay) {
                            std::cout << "Invalid day for this month! Try again." << std::endl;
                            continue;
                        }
                        break;
                    } while (true);

                    newDate.SetDay(day);
                    newDate.SetMonth(month);
                    newDate.SetYear(year);
                    MyList.ModifyActDate(description,newDate);
                    std::cout << "Date modified successfully." << std::endl;
                }
                else {
                    std::cout << "Invalid option." << std::endl;
                }
                break;
            }
            case 5: {
                std::string description;
                std::cout << "Enter description of activity to mark as completed: ";
                std::cin.ignore();
                std::getline(std::cin,description);
                if(MyList.SetActivityComplete(description))
                    std::cout << "Mark as completed successfully" << std::endl;
                else
                    std::cout << "No activity found with that description." << std::endl;
                break;
            }
            case 6: {
                std::string description;
                std::cout << "Enter description of activity to mark as not completed: ";
                std::cin.ignore();
                std::getline(std::cin, description);
                if(MyList.SetActivityUnComplete(description))
                    std::cout << "Mark as uncompleted successfully" << std::endl;
                else
                    std::cout << "No activity found with that description." << std::endl;
                break;
            }
            case 7:{
                MyList.PrintAllActivity();
                break;
            }
            case 8:{
                MyList.PrintCompletedActivities();
                break;
            }
            case 9:{
                MyList.PrintUnCompleteActivities();
                break;
            }
            case 10:{
                std::string description;
                bool found=false;
                std::cout << "Enter description of activity to check: ";
                std::cin.ignore();
                std::getline(std::cin, description);
                if (MyList.CheckActivity(description,found))
                    std::cout << "Activity: " << description << " is completed." << std::endl;
                else
                    if(found==true)
                        std::cout << "Activity: " << description << " is NOT completed." << std::endl;
                    else
                        std::cout << "Activity not found!!" << std::endl;
                break;
            }
            case 11:{
                std::string filename;
                std::cout << "Enter filename to save: ";
                std::cin.ignore();
                std::getline(std::cin,filename);
                if (MyList.SaveToFile(filename))
                    std::cout << "Activities saved successfully." <<std::endl;
                else
                    std::cout << "Error saving file." <<std::endl;
                break;
            }

            case 12: {
                std::string filename;
                std::cout << "Enter filename to load: ";
                std::cin.ignore();
                std::getline(std::cin, filename);
                if (MyList.LoadToFile(filename))
                    std::cout << "Activities loaded successfully." <<std::endl;
                else
                    std::cout << "Error loading file." <<std::endl;
                break;
            }
            default:
                std::cout << "Invalid option please choose a number between ( 1 / 12 )" << std::endl;
        }
    }while(!stop);

    return 0;

};
