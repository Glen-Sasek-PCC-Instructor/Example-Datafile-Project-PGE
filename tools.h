#pragma once

#include "pgeData.h"

//constants
const int CAP = 20;

//function prototypes
void displayMenu();
void readOption(char *option);
void exeOption(PGE_Data list[], int &count, char *option);
void readInt(const char prompt[], int &temp);
