#include "course.h"

course::course(){

    std::cout << "Enter the name of the new course: ";
    std::cin >> name;

    std::system("clear");

};

int course::courseMenu(){

    while(1){

        //std::system("clear");

        std::cout << "The following operations are available under course:: " << name << std::endl << std::endl;

        std::cout << "1 --> Access / Edit the student list.\n";
        std::cout << "2 --> Access / Edit Assignments.\n";
        std::cout << "3 --> Show Grade Statistics for this course.\n";
        std::cout << "4 --> Back to the List of Available Courses.\n";
        std::cout << "5 --> Back to the Main Menu\n\n";

        std::cout << "Enter the option:: ";

        int op = -1;

        std::cin >> op;
        int status = courseMenuOptions(op);

        if(status == 4 || status == 5) return status;

        if(status == -1) continue;

        if(status == 1){

            studentList();
            std::system("clear");
            continue;
        }

        if(status == 2){

            assignmentList();
            std::system("clear");
            continue;
        }

        if(status == 3){

            courseStats();
            //std::system("clear");
            continue;
        }

        return 1;
    }

    // NEED TO DO THINGS HERE!!!!!!

    return 1;

}

void course::courseStats(){

    if(assignments.size() == 0){

        std::cout << "NOTE::The course does not have any assignments for statistics..\n\n";
        return;
    }

    float overallTotal = 0;
    std::vector<float> allMeans;
    float mean = 0;
    float median = 0;

    for(auto a : assignments){

        int i = a.first;
        auto as = a.second;

        auto x = assignmentStats(i);

        overallTotal += (as->max_credit * as->percent / 100);
        allMeans.push_back(x.first * as->percent / 100);
        mean+= (x.first * as->percent / 100);
        median+= (x.second * as->percent / 100);
    }

    //float mean = std::accumulate(allMeans.begin(), allMeans.end(), 0)/ allMeans.size();

    //float median = 0;
    // std::sort(allMeans.begin(), allMeans.end());

    // int n = allMeans.size();

    // if(n % 2 == 0){

    //     median = (allMeans[(n/2)-1] + allMeans[n/2]) / 2;
    // }

    // else median = allMeans[(n-1)/2];

    std::cout << "Overall Course creits completd: " << overallTotal <<  std::endl;
    std::cout << "Overall Mean: " << mean << std::endl;
    std::cout << "Overall Median: " << median << std::endl << std::endl;

    std::cout << "Press any key to go back!\n";
    char c;
    std::cin >> c;
    std::system("clear");

    return;
}

std::pair<float, float> course::assignmentStats(int i){

    auto as = assignments[i];

    std::cout << "Assignment ID: " << i << "\t\t\tAssignment Name: " << as->name << std::endl;

    float mean = as->calcMean();
    std::cout << "Maximum Credit: " << as->max_credit << std::endl;
    std::cout << "Overall weightage for the final score: " << as->percent << std::endl;
    std::cout << "Mean Score of the class: " << mean << std::endl;
    float median = as->calcMedian();
    std::cout << "Median of the class is: " << median << std::endl << std::endl;

    return {mean, median};
}



int course::courseMenuOptions(const int op){

    std::system("clear");

    if(op == 4 || op == 5) {
        return op;
    }

    if(op <= 0 || op > 5){
        std::cout << "ERROR:: Pleae choose a valid option from the menu below..\n\n";
        return -1;
    }

    return op;
}

void course::studentList(){

    while(1){

        printStudentOptions();

        std::cout << "\nEnter a Student ID for further information or Choose other options:: ";
        long int op = -1;
        std::cin >> op;

        int status = studentListOperations(op);

        if(status == -1) continue;
        if(status == 1) break;

    }
    return;



}

void course::printStudentOptions(){

    if(studentData.size() == 0){

        std::cout << "The student list is empty!\n";
    }

    else{

        std::cout << "Student ID\t\t\t\tStudent Name\n\n";

        for(auto m : studentData){

            auto id = m.first;
            auto stu = m.second;

            std::cout << id << "\t\t\t\t\t" << stu->name << std::endl;

        }

    }

    std::cout << "\nOther operations:\n\n";
    std::cout << "1 --> Add a new student\n";
    std::cout << "2 --> Remove a student\n";
    std::cout << "3 --> Go back to the course home!\n";
    return;

    //Other options to be added

}

