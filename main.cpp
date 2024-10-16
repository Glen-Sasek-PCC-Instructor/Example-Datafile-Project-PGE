/*This program reads Energy Consumption data from a file for PCC Buildings, and prints some statistical information. The data modeling is done using structs. A struct called PGE_Data is used to store building name, annual consumption and annual cost. The building name is a char array, annual consumption and cost are int data types. */

#include "tools.h"

//main
int main()
{
    PGE_Data list[CAP];
    int count = 0;
    char option[MAXCHAR];
    ofstream outFile;
    //load the data from the files first. 
    //First load the building names from the building.txt file
    if(!loadData(list, count))
    {
      return 0;
    }
    cout << "Count  = " << count << endl;
    do
    {
    	displayMenu();
    	readOption(option);
    	exeOption(list, count, option);
    }while(strcmp(option, "QUIT") != 0 && strcmp(option, "Q") != 0 && strcmp(option, "q") != 0);
    printData(outFile, list, count);
    return 0;
}
