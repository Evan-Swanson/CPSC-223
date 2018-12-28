// Clientprogram.cpp
//This program creates a dictionary of contacts that are input from a file and tests 
//various operations on the dictionary.

//Evan Swanson, Ryan Schoenlein
//Dropoff: eswanson2

#include <fstream>
#include <iostream>
#include "Item.h"
#include "Dictionary.h"
#include <cstdlib>

using namespace std;

//opens an input file named "Input.dat"
//pre: Input.dat file exists
//post: file has been opened
//usage: openInputFile(infile)
void openInputFile(ifstream& infile);

//inputs new contacts from a file into a dictionary
//pre: infile has been opened
//post: theDictionary contains the next numberContacts in the input file
//usage: inputNewContacts(infile, myDictionary, 3)
void inputNewContacts(ifstream& infile, Dictionary& theDictionary, int numberContacts);

//reads the next phone number in an input file
//pre: infile has been opened
//post: nextNumber contains the next phone number in the file
//usage: readNextPhoneNumber(infile, nextNumber)
void readNextPhoneNumber(ifstream& infile, Key& nextNumber);

//searchs the dictionary for a contact using a phone number
//pre: targetPhone has been assigned 
//post: if it is found, theItem contains the contact, theIndex contains the index and isFound is true, else isFound is false
//usage: searchForContact(myDictionary, targetPhone, theItem, isFound, theIndex)
void searchForContact(Dictionary& theDictionary, Key& targetPhone, Item& theItem, bool& isFound, int& theIndex);



int main()
{
	Dictionary myDictionary;
	ifstream infile;
	Item nextContact, foundItem;
	Key nextNumber;
	bool isFound, isDone;
	int theIndex;
	
	openInputFile(infile);
	infile >> myDictionary;
	cout << myDictionary;
	
	inputNewContacts(infile, myDictionary, 3);
	cout << myDictionary;
	
	readNextPhoneNumber(infile, nextNumber);
	searchForContact(myDictionary, nextNumber, foundItem, isFound, theIndex);
	
	readNextPhoneNumber(infile, nextNumber);
	searchForContact(myDictionary, nextNumber, foundItem, isFound, theIndex);
	
	readNextPhoneNumber(infile, nextNumber);
	myDictionary.remove(nextNumber, isDone);
	cout << myDictionary;
	
	readNextPhoneNumber(infile, nextNumber);
	searchForContact(myDictionary, nextNumber, foundItem, isFound, theIndex);
	
	return 0;
}

//opens an input file named "Input.dat"
//pre: Input.dat file exists
//post: file has been opened
//usage: openInputFile(infile)
void openInputFile(ifstream& infile)
{
	infile.open("Input.dat");
	if(infile.fail())
	{
		cout << "Error opening Input.dat " << endl;
		exit(1);
	}
}

//inputs new contacts from a file into a dictionary
//pre: infile has been opened
//post: theDictionary contains the next numberContacts in the input file
//usage: inputNewContacts(infile, myDictionary, 3)
void inputNewContacts(ifstream& infile, Dictionary& theDictionary, int numberContacts)
{
	Item nextContact;
	bool isFull;
	
	for(int k = 0; k < numberContacts; k++)
	{
		infile >> nextContact;
		theDictionary.insert(nextContact, isFull);
	}
}


//reads the next phone number in an input file
//pre: infile has been opened
//post: nextNumber contains the next phone number in the file
//usage: readNextPhoneNumber(infile, nextNumber)
void readNextPhoneNumber(ifstream& infile, Key& nextNumber)
{
	infile >> nextNumber;
}

//searchs the dictionary for a contact using a phone number
//pre: targetPhone has been assigned 
//post: if it is found, theItem contains the contact, theIndex contains the index and isFound is true, else isFound is false
//usage: searchForContact(myDictionary, targetPhone, theItem, isFound, theIndex)
void searchForContact(Dictionary& theDictionary, Key& targetPhone, Item& theItem, bool& isFound, int& theIndex)
{
	cout << endl << "Searching for number: " << targetPhone << endl;
	theDictionary.search(targetPhone, theItem, isFound, theIndex);
	if(isFound)
		cout << "Contact found: " << theItem << endl;
	else
		cout << "Contact not found" << endl;
}