int course::studentListOperations(long int op){

    std::system("clear");

    if(op == 1){

        long int id;
        std::string name;

        std::cout << "Enter the student ID: ";
        std::cin >> id;

        if(studentData.find(id) != studentData.end()){

            std::system("clear");
            std::cout << "The student ID entered already exists!\n\n";
            return -1;
        }

        if(id == 1 || id == 2 || id == 3){

            std::system("clear");
            std::cout << "ERROR: This ID is not permitted to be used as an ID\n";
            return -1;           
        }

        std::cout << "Enter the student Name: ";
        std::cin >> name;

        
        student* newStudent = new student(id, name, assignments);

        studentData[id] = newStudent;

        std::system("clear");
        std::cout << "SUCCESS: A new student has been added successfully!\n\n";
        return -1;

    }

    if(op == 2){

        long int id;
        std::cout << "Enter the student ID of the student you want to remove: ";
        std::cin >> id;

        if(studentData.find(id) == studentData.end()){

            std::system("clear");
            std::cout << "ERROR: The entere student ID does not exist in the database!\n";
            return -1;
        }

        removeStudent(id);
        std::system("clear");
        std::cout << "SUCCESS: Stduent removed successfully!\n";
        return -1;
    }

    if(op == 3) return 1;

    if(studentData.find(op) != studentData.end()){

        auto stu = studentData[op];
        stu->insideStuOps();
    }

    else{

        std::cout << "ERROR:: INVALID ENTRY!\n";
    }

    return -1;

}

void course::removeStudent(long int id){

    student* stu = studentData[id];
    studentData.erase(id);

    for(auto a : assignments){

        auto as = a.second;

        as->removeStudents(id);
    }

    delete stu;
    stu = NULL;
    return;
}

void course::assignmentList(){

    while(1){

        printAssignments();

        std::cout << "\nEnter an assignment ID for further information or Choose other options:: ";
        int op = -1;
        std::cin >> op;

        int status = assignmentListOperations(op);

        if(status == -1) continue;
        if(status == 1) break;

    }

    return;
}

void course::printAssignments(){

    if(assignments.size() == 0){

        std::cout << "The assignment list is empty.\n\n";
    }

    else{

        std::cout << "The following assignments are available:\n\n";
        std::cout << "Assignment ID\t\t\tAssignment Name\n";

        for(auto a : assignments){

            auto i = a.first;
            auto as = a.second;

            std::cout << i << "\t\t\t\t" << as->name << std::endl;

        }
    }

    std::cout << "\nOther operations:\n\n";
    std::cout << "1 --> Add a new Assignment\n";
    std::cout << "2 --> Remove an assignment\n";
    std::cout << "3 --> Go back to the course home!\n";

    return;
}

int course::assignmentListOperations(int op){

    std::system("clear");

    if(op == 1){

        int id;
        std::string name;

        std::cout << "Enter the assignment ID: ";
        std::cin >> id;

        if(assignments.find(id) != assignments.end()){

            std::system("clear");
            std::cout << "ERROR: The assignment ID entered already exists!\n\n";
            return -1;
        }
        
        if(id == 1 || id == 2 || id == 3){

            std::system("clear");
            std::cout << "ERROR: This ID is not permitted to be used as an assignment ID\n";
            return -1;           
        }


        std::cout << "Enter the assignment Name: ";
        std::cin >> name;

        assignment* newAssignment = new assignment(id, name, studentData);

        assignments[id] = newAssignment;

        std::system("clear");
        std::cout << "SUCCESS: A new assignment has been created successfully!\n\n";
        return -1;

    }

    if(op == 2){

        long int id;
        std::cout << "Enter the ID of the assignment you want to remove: ";
        std::cin >> id;


        if(assignments.find(id) != assignments.end()){

            removeAssignment(id);

            std::system("clear");
            std::cout << "SUCCESS: Assesment removed successfully!\n";
            return -1;
        }

        

        std::system("clear");
        std::cout << "ERROR: The entered assesment ID does not exist in the database!\n";
        return -1;

    }

    if(op == 3) return 1;

    if(assignments.find(op) != assignments.end()){

        auto x = assignmentStats(op);
        std::cout << "\nPress any key to go back::";
        char c;
        std::cin >> c;
        std::system("clear");
    }

    return -1;

}

void course::removeAssignment(int i){

    // for(auto it = assignments.begin(); it!= assignments.end(); it++){

    //     if(*it == a){

    //         assignments.erase(it);
    //         break;
    //     }
    // }
    auto as = assignments[i];
    assignments.erase(i);

    for(auto s : studentData){

        auto stu = s.second;

        // for(auto it = stu->assignmentsVec.begin(); it != stu->assignmentsVec.end(); it++){

        //     if(*it == a){
        //         stu->assignmentsVec.erase(it);
        //         break;
        //     }
        // }

        stu->removeAssignment(i);
    }

    delete as;
    as = NULL;
    return;
}

