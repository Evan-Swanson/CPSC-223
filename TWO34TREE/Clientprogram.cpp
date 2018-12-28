//Tests all cases of Two34Tree's insert
//Evan Swanson, Ryan Schoenlein
//5/3/18
//dropoff: eswanson2

#include "Two34Tree.h"
#include <iostream>
#include <fstream>
#include "Exception.h"

void openInputFile(ifstream& infile);
void inputItems(ifstream& infile, Two34Tree& theTree, int numberOfItems);
void testCase1(ifstream& infile, ofstream& outfile);
void testCase2(ifstream& infile, ofstream& outfile);
void testCase3(ifstream& infile, ofstream& outfile);
void testCase4(ifstream& infile, ofstream& outfile);
void testCase5(ifstream& infile, ofstream& outfile);
void testCase6(ifstream& infile, ofstream& outfile);

using namespace std;

int main()
{
	Two34Tree myTree;
	ofstream outfile;
	ifstream infile;
	
	openInputFile(infile);
	outfile.open("Two.dat");
	
	testCase1(infile, outfile);
	testCase2(infile, outfile);
	testCase3(infile, outfile);
	testCase4(infile, outfile);
	testCase5(infile, outfile);
	testCase6(infile, outfile);
	
	myTree.display(outfile, 'i');
	
	return 0;
}


//opens an input file with the name "dictionary.dat"
//post if filename exists in the same directory as the program, it is opened
//      with its file pointer at the beginning of the file 
//      else an error message is printed
//usage openInputFile(infile);
void openInputFile(ifstream& infile)
{
	infile.open("in8.dat");
	if(infile.fail())
	{
		cout << "Error opening dictionary.dat " << endl;
		exit(1);
	}
}

//inputs items into an AVLTree
//pre: infile has been opened
//post: the next numberOfItems items from the infile have been inserted into the tree
//usage: inputItems(infile, myTree, 3);
void inputItems(ifstream& infile, Two34Tree& theTree, int numberOfItems)
{
	Key nextItem;
	
	for(int k = 0; k < numberOfItems; k++)
	{
		infile >> nextItem;
		theTree.insert(nextItem);
	}
}

