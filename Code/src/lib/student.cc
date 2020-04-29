#include "student.h"

student::student(long int i, std::string s, std::map<int, assignment*> &assign){

    //std::cout << "DEBUG:: I CAME HERE!\n\n";
    id = i;
    name = s;
    assignmentsVec = assign;
    //std::cout << "DEBUG:: I CAME HERE!\n\n";
    newStudentGrades();

}

void student::newStudentGrades(){

    if(assignmentsVec.size() != 0){

        std::cout << "Please enter the gardes for this student for the following assignments:\n";

        for(auto a : assignmentsVec){

            auto i = a.first;
            auto as = a.second;

        int score = 0;

        std::cout << "\nAssignment: " << i << "\t\tAssignment Name: " << as->name << std::endl;
        std::cout << "Max Credit = " << as->max_credit << std::endl;
        std::cout << "Student score: ";
        std::cin >> score;

        std::pair<int, int> grade = {score, as->max_credit};

        assignmentScore[i] = grade;

        } 
    }

    return;
}

void student::removeAssignment(int a){

    assignmentsVec.erase(a);
    //auto i = a->id;
    assignmentScore.erase(a);
}

