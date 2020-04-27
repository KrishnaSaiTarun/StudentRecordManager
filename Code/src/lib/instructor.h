#ifndef TEMPLATE_INSTRUCTOR_H
#define TEMPLATE_INSTRUCTOR_H

#include <iostream>
#include <string>
#include <vector>
#include "course.h"

class instructor{

    public:

    std::string name;
    //std::vector<std::string> courses;
    std::string id;

    instructor();

    void operations();
    void addCourse(course* newCourse);
    void courseOperations();

    std::vector<course*> courses;

    private:

        void printMenu();
        int furtherActions(const int op);
        void addInstructor();
        void eraseData();
    
};

#endif