void testCase1(ifstream& infile, ofstream& outfile)
{
	Two34Tree caseOneTree;
	Two34Tree caseOneTree2;
	Two34Tree caseOneTree3;
	Two34Tree caseOneTree4;
	Two34Tree caseOneTree5;
	
	outfile << endl << "-------------CASE OF INSERTING INTO ROOT WITH NO SPLITTING -----------" << endl;
	
	//Case 1: empty tree
	outfile  << endl << "Test1: CASE OF EMPTY TREE" << endl;
	outfile << endl << "Pre: " << endl << endl;
	caseOneTree.display(outfile, 'p');
	outfile << endl << "*Inserting 10" << endl << endl;
	outfile << endl << "Post: " << endl << endl;
	inputItems(infile, caseOneTree, 1);
	caseOneTree.display(outfile, 'p');
	
	//Case 2: 
	outfile  << endl << "Test2: CASE OF ROOT WITH SINGLE ITEM" << endl;
	outfile << endl << "Pre: " << endl << endl;
	caseOneTree.display(outfile, 'p');
	outfile << endl << "*Inserting 30" << endl << endl;
	outfile << endl << "Post: " << endl << endl;
	inputItems(infile, caseOneTree, 1);
	caseOneTree.display(outfile, 'p');
	
	//Case 2: 
	outfile  << endl << "Test3: CASE OF ROOT WITH TWO ITEMS" << endl;
	outfile << endl << "Pre: " << endl << endl;
	caseOneTree.display(outfile, 'p');
	outfile << endl << "*Inserting 60" << endl << endl;
	outfile << endl << "Post: " << endl << endl;
	inputItems(infile, caseOneTree, 1);
	caseOneTree.display(outfile, 'p');
	
	//Case 2: 
	outfile  << endl << "Test4: CASE OF INSERTING SAME ITEMS, BUT IN THE ORDER: 10,60,30" << endl;
	outfile << endl << "Pre: " << endl << endl;
	caseOneTree2.display(outfile, 'p');
	outfile << endl << "*Inserting 10,60,30" << endl << endl;
	outfile << endl << "Post: " << endl << endl;
	inputItems(infile, caseOneTree2, 3);
	caseOneTree2.display(outfile, 'p');
	
	//Case 2: 
	outfile  << endl << "Test5: CASE OF INSERTING SAME ITEMS, BUT IN THE ORDER: 30,10,60" << endl;
	outfile << endl << "Pre: " << endl << endl;
	caseOneTree3.display(outfile, 'p');
	outfile << endl << "*Inserting 30,10,60" << endl << endl;
	outfile << endl << "Post: " << endl << endl;
	inputItems(infile, caseOneTree3, 3);
	caseOneTree3.display(outfile, 'p');
	
	//Case 2: 
	outfile  << endl << "Test6: CASE OF INSERTING SAME ITEMS, BUT IN THE ORDER: 30,60,10" << endl;
	outfile << endl << "Pre: " << endl << endl;
	caseOneTree4.display(outfile, 'p');
	outfile << endl << "*Inserting 30,60,10" << endl << endl;
	outfile << endl << "Post: " << endl << endl;
	inputItems(infile, caseOneTree4, 3);
	caseOneTree4.display(outfile, 'p');
	
	//CASE
	outfile  << endl << "Test7: CASE OF INSERTING SAME ITEMS, BUT IN THE ORDER: 60,10,30" << endl;
	outfile << endl << "Pre: " << endl << endl;
	caseOneTree5.display(outfile, 'p');
	outfile << endl << "*Inserting 60,10,30" << endl << endl;
	outfile << endl << "Post: " << endl << endl;
	inputItems(infile, caseOneTree5, 3);
	caseOneTree5.display(outfile, 'p');
	
	/*
	outfile << endl << "*Inserting 888" << endl << endl;
	inputItems(infile, caseOneTree, 1);
	outfile << "Post: " << endl << endl; 
	caseOneTree.prettyDisplay(outfile);
	*/
}

void testCase2(ifstream& infile, ofstream& outfile)
{
	Two34Tree caseOneTree;
	Two34Tree caseOneTree2;
	Two34Tree caseOneTree3;
	Two34Tree caseOneTree4;
	Two34Tree caseOneTree5;
	
	outfile << endl << "-------------CASE OF ROOT NODE SPLITTING -----------" << endl;
	
	//Case 1: empty tree
	outfile  << endl << "Test1: CASE OF ADDING TO LEFT SIDE, RIGHT SPOT" << endl;
	inputItems(infile, caseOneTree, 3);
	outfile << endl << "Pre: " << endl << endl;
	caseOneTree.display(outfile, 'p');
	outfile << endl << "*Inserting 20" << endl << endl;
	outfile << endl << "Post: " << endl << endl;
	inputItems(infile, caseOneTree, 1);
	caseOneTree.display(outfile, 'p');
	
	//Case 1: empty tree
	outfile  << endl << "Test2: CASE OF ADDING TO LEFT SIDE, LEFT SPOT" << endl;
	inputItems(infile, caseOneTree2, 3);
	outfile << endl << "Pre: " << endl << endl;
	caseOneTree2.display(outfile, 'p');
	outfile << endl << "*Inserting 5" << endl << endl;
	outfile << endl << "Post: " << endl << endl;
	inputItems(infile, caseOneTree2, 1);
	caseOneTree2.display(outfile, 'p');
	
	
	//Case 1: empty tree
	outfile  << endl << "Test3: CASE OF ADDING TO RIGHT SIDE, LEFT SPOT" << endl;
	inputItems(infile, caseOneTree3, 3);
	outfile << endl << "Pre: " << endl << endl;
	caseOneTree3.display(outfile, 'p');
	outfile << endl << "*Inserting 50" << endl << endl;
	outfile << endl << "Post: " << endl << endl;
	inputItems(infile, caseOneTree3, 1);
	caseOneTree3.display(outfile, 'p');
	
	//Case 1: empty tree
	outfile  << endl << "Test4: CASE OF ADDING TO RIGHT SIDE, RIGHT SPOT" << endl;
	inputItems(infile, caseOneTree4, 3);
	outfile << endl << "Pre: " << endl << endl;
	caseOneTree4.display(outfile, 'p');
	outfile << endl << "*Inserting 70" << endl << endl;
	outfile << endl << "Post: " << endl << endl;
	inputItems(infile, caseOneTree4, 1);
	caseOneTree4.display(outfile, 'p');
}


