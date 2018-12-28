//Clientprogram.cpp
//Evan Swanson, Ryan Schoenlein
// 3/26/18
// dropoff: eswanson2

//This program automatically creates a dictionary from an input file "dictionary.dat"
// and gives the user various options they want to perform on it, including adding, removing
// and searching for contacts, as well as rebalancing and saving the dictionary. 

#include <iostream>
#include "BinarySearchTree.h"
#include <fstream>
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

//opens an input file with the name "dictionary.dat"
//post if filename exists in the same directory as the program, it is opened
//      with its file pointer at the beginning of the file 
//      else an error message is printed
//usage openInputFile(infile);
void openInputFile(ifstream& infile);

//inputs data from a file into a dictionary
//pre: infile is not open, outfile is not open
//post: infile has bee closed, outfile has been close, myTree is assigned
//usage: inputDataFromFile(infile, outfile, myTree);
void inputDataFromFile(ifstream& infile, ofstream& outfile, BinarySearchTree& myTree);

//Performs the user selected option
//pre: userOption has been assigned, myTree has been assigned, outfile and infile are not open
//post: the user selected option has been done
//usage: (userOption, myTree, outfile, infile);
void doOption(char userOption, BinarySearchTree& myTree, ofstream& outfile, ifstream& infile);

//find the name of the contact, given her/his phone number
//pre: myTree has been assigned
//post: the screen dislays the found contact or an error message
//usage: doOptionF(myTree);
void doOptionF(BinarySearchTree& myTree);

//inserts a new item (phone number and name ) into the dictionary
//pre: myTree has been assigned
//post: the user-inputed contact has been inserted
//usage: doOptionI(myTree);
void doOptionI(BinarySearchTree& myTree);

//list the items in the entire dictionary on the screen in inorder fashion
//pre: myTree has been assigned
//post: the dictionary items are listed on screen, sorted by phone number
//usage: doOptionL(myTree);
void doOptionL(BinarySearchTree& myTree);

//print the tree in pretty fashion
//pre: myTree has been assigned
//post: the tree is displayed on screen
//usage: doOptionP(myTree);
void doOptionP(BinarySearchTree& myTree);

//rebalances the tree
//pre: myTree has been assigned, infile and outfile are not open
//post: the tree is now minimum height
//usage: doOptionR(myTree);
void doOptionR(BinarySearchTree& myTree, ifstream& infile, ofstream& outfile);

//save the dictionary to the file in sorted order – inorder --  ready to be read
//pre: myTree has been assigned, outfile is not open
//post: the tree has been saved to "dictionary.dat"
//usage: doOptionS(myTree);
void doOptionS(BinarySearchTree& myTree, ofstream& outfile);

//deletes a phone number and name from the dictionary
//pre: myTree has been assigned
//post: the user-inputed phone number has been deleted
//usage: doOptionD(myTree);
void doOptionD(BinarySearchTree& myTree);

//prints an exception message
//pre except has been thrown
//post except is printed to the screen with two newlines before and after
//usage PrintExceptionMessage(except);
void PrintExceptionMessage(const Exception& except);

int main()
{
	BinarySearchTree myTree;
	char userOption;
	ifstream infile;
	ofstream outfile;
	
	inputDataFromFile(infile, outfile, myTree);
	
	
	printMenu();
	getOption(userOption);
	
	while(isNotExit(userOption))
	{
		doOption(userOption, myTree, outfile, infile);
		printMenu();
		getOption(userOption);
	}

	doOptionS(myTree, outfile);
  
   return 0;
}

//prints the actions menu to the screen
//post: screen displays the menu
//usage: printMenu();
void printMenu()
{
	cout << "--------------------------------------------------------------------------" << endl << endl;
	cout << "Your options are: " << endl << endl;
	cout << "d  : deletes a phone number and name from the dictionary" << endl;
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
	char newLine;
	
	cin.get(userOption);
	cin.get(newLine);
}

//finds if a user's input is not the exit command
//pre: userOption has been assigned
//post: returns true if userOption is not exit
//usage: isNotExit(userOption);
bool isNotExit(char userOption)
{
	return (userOption != 'e');
}

