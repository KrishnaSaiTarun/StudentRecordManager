#include "course.h"

course::course(){

    std::cout << "Enter the name of the new course: ";
    std::cin >> name;

    std::system("clear");

};

void course::courseMenu(){

    std::system("clear");

    std::cout << "The following operations are available under course:: " << name << std::endl << std::endl;

    std::cout << "1 --> Access / Edit the student list.\n";
    std::cout << "2 --> Access / Edit Assignments.\n";
    std::cout << "3 --> Show Grade Statistics for this course.\n";
    std::cout << "4 --> Back to the List of Available Courses.\n";
    std::cout << "5 --> Back to the Main Menu\n\n";

    std::cout << "Enter the option:: ";

    int op = -1;

    std::cin >> op;

    std::system("clear");

    // NEED TO DO THINGS HERE!!!!!!

    return;

}

    //std::string name;
    //std::vector<assignment*> assignments;