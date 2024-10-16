#include "tools.h"

//display the menu to the user
void displayMenu()
{
  cout << "Pick an option from below: \n";
  cout << "(A)DD\n";
  cout << "(R)EMOVE\n";
  cout << "(P)RINT\n";
  cout << "(F)IND\n";
  cout << "(M)AX\n";
  cout << "(Q)UIT\n";
  cout << endl;
}

//read the option using a char array - cstring
void readOption(char *option)
{
  cin >> option;
  cin.ignore(100, '\n');
}

//exeOption to call the different functions.
void exeOption(PGE_Data list[], int &count, char *option)
{
  int index = 0;
  switch(toupper(option[0]))
  {
    case 'A':
        addData(list, count);
        break;
    case 'P':
        printData(list, count);
        break;
    case 'R':
        printData(list, count);
        readInt("Enter an index to remove a building: ", index);
        if(validateIndex(index, count))
        { 
          removeData(list, count, index);
        }
        else
        {
          cout << "Invalid index!!\n" << endl;
        }
        break;
    case 'F':
        findBldg(list, count);
        break;
    case 'M':
        findMax(list, count);
        break;
    case 'Q':
        return;
    default:
        cout << "Invalid Option!! Please try again!!!" << endl;
  }//end switch
}

//Name: 	readInt()
//Parameters: 	prompt c-string and an int by reference (note the & sign)
//Desc:		reads a number from the user and does data validation
//return:	None - void function, but number is already changed.

void readInt(const char prompt[], int &temp)
{
  cout << prompt;
  cin >> temp;
  while(!cin)
  {
    cout << "Invalid number! Please try again!!!" << endl;
    cin.clear();
    cin.ignore(100, '\n');
    cin >> temp;
  }
  //to ignore the line feed after the number entry by the user
  cin.ignore(5, '\n');
}


