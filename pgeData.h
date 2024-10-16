#pragma once
//This file has the struct definition for PGE_Data
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

//constants and function prototypes
const int MAXCHAR = 101;

struct PGE_Data
{
  char bldgNames[MAXCHAR];
  int annConsump;
  int annCost;
};

//function prototypes
//loads data from a text file
bool loadData(PGE_Data list[], int &count);
//prints the data to the screen
void printData(const PGE_Data list[], int count);
//prints the updated data back to the text file
void printData(ofstream &outFile, const PGE_Data list[], int count);
//adds a new bldg to the list
void addData(PGE_Data list[], int &count);
//removes a bldg from the list
void removeData(PGE_Data list[], int &count, int index);
//validate index to delete
bool validateIndex(int index, int count);
//find a building and print information
void findBldg(const PGE_Data list[], int count);
//find the bldg with max consumption
void findMax(const PGE_Data list[], int count);

