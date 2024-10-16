#include "pgeData.h"
#include "tools.h"
//loads the building names first from annual.txt file
bool loadData(PGE_Data list[], int &count)
{
    ifstream infile;
    infile.open("PGE_data.txt");
    if(!infile)
    {
    	cout << "File did not open! Program Exiting!!!" << endl;
    	return false;
    }
  	infile.getline(list[count].bldgNames, MAXCHAR, ';');
    while(!infile.eof())
    {
      infile >> list[count].annConsump;
      infile.ignore(10, ';');
      infile >> list[count].annCost;
      infile.ignore(5, '\n');
      count++;
      infile.getline(list[count].bldgNames, MAXCHAR, ';');
    }
    infile.close();
    return true;
  }

//prints the data from the arrays
void printData(const PGE_Data list[], int count)
{
    for(int i = 0; i < count; i++)
    {
      cout << i << ": ";
    	cout << list[i].bldgNames << ';';
    	cout << list[i].annConsump << ';' << list[i].annCost << endl;
    }
  cout << endl;
}

//adds a line of information to the file
void addData(PGE_Data list[], int &count)
{
    cout << "Enter Building Name: ";
    cin.getline(list[count].bldgNames, MAXCHAR);
    readInt("Enter Annual Use: ", list[count].annConsump);
    readInt("Enter Annual Charge: ", list[count].annCost);
    count++;
}

//validate index to delete
bool validateIndex(int index, int count)
{
  if(index < count)
  {
    return true;
  }
  else
  {
    return false;
  }
}

//removes a building by index
void removeData(PGE_Data list[], int &count, int index)
{
  for(int i = index; i < count-1; i++)
    {
      list[i] = list[i + 1];
    }
  count--;
}

//finds a building with a given name - partial string search
void findBldg(const PGE_Data list[], int count)
{
    char aBldg[MAXCHAR];
    cout << "Enter building name to search for: ";
    cin.getline(aBldg, MAXCHAR);
    for(int i = 0; i < count; i++)
    {
    	if(strstr(list[i].bldgNames, aBldg) != NULL)
    	{
    	    cout << list[i].bldgNames << ';';
    	    cout << list[i].annConsump << ';' << list[i].annCost << endl;
    	    break;
      }
    }
}

//finds the building with the maximum usage
void findMax(const PGE_Data list[], int count)
{
    int maxUse = list[0].annConsump, maxIndex = 0;
    for(int i = 1; i < count; i++)
    {
    	if(list[i].annConsump > maxUse)
    	{
    	    maxUse = list[i].annConsump;
    	    maxIndex= i;
    	}
    }
    //print the values at maxIndex
    cout << list[maxIndex].bldgNames << ';';
    cout << list[maxIndex].annConsump << ';' << list[maxIndex].annCost << endl;
}

//prints the updated data back to the text file
void printData(ofstream &outFile, const PGE_Data list[], int count)
{
  outFile.open("PGE_data.txt");
  if(!outFile)
    {
    	cout << "File did not open! Program Exiting!!!" << endl;
    	return;
    }
    for(int i = 0; i < count; i++)
    {
    	outFile << list[i].bldgNames << ';';
    	outFile << list[i].annConsump << ';' << list[i].annCost << endl;
    }  
  outFile.close();
}