void testCase3(ifstream& infile, ofstream& outfile)
{
	Two34Tree caseOneTree;
	Two34Tree caseOneTree2;
	Two34Tree caseOneTree3;
	Two34Tree caseOneTree4;
	Two34Tree caseOneTree5;
	
	outfile << endl << "-------------CASE OF ADDING TO A LEVEL 2 NODE -----------" << endl;
	
	//Case 1: empty tree
	outfile  << endl << "Test1: CASE OF ADDING TO RIGHT SIDE" << endl;
	inputItems(infile, caseOneTree, 4);
	outfile << endl << "Pre: " << endl << endl;
	caseOneTree.display(outfile, 'p');
	outfile << endl << "*Inserting 40" << endl << endl;
	outfile << endl << "Post: " << endl << endl;
	inputItems(infile, caseOneTree, 1);
	caseOneTree.display(outfile, 'p');
	
	//Case 1: empty tree
	outfile  << endl << "Test2: CASE OF ADDING TO A NODE THAT MAKES IT FULL" << endl;
	outfile << endl << "Pre: " << endl << endl;
	caseOneTree.display(outfile, 'p');
	outfile << endl << "*Inserting 70" << endl << endl;
	outfile << endl << "Post: " << endl << endl;
	inputItems(infile, caseOneTree, 1);
	caseOneTree.display(outfile, 'p');
	
	//Case 1: empty tree
	outfile  << endl << "Test3: CASE OF ADDING TO LEFT SIDE" << endl;
	inputItems(infile, caseOneTree2, 4);
	outfile << endl << "Pre: " << endl << endl;
	caseOneTree2.display(outfile, 'p');
	outfile << endl << "*Inserting 25" << endl << endl;
	outfile << endl << "Post: " << endl << endl;
	inputItems(infile, caseOneTree2, 1);
	caseOneTree2.display(outfile, 'p');
	
}


void testCase4(ifstream& infile, ofstream& outfile)
{
	Two34Tree caseOneTree;
	Two34Tree caseOneTree2;
	Two34Tree caseOneTree3;
	Two34Tree caseOneTree4;
	Two34Tree caseOneTree5;
	
	outfile << endl << "-------------CASE OF SPLITTING A LEVEL 2 NODE -----------" << endl;
	
	//Case 1: empty tree
	outfile  << endl << "Test1: CASE OF ADDING INTO NEW RIGHT NODE" << endl;
	inputItems(infile, caseOneTree, 6);
	outfile << endl << "Pre: " << endl << endl;
	caseOneTree.display(outfile, 'p');
	outfile << endl << "*Inserting 70" << endl << endl;
	outfile << endl << "Post: " << endl << endl;
	inputItems(infile, caseOneTree, 1);
	caseOneTree.display(outfile, 'p');
	
	//Case 1: empty tree
	outfile  << endl << "Test2: CASE OF SPLITTING A RIGHT NODE AND THE ITEM GOES INTO MIDDLE" << endl;
	inputItems(infile, caseOneTree2, 6);
	outfile << endl << "Pre: " << endl << endl;
	caseOneTree2.display(outfile, 'p');
	outfile << endl << "*Inserting 45" << endl << endl;
	outfile << endl << "Post: " << endl << endl;
	inputItems(infile, caseOneTree2, 1);
	caseOneTree2.display(outfile, 'p');
	
	
	//Case 1: empty tree
	outfile  << endl << "Test3: CASE OF SPLITTING A LEFT NODE" << endl;
	inputItems(infile, caseOneTree3, 5);
	outfile << endl << "Pre: " << endl << endl;
	caseOneTree3.display(outfile, 'p');
	outfile << endl << "*Inserting 15" << endl << endl;
	outfile << endl << "Post: " << endl << endl;
	inputItems(infile, caseOneTree3, 1);
	caseOneTree3.display(outfile, 'p');
	
	//Case 1: empty tree
	outfile  << endl << "Test4: CASE OF SPLITTING A LEFT NODE AND NEW ITEM GOES INTO MIDDLE" << endl;
	inputItems(infile, caseOneTree4, 5);
	outfile << endl << "Pre: " << endl << endl;
	caseOneTree4.display(outfile, 'p');
	outfile << endl << "*Inserting 27" << endl << endl;
	outfile << endl << "Post: " << endl << endl;
	inputItems(infile, caseOneTree4, 1);
	caseOneTree4.display(outfile, 'p');
	
}

