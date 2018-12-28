//clientguy

#include "BinarySearchTree.h"
#include "Exception.h"
#include <string>
#include <fstream>
using namespace std;

//opens an input file with a chosen name
//pre filename is assigned
//post if filename exists in the same directory as the program, it is opened
//      with its file pointer at the beginning of the file 
//      else an error message is printed
//usage OpenInputFile(infile, filename);
void OpenInputFile(ifstream& inputFile, string filename);

//prints an exception message
//pre except has been thrown
//post except is printed to the screen with two newlines before and after
//usage PrintExceptionMessage(except);
void PrintExceptionMessage(const Exception& except);

void printMenu();

void getOption(char& userOption);

bool isNotExit(char userOption);

void doOption();

int main()
{
	char userOption;
	
	printMenu();
	getOption(userOption);
	
	while(isNotExit(userOption))
	{
		doOption();
		printMenu();
		getOption();
	}

  
   return 0;
}

//opens an input file with a chosen name
//pre filename is assigned
//post if filename exists in the same directory as the program, it is opened
//      with its file pointer at the beginning of the file 
//      else an error message is printed
//usage OpenInputFile(infile, filename);
void OpenInputFile(ifstream& inputFile, string filename) 
{
   inputFile.open(filename);
   if (inputFile.fail())
   {
      cout << "File failed to open!!!!" << endl;
      exit(1);
   }
}

//prints an exception message
//pre except has been thrown
//post except is printed to the screen with two newlines before and after
//usage PrintExceptionMessage(except);
void PrintExceptionMessage(const Exception& except)
{
   cout << endl << endl;
   cout << except.What();
   cout << endl << endl;
}

void printMenu()
{
	cout << "--------------------------------------------------------------------------" << endl << endl;
	cout << "Your options are: " << endl << endl;
	cout << "f  : find the name of the contact, given her/his phone number" << endl;
	cout << "i  : insert a new item (phone number and name ) into the dictionary" << endl;
	cout << "l  : list the items in the entire dictionary on the screen in inorder fashion " << endl;
	cout << "p  : print the tree in pretty fashion (showing only the phone numbers) " << endl;
	cout << "r  : rebalance the tree   " << endl;
	cout << "s  : save the dictionary to the file in sorted order – inorder --  ready to be read " << endl;
	cout << "e  : exit the program which automatically does option s " << endl << endl;
	cout << "Enter your option > ";
}

void getOption(char& userOption)
{
	char newline;
	
	cin << userOption;
	cin << newLine;
}

bool isNotExit(char userOption)
{
	return (userChar != 'e');
}
 
void doOption()
{
}	