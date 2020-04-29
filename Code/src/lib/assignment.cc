#include "assignment.h"

assignment::assignment(int i, std::string s, std::map<long int, student*> &students){

    id = i;
    name = s;

    std::cout << "Please enter the maximum credit for this assignment: ";
    std::cin >> max_credit;

    updateStudentCredits(students);

}

void assignment::updateStudentCredits(std::map<long int, student*> &students){

    if(students.size() != 0){

        std::cout << "Enter the grades of the following students out of:: " << max_credit << std::endl << std::endl;

        for(auto s : students){

            auto i = s.first;
            auto stu = s.second;
            int score;

            std::cout << "Student ID:" << i << "\t\tStudent Name: " << stu->name << "\t\tScore: ";
            std::cin >> score;

            studentCredits[i] = score;

            stu->assignmentsVec[id] = this;
            stu->assignmentScore[id] = {score, max_credit};
        }
    }

    return;
}


void assignment::removeStudents(long int i){

    studentCredits.erase(i);
    return;
}