void testCase5(ifstream& infile, ofstream& outfile)
{
	Two34Tree caseOneTree;
	Two34Tree caseOneTree2;
	Two34Tree caseOneTree3;
	Two34Tree caseOneTree4;
	Two34Tree caseOneTree5;
	
	outfile << endl << "-------------ADDING TO A LEVEL 2 NODE AFTER A SPLIT -----------" << endl;
	
	//Case 1: empty tree
	outfile  << endl << "Test1: CASE OF ADDING INTO NEW RIGHT NODE" << endl;
	inputItems(infile, caseOneTree, 7);
	outfile << endl << "Pre: " << endl << endl;
	caseOneTree.display(outfile, 'p');
	outfile << endl << "*Inserting 80" << endl << endl;
	outfile << endl << "Post: " << endl << endl;
	inputItems(infile, caseOneTree, 1);
	caseOneTree.display(outfile, 'p');
	
	//Case 1: empty tree
	outfile  << endl << "Test2: CASE OF ADDING INTO LEFT NODE" << endl;
	outfile << endl << "Pre: " << endl << endl;
	caseOneTree.display(outfile, 'p');
	outfile << endl << "*Inserting 25" << endl << endl;
	outfile << endl << "Post: " << endl << endl;
	inputItems(infile, caseOneTree, 1);
	caseOneTree.display(outfile, 'p');
	
	//***** ADD TO MIDDLE
	
}

void testCase6(ifstream& infile, ofstream& outfile)
{
	Two34Tree caseOneTree;
	Two34Tree caseOneTree2;
	Two34Tree caseOneTree3;
	Two34Tree caseOneTree4;
	Two34Tree caseOneTree5;
	
	outfile << endl << "-------------SPLITTING A LEVEL 2 NODE TO MAKE 4 CHILDREN -----------" << endl;
	
	//Case 1: empty tree
	outfile  << endl << "Test1: CASE OF SPLITTING RIGHT NODE" << endl;
	inputItems(infile, caseOneTree, 8);
	outfile << endl << "Pre: " << endl << endl;
	caseOneTree.display(outfile, 'p');
	outfile << endl << "*Inserting 95" << endl << endl;
	outfile << endl << "Post: " << endl << endl;
	inputItems(infile, caseOneTree, 1);
	caseOneTree.display(outfile, 'p');
	
	//Case 1: empty tree
	outfile  << endl << "Test2: CASE OF SPLITTING LEFT NODE" << endl;
	inputItems(infile, caseOneTree2, 8);
	outfile << endl << "Pre: " << endl << endl;
	caseOneTree2.display(outfile, 'p');
	outfile << endl << "*Inserting 13" << endl << endl;
	outfile << endl << "Post: " << endl << endl;
	inputItems(infile, caseOneTree2, 1);
	caseOneTree2.display(outfile, 'p');
}

