#include "BinarySearchTree.h"
#include <fstream>
#include <iostream>

using namespace std;

void PrintExceptionMessage(const Exception& except);

int main()
{
	BinarySearchTree testTree;
	ifstream infile;
	ofstream outfile;
	Item testItem;
	
	infile.open("dictionary.dat");
	if(infile.fail())
	{
		cout << "Error opening Input.dat " << endl;
		exit(1);
	}
	
	//testing insert
	Item nextItem;
	char newLine;
	int numberOfItems;
	
	infile >> numberOfItems;
	infile.get(newLine);
	
	for (int k = 0; k < numberOfItems; k++)
	{
		infile >> nextItem;
		try
		{
		testTree.insert(nextItem);
		}
	
		 catch (Exception except)
		{
			PrintExceptionMessage(except);
		}
		
	}
	
	infile.close();
	
	testTree.rebalance(infile, outfile);
	
	testTree.prettyDisplay();
	
	cout << endl << "Testing insert on existing contact" << endl;
	
	try
	{
	testTree.insert(nextItem);
	}
	
   catch (Exception except)
   {
      PrintExceptionMessage(except);
   }
   
   
   //testing search
   cout << "testing search (expected outcome: 2222222 bill johnson)" << endl;
   Key testKey("2222222");
   Item foundItem;
   
   	try
	{
		testTree.search(testKey, foundItem);
		cout << "the found item is: " << foundItem;
	}
	
   
   catch (Exception except)
   {
      PrintExceptionMessage(except);
   }
   
   cout << endl << "testing search on nonexistant item: " << endl;
   
   Key aKey("1212121");
   
	try
	{
		testTree.search(aKey, foundItem);
	}
	
   catch (Exception except)
   {
      PrintExceptionMessage(except);
   }
   

   //testing rebalance
   cout << endl << "testing rebalance: " << endl;
   testTree.rebalance(infile, outfile);
   testTree.prettyDisplay();
	
	
	return 0;
}

void PrintExceptionMessage(const Exception& except)
{
   cout << endl << endl;
   cout << except.What();
   cout << endl << endl;
}