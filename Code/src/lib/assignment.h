#ifndef TEMPLATE_ASSIGNMENT_H
#define TEMPLATE_ASSIGNMENT_H

#include <map>
#include <string>
#include "student.h"

class student;

class assignment{

    public: 

        assignment(int i, std::string s, std::map<long int, student*> &students);

        int max_credit;
        std::map<long int, int> studentCredits;
        std::string name;
        int id;


        void updateStudentCredits(std::map<long int, student*> &students);
        void removeStudents(long int i);
};

#endif