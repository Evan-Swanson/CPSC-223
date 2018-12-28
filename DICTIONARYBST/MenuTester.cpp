//MenuTester.cpp

#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

//prints the actions menu to the screen
//post: screen displays the menu
//usage: printMenu();
void printMenu();

//gets the user's option 
//post: userOption is assigned
//usage: getOption(userOption);
void getOption(char& userOption);

//finds if a user's input is not the exit command
//pre: userOption has been assigned
//post: returns true if userOption is not exit
//usage: isNotExit(userOption);
bool isNotExit(char userOption);

void doOption(char userOption, BinarySearchTree& myTree);

void PrintExceptionMessage(const Exception& except);

int main()
{
	BinarySearchTree myTree;
	char userOption;
	
	printMenu();
	getOption(userOption);
	
	while(isNotExit(userOption))
	{
		doOption(userOption, myTree);
		printMenu();
		getOption(userOption);
	}

  
   return 0;
}

//prints the actions menu to the screen
//post: screen displays the menu
//usage: printMenu();
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

//gets the user's option 
//post: userOption is assigned
//usage: getOption(userOption);
void getOption(char& userOption)
{
	cin >> userOption;
}

//finds if a user's input is not the exit command
//pre: userOption has been assigned
//post: returns true if userOption is not exit
//usage: isNotExit(userOption);
bool isNotExit(char userOption)
{
	return (userOption != 'e');
}
 
void doOption(char userOption, BinarySearchTree& myTree)
{
	if(userOption == 'f')
	{
		Key userKey;
		Item theItem;
		cout << "Enter the phone number you want to find (in the form 1234567) > " ;
		cin >> userKey;
		
		try
		{
		myTree.search(userKey, theItem);
		cout << "Contact Found: " << theItem << endl;
		}
		
		catch (Exception except)
		{
			PrintExceptionMessage(except);
		}
		
	}
}	

void PrintExceptionMessage(const Exception& except)
{
   cout << endl << endl;
   cout << except.What();
   cout << endl << endl;
}