#ifndef TEMPLATE_COURSE_H
#define TEMPLATE_COURSE_H

#include <iostream>
#include <string>
#include <vector>
#include "student.h"
#include "assignment.h"

class course{

    public:

    course();

    int courseMenu();

    std::string name;
    std::map<int, assignment*> assignments;

    void studentList();
    int studentListOperations(long int op);
    void printStudentOptions();
    void removeStudent(long int id);
    void assignmentList();
    void printAssignments();
    int assignmentListOperations(int op);
    void removeAssignment(int i);

    // MApping between student ID and the Stdent object
    std::map <long int, student*> studentData;

    private:

    int courseMenuOptions(const int op);
    


};

#endif