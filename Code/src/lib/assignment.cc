#include "assignment.h"

assignment::assignment(int i, std::string s, std::map<long int, student*> &students){

    id = i;
    name = s;

    std::cout << "Please enter the maximum credit for this assignment: ";
    std::cin >> max_credit;
    std::cout << "Please enter the percentage of this course for the final grade: ";
    std::cin >> percent;

    updateStudentCredits(students);

}

void assignment::updateStudentCredits(std::map<long int, student*> &students){

    if(students.size() != 0){

        std::cout << "\nEnter the grades of the following students out of:: " << max_credit << std::endl << std::endl;

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

float assignment::calcMean(){

    int sum = 0;

    for(auto g : studentCredits){

        int marks = g.second;
        sum += marks;
    }

    return sum/studentCredits.size();
}

float assignment::calcMedian(){

    std::vector<int> scores;

    for(auto g : studentCredits){

        scores.push_back(g.second);
    }

    std::sort(scores.begin(), scores.end());

    int n = scores.size();

    if(n % 2 == 0){

        return (scores[(n/2)-1] + scores[n/2]) / 2;
    }

    else return scores[(n-1)/2];

}

void assignment::changeScore(long int i, int score){

    studentCredits.erase(i);
    studentCredits[i] = score;
}