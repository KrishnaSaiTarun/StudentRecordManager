#include "instructor.h"

instructor::instructor(){

    name = "";
    id = "";
}

void instructor::operations(){

    int op = -1;

    while(1){

        printMenu();

        std::cin >> op;

        int status = furtherActions(op);
        if(status) break;
    }
    
    return;
}

void instructor::printMenu(){

    if(name == ""){

        std::cout << "There is currently no instructor!" << std::endl << std::endl;

    }

    else{

        std::cout << "Instructor's name: " << name << std::endl;
        std::cout << "Instructor's ID: " << id << std::endl << std::endl;
        std::cout << "The courses taken by the instructor are:: ";

        if(courses.size() == 0){

            std::cout << "{The course List is Empty}" << std::endl << std::endl;
        }
        else{

            std::cout << "{\t";

            for(auto x : courses){

                std::cout << x->name << "\t";

            }

            std::cout << "}\n\n";
        }
    }

    std::cout << "Choose further operations if required::" << std::endl;
    std::cout << "1--> Edit/Add Instrctor" << std::endl;
    std::cout << "2--> Return to the Main Menu" << std::endl;
    std::cout << "Enter the option:: ";
}

int instructor::furtherActions(const int op){

    if(op == 2) {

        std::system("clear");
        return 1;
    }

    if(op != 1){

        std::system("clear");
        std::cout << "Invalid option. Please choose a valid option.." << std::endl <<std::endl;
        //printMenu();
        return 0;
    }

    addInstructor();
    return 0;

    

}

void instructor::addInstructor(){

    eraseData();
    std::system("clear");

    while(1){

        std::cout << "Enter the instructor Name: ";
        std::cin >> name;

        if(name == ""){

            std::system("clear");

            std::cout << "Please enter some text!\n" << std::endl;
        }

        else break;
    }

    while(1){

        std::cout << "Enter the instructor ID: ";
        std::cin >> id;

        if(id == ""){

            //std::system("clear");

            std::cout << "Please enter a valid ID!\n" << std::endl;
        }

        else break;
    }

    std::system("clear");

    //std::cout << std::endl << std::endl;
    return;
}

void instructor::eraseData(){

    name = "";
    id = "";
    return;
}

void instructor::addCourse(course* newCourse){

    courses.push_back(newCourse);
}

void instructor::courseOperations(){

    int i;

    while(1){

        std::cout << "The available courses are::\n " << std::endl;

        i = 1;
        for(auto x : courses){

            std::cout << i << ": " << x->name << std::endl;
            i++;

        }

        std::cout << i << ": " "Return to the main menu." << std::endl;

        std::cout << "Enter the option:: ";

        int op = -1;
        std::cin >> op;

        if(op == i){

            std::system("clear");
            return;
        }

        int status = courseOperationsHelper(op, i);

        i = op;
        if(status) break;

    }

    // MAYBE WHILE AGAIN HERE

    courses[i-1]->courseMenu();
    

}

int instructor::courseOperationsHelper(const int op, const int i){

    if(op > i || op <= 0){

        std::system("clear");
        std::cout << "\nPlease enter a valid option.\n";
        //instructor::courseOperations();
        return 0;
    }        
    
    return 1;    
}