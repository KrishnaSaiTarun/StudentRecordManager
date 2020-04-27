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
    }

    std::cout << "Choose further operations if required::" << std::endl;
    std::cout << "1--> Edit/Add Instrctor" << std::endl;
    std::cout << "2--> Return to the Main Menu" << std::endl;
}

int instructor::furtherActions(const int op){

    if(op == 2) return 1;

    if(op != 1){

        std::cout << "Invalid option. Please choose a valid option.." << std::endl <<std::endl;
        //printMenu();
        return 0;
    }

    addInstructor();
    return 0;

    

}

void instructor::addInstructor(){

    eraseData();

    std::cout << "Enter the instructor Name: ";
    std::cin >> name;
    std::cout << "\nEnter the instructor ID: ";
    std::cin >> id;
    std::cout << std::endl << std::endl;
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

    std::cout << "The available courses are: " << std::endl;

    int i = 1;
    for(auto x : courses){

        std::cout << i << ": " << x->name << std::endl;
        i++;

    }
}