//Performs the user selected option
//pre: userOption has been assigned, myTree has been assigned, outfile and infile are not open
//post: the user selected option has been done
//usage: (userOption, myTree, outfile, infile);
void doOption(char userOption, BinarySearchTree& myTree, ofstream& outfile, ifstream& infile)
{
	if(userOption == 'd')
	{
		doOptionD(myTree);
	}
	
	else if(userOption == 'f')
	{
		doOptionF(myTree);
	}
	
	else if(userOption == 'i')
	{
		doOptionI(myTree);
	}
	
	else if(userOption == 'l')
	{
		doOptionL(myTree);
	}
	
	else if(userOption == 'p')
	{
		doOptionP(myTree);
	}
	
	else if(userOption == 'r')
	{
		doOptionR(myTree, infile, outfile);
	}
	
	else if(userOption == 's')
	{
		doOptionS(myTree, outfile);
	}
}	

//find the name of the contact, given her/his phone number
//pre: myTree has been assigned
//post: the screen dislays the found contact or an error message
//usage: doOptionF(myTree);
void doOptionF(BinarySearchTree& myTree)
{
	Key userKey;
	Item theItem;
	cout << "Enter the phone number you want to find (in the form 1234567) > " ;
	cin >> userKey;
	
	try
	{
		myTree.search(userKey, theItem);
		cout << "*Contact Found: " << theItem << endl;
	}		
	catch (Exception except)
	{
		PrintExceptionMessage(except);
	}
}

//inserts a new item (phone number and name ) into the dictionary
//pre: myTree has been assigned
//post: the user-inputed contact has been inserted
//usage: doOptionI(myTree);
void doOptionI(BinarySearchTree& myTree)
{
	Item newItem;
	
	cout << "Enter the contact you wish to add (in the form: 1234567 first last) > ";
	cin >> newItem;
	
	try
	{
		myTree.insert(newItem);
		cout << "*Contact successfully inserted" << endl;
	}
	
	catch (Exception except)
	{
		PrintExceptionMessage(except);
	}
}

//list the items in the entire dictionary on the screen in inorder fashion
//pre: myTree has been assigned
//post: the dictionary items are listed on screen, sorted by phone number
//usage: doOptionL(myTree);
void doOptionL(BinarySearchTree& myTree)
{
	cout << endl;
	myTree.BinaryTree::inorderTraverse(cout);
}

//print the tree in pretty fashion
//pre: myTree has been assigned
//post: the tree is displayed on screen
//usage: doOptionP(myTree);
void doOptionP(BinarySearchTree& myTree)
{
	myTree.prettyDisplay();
}

//rebalances the tree
//pre: myTree has been assigned, infile and outfile are not open
//post: the tree is now minimum height
//usage: doOptionR(myTree);
void doOptionR(BinarySearchTree& myTree, ifstream& infile, ofstream& outfile)
{
	myTree.rebalance(infile, outfile);
}

//save the dictionary to the file in sorted order – inorder --  ready to be read
//pre: myTree has been assigned, outfile is not open
//post: the tree has been saved to "dictionary.dat"
//usage: doOptionS(myTree);
void doOptionS(BinarySearchTree& myTree, ofstream& outfile)
{
	outfile.open("dictionary.dat");
	myTree.inorderTraverse(outfile);
	outfile.close();
	cout << "*Dictionary saved" << endl;
}

//deletes a phone number and name from the dictionary
//pre: myTree has been assigned
//post: the user-inputed phone number has been deleted
//usage: doOptionD(myTree);
void doOptionD(BinarySearchTree& myTree)
{
	Key targetKey;
	
	cout << "Enter the phone number you wish to delete (in the form: 1234567) > ";
	cin >> targetKey;
	
	try
	{
		myTree.remove(targetKey);
		cout << "*Contact successfully removed" << endl;
	}
	
	catch (Exception except)
	{
		PrintExceptionMessage(except);
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

//opens an input file with the name "dictionary.dat"
//post if filename exists in the same directory as the program, it is opened
//      with its file pointer at the beginning of the file 
//      else an error message is printed
//usage openInputFile(infile);
void openInputFile(ifstream& infile)
{
	infile.open("dictionary.dat");
	if(infile.fail())
	{
		cout << "Error opening dictionary.dat " << endl;
		exit(1);
	}
}

//inputs data from a file into a dictionary
//pre: infile is not open, outfile is not open
//post: infile has bee closed, outfile has been close, myTree is assigned
//usage: inputDataFromFile(infile, outfile, myTree);
void inputDataFromFile(ifstream& infile, ofstream& outfile, BinarySearchTree& myTree)
{
	Item nextItem;
	char newLine;
	int numberOfItems;
	
	openInputFile(infile);
	
	infile >> numberOfItems;
	infile.get(newLine);
	
	for (int k = 0; k < numberOfItems; k++)
	{
		infile >> nextItem;
		myTree.insert(nextItem);
	}
	infile.close();
	
	myTree.rebalance(infile, outfile);
}

