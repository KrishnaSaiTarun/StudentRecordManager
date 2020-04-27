#include "studentRecordManager.h"

studentRecordManager::studentRecordManager(){}

void studentRecordManager::start(){

  int option; 
  
  // Initialize the ncurses library!
  //initscr();

  while(1){

    //break;

    // PRINT THE MAIN MENU
      menu();

    // READ THE USER INPUT
      std::cin >> option;

      std::cout << std::endl;

      int status = optionManager(option);

      if(status) break;

    }

    //getch();
    //endwin();

    return;
}

int studentRecordManager::optionManager(const int option){

  if(option == 4) return 1;

  if(option != 1 && option != 2 && option != 3){

    std::cout << "The entered option does not exist! Please choose a valid option from the menu.." << std::endl << std::endl;
    return 0;
  }

  if(option == 1){
    
    prof.operations();
  }

  else if(option == 2){

    course* newCourse = new course();
    prof.addCourse(newCourse);
  }

  else if(option == 3){
    prof.courseOperations();
  }

  return 0;
}

