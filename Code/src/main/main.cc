#include <iostream>
#include "src/lib/studentRecordManager.h"
//#include "src/lib/menu.h"

int main()
{
    //initscr();
    std::system("clear");
    
    studentRecordManager s;
    s.start();

    //endwin();

    return EXIT_SUCCESS;
}