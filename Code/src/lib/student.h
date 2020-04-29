#ifndef TEMPLATE_STUDENT_H
#define TEMPLATE_STUDENT_H

#include <string>
#include <vector>
#include <map>
#include "assignment.h"
#include <iostream>

class assignment;

class student{

    public: 

        student(long int i, std::string s, std::map<int, assignment*> &assign);

        void newStudentGrades();
        void removeAssignment(int a);

        long int id;
        std::string name;
        std::map<int, assignment*> assignmentsVec;
        std::map<int, std::pair<int, int>> assignmentScore;
};


#endif