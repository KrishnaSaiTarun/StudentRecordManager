#ifndef TEMPLATE_STUDENTRECORDMANAGER_H
#define TEMPLATE_STUDENTRECORDMANAGER_H

//#include <cstdlib.h>
#include <ncurses.h>
#include "src/lib/menu.h"
#include "src/lib/instructor.h"
#include <iostream>
#include <vector>

class studentRecordManager {

  public:
    
    studentRecordManager();
    void start();

    instructor* prof;

  private: 

    int optionManager(const int option);
};

#endif