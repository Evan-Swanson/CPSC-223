//Clientprogram.cpp
//Evan Swanson, Ryan Schoenlein
// 4/18/18
//Fully tests all cases of insert on a AVLTree

#include "AVLTree.h"
#include <iostream>
#include <fstream>
#include "Exception.h"

using namespace std;

void openInputFile(ifstream& infile);
void inputItems(ifstream& infile, AVLTree& theTree, int numberOfItems);
void testNoPivot(ifstream& infile, ofstream& outfile);
void testShortSide(ifstream& infile, ofstream& outfile);
void testSingleLeft(ifstream& infile, ofstream& outfile);
void testSingleRight(ifstream& infile, ofstream& outfile);
void testDoubleLeftRight(ifstream& infile, ofstream& outfile);
void testDoubleRightLeft(ifstream& infile, ofstream& outfile);
void PrintExceptionMessage(const Exception& except);

int main()
{
	ifstream infile;
	ofstream outfile;
	
	openInputFile(infile);
	outfile.open("avl.dat");
	
	try
	{
		testNoPivot(infile, outfile);
		testShortSide(infile, outfile);
		testSingleLeft(infile, outfile);
		testSingleRight(infile, outfile);
		testDoubleLeftRight(infile, outfile);
		testDoubleRightLeft(infile, outfile);
	}
	
	catch (Exception except)
	{
		PrintExceptionMessage(except);
	}
	
	
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
void inputItems(ifstream& infile, AVLTree& theTree, int numberOfItems)
{
	Item nextItem;
	
	for(int k = 0; k < numberOfItems; k++)
	{
		infile >> nextItem;
		theTree.insert(nextItem);
	}
}

//Tests all subcases of the hasNoPivot case
//pre: infile and outfile have been opened
//post: the outfile displays the case that is being tested, the subcases
// 		that are being tested, and the pre and post AVL Trees after an item
// 		is inserted for each subcases
//usage: testNoPivot(infile, outfile);
void testNoPivot(ifstream& infile, ofstream& outfile)
{
	AVLTree noPivotTree;
	
	outfile << endl << "-------------CASE OF NO PIVOT-----------" << endl;
	
	//Case 1: empty tree
	outfile  << endl << "Test1: CASE OF EMPTY TREE" << endl;
	outfile << endl << "Pre: " << endl << endl;
	noPivotTree.prettyDisplay(outfile);
	outfile << endl << "*Inserting 888" << endl << endl;
	inputItems(infile, noPivotTree, 1);
	outfile << "Post: " << endl << endl; 
	noPivotTree.prettyDisplay(outfile);
	
	//Case 2: 1 node tree
	outfile  << endl << "Test2: CASE OF 1 NODE TREE" << endl;
	outfile << endl << "Pre: " << endl << endl;
	noPivotTree.prettyDisplay(outfile);
	outfile << endl << "*Inserting 980" << endl << endl;
	inputItems(infile, noPivotTree, 1);
	outfile << "Post: " << endl << endl; 
	noPivotTree.prettyDisplay(outfile);

	
	//Case 2: tree of height 2
	inputItems(infile, noPivotTree, 1);
	
	outfile  << endl << "Test3: CASE OF TREE OF HEIGHT 2" << endl;
	outfile << endl << "Pre: " << endl << endl;
	noPivotTree.prettyDisplay(outfile);
	outfile << endl << "*Inserting 666" << endl << endl;
	inputItems(infile, noPivotTree, 1);
	outfile << "Post: " << endl << endl; 
	noPivotTree.prettyDisplay(outfile);
	
}

//Tests all subcases of the addedToShortSide case
//pre: infile and outfile have been opened
//post: the outfile displays the case that is being tested, the subcases
// 		that are being tested, and the pre and post AVL Trees after an item
// 		is inserted for each subcases
//usage: testShortSide(infile, outfile);
void testShortSide(ifstream& infile, ofstream& outfile)
{
	AVLTree shortSideTreeLeft;
	AVLTree shortSideTreeRight;
	inputItems(infile, shortSideTreeLeft, 2);
	
	
	outfile << endl << "-------------CASE OF ADDED TO SHORT SIDE-----------" << endl;
	
	//Case 1: Tall to the left
	outfile  << endl << "Test1: CASE OF TALL TO THE LEFT" << endl;
	outfile << endl << "Pre: " << endl << endl;
	shortSideTreeLeft.prettyDisplay(outfile);
	outfile << endl << "*Inserting 999" << endl << endl;
	inputItems(infile, shortSideTreeLeft, 1);
	outfile << "Post: " << endl << endl; 
	shortSideTreeLeft.prettyDisplay(outfile);
	
	//Case 2: Tall to the right
	inputItems(infile, shortSideTreeRight, 2);
	outfile  << endl << "Test2: CASE OF TALL TO THE RIGHT" << endl;
	outfile << endl << "Pre: " << endl << endl;
	shortSideTreeRight.prettyDisplay(outfile);
	outfile << endl << "*Inserting 777" << endl << endl;
	inputItems(infile, shortSideTreeRight, 1);
	outfile << "Post: " << endl << endl; 
	shortSideTreeRight.prettyDisplay(outfile);
	
	//Case 3 height 2
	inputItems(infile, shortSideTreeRight, 1);
	outfile  << endl << "Test3: CASE OF HEIGHT 2" << endl;
	outfile << endl << "Pre: " << endl << endl;
	shortSideTreeRight.prettyDisplay(outfile);
	outfile << endl << "*Inserting 780" << endl << endl;
	inputItems(infile, shortSideTreeRight, 1);
	outfile << "Post: " << endl << endl; 
	shortSideTreeRight.prettyDisplay(outfile);
	
	//Case 4 leaf on short side
	outfile  << endl << "Test4: CASE OF PIVOT NOT THE PARENT" << endl;
	outfile << endl << "Pre: " << endl << endl;
	shortSideTreeRight.prettyDisplay(outfile);
	outfile << endl << "*Inserting 900" << endl << endl;
	inputItems(infile, shortSideTreeRight, 1);
	outfile << "Post: " << endl << endl; 
	shortSideTreeRight.prettyDisplay(outfile);
}

//Tests all subcases of the singleLeftRotation case
//pre: infile and outfile have been opened
//post: the outfile displays the case that is being tested, the subcases
// 		that are being tested, and the pre and post AVL Trees after an item
// 		is inserted for each subcases
//usage: testSingleLeft(infile, outfile);
void testSingleLeft(ifstream& infile, ofstream& outfile)
{
	AVLTree singleLeftTree;
	inputItems(infile, singleLeftTree, 2);
	
	
	outfile << endl << "-------------CASE OF SINGLE LEFT ROTATION-----------" << endl;
	
	//Case 1: h = 0
	outfile  << endl << "Test1: CLOUD POINTER IS THE ROOT" << endl;
	outfile << endl << "Pre: " << endl << endl;
	singleLeftTree.prettyDisplay(outfile);
	outfile << endl << "*Inserting 980" << endl << endl;
	inputItems(infile, singleLeftTree, 1);
	outfile << "Post: " << endl << endl; 
	singleLeftTree.prettyDisplay(outfile);
	
	//Case 2: h = 1
	inputItems(infile, singleLeftTree, 2);
	outfile  << endl << "Test2: CASE OF SUBTREES T1,T2,T3 HAVE HEIGHT 1" << endl;
	outfile << endl << "Pre: " << endl << endl;
	singleLeftTree.prettyDisplay(outfile);
	outfile << endl << "*Inserting 995" << endl << endl;
	inputItems(infile, singleLeftTree, 1);
	outfile << "Post: " << endl << endl; 
	singleLeftTree.prettyDisplay(outfile);
	
	//Case 3: Cloud pointer is rightChild
	outfile  << endl << "Test3: CASE OF CLOUD POINTER IS A RIGHT CHILD" << endl;
	outfile << endl << "Pre: " << endl << endl;
	singleLeftTree.prettyDisplay(outfile);
	outfile << endl << "*Inserting 997" << endl << endl;
	inputItems(infile, singleLeftTree, 1);
	outfile << "Post: " << endl << endl; 
	singleLeftTree.prettyDisplay(outfile);
	
	//Case 4: Cloud pointer is leftChild
	inputItems(infile, singleLeftTree, 1);
	outfile  << endl << "Test4: CASE OF CLOUD POINTER IS A LEFT CHILD" << endl;
	outfile << endl << "Pre: " << endl << endl;
	singleLeftTree.prettyDisplay(outfile);
	outfile << endl << "*Inserting 993" << endl << endl;
	inputItems(infile, singleLeftTree, 1);
	outfile << "Post: " << endl << endl; 
	singleLeftTree.prettyDisplay(outfile);
}

//Tests all subcases of the singleRightRotation case
//pre: infile and outfile have been opened
//post: the outfile displays the case that is being tested, the subcases
// 		that are being tested, and the pre and post AVL Trees after an item
// 		is inserted for each subcases
//usage: testSingleRight(infile, outfile);
void testSingleRight(ifstream& infile, ofstream& outfile)
{
	AVLTree singleRightTree;
	inputItems(infile, singleRightTree, 2);
	
	outfile << endl << "-------------CASE OF SINGLE RIGHT ROTATION-----------" << endl;
	
	//Case 1: h = 0
	outfile  << endl << "Test1: CLOUD POINTER IS THE ROOT" << endl;
	outfile << endl << "Pre: " << endl << endl;
	singleRightTree.prettyDisplay(outfile);
	outfile << endl << "*Inserting 555" << endl << endl;
	inputItems(infile, singleRightTree, 1);
	outfile << "Post: " << endl << endl; 
	singleRightTree.prettyDisplay(outfile);
	
	//Case 2: h = 1
	inputItems(infile, singleRightTree, 2);
	outfile  << endl << "Test2: CASE OF SUBTREES T1,T2,T3 HAVE HEIGHT 1" << endl;
	outfile << endl << "Pre: " << endl << endl;
	singleRightTree.prettyDisplay(outfile);
	outfile << endl << "*Inserting 333" << endl << endl;
	inputItems(infile, singleRightTree, 1);
	outfile << "Post: " << endl << endl; 
	singleRightTree.prettyDisplay(outfile);
	
	//Case 3: Cloud pointer is leftChild
	outfile  << endl << "Test3: CASE OF CLOUD POINTER IS A LEFT CHILD" << endl;
	outfile << endl << "Pre: " << endl << endl;
	singleRightTree.prettyDisplay(outfile);
	outfile << endl << "*Inserting 222" << endl << endl;
	inputItems(infile, singleRightTree, 1);
	outfile << "Post: " << endl << endl; 
	singleRightTree.prettyDisplay(outfile);
	
	//Case 4: Cloud pointer is leftChild
	inputItems(infile, singleRightTree, 1);
	outfile  << endl << "Test4: CASE OF CLOUD POINTER IS A RIGHT CHILD" << endl;
	outfile << endl << "Pre: " << endl << endl;
	singleRightTree.prettyDisplay(outfile);
	outfile << endl << "*Inserting 350" << endl << endl;
	inputItems(infile, singleRightTree, 1);
	outfile << "Post: " << endl << endl; 
	singleRightTree.prettyDisplay(outfile);
	
}

//Tests all subcases of the doubleLeftRightRotation case
//pre: infile and outfile have been opened
//post: the outfile displays the case that is being tested, the subcases
// 		that are being tested, and the pre and post AVL Trees after an item
// 		is inserted for each subcases
//usage: testDoubleLeftRight(infile, outfile);
void testDoubleLeftRight(ifstream& infile, ofstream& outfile)
{
	AVLTree doubleLeftRightTree;
	AVLTree secondDoubleLeftRightTree;
	inputItems(infile, doubleLeftRightTree, 5);
	
	outfile << endl << "-------------CASE OF DOULBE LEFT RIGHT ROTATION-----------" << endl;
	
	//Case 1: h = 0
	outfile  << endl << "Test1: CLOUD POINTER IS THE ROOT" << endl;
	outfile << endl << "Pre: " << endl << endl;
	doubleLeftRightTree.prettyDisplay(outfile);
	outfile << endl << "*Inserting 670" << endl << endl;
	inputItems(infile, doubleLeftRightTree, 1);
	outfile << "Post: " << endl << endl; 
	doubleLeftRightTree.prettyDisplay(outfile);
	
	//Case 2: h = 1
	inputItems(infile, doubleLeftRightTree, 3);
	outfile  << endl << "Test2: CASE OF OUTSIDE SUBTREES HEIGHT 2 AND INSIDE HAVE HEIGHT 1" << endl;
	outfile << endl << "Pre: " << endl << endl;
	doubleLeftRightTree.prettyDisplay(outfile);
	outfile << endl << "*Inserting 667" << endl << endl;
	inputItems(infile, doubleLeftRightTree, 1);
	outfile << "Post: " << endl << endl; 
	doubleLeftRightTree.prettyDisplay(outfile);
	
	//Case 3: Cloud pointer is a leftChild
	inputItems(infile, secondDoubleLeftRightTree, 10);
	outfile  << endl << "Test3: CASE OF CLOUD POINTER IS A LEFT CHILD" << endl;
	outfile << endl << "Pre: " << endl << endl;
	secondDoubleLeftRightTree.prettyDisplay(outfile);
	outfile << endl << "*Inserting 580" << endl << endl;
	inputItems(infile, secondDoubleLeftRightTree, 1);
	outfile << "Post: " << endl << endl; 
	secondDoubleLeftRightTree.prettyDisplay(outfile);
	
	//Case 4: Cloud pointer is rightChild
	inputItems(infile, secondDoubleLeftRightTree, 1);
	outfile  << endl << "Test4: CASE OF CLOUD POINTER IS A RIGHT CHILD" << endl;
	outfile << endl << "Pre: " << endl << endl;
	secondDoubleLeftRightTree.prettyDisplay(outfile);
	outfile << endl << "*Inserting 713" << endl << endl;
	inputItems(infile, secondDoubleLeftRightTree, 1);
	outfile << "Post: " << endl << endl; 
	secondDoubleLeftRightTree.prettyDisplay(outfile);
	
}

//Tests all subcases of the doubleRightLeftRotation case
//pre: infile and outfile have been opened
//post: the outfile displays the case that is being tested, the subcases
// 		that are being tested, and the pre and post AVL Trees after an item
// 		is inserted for each subcases
//usage: testDoubleRightLeft(infile, outfile);
void testDoubleRightLeft(ifstream& infile, ofstream& outfile)
{
	AVLTree doubleRightLeftTree;
	AVLTree secondDoubleRightLeftTree;
	inputItems(infile, doubleRightLeftTree, 5);
	
	outfile << endl << "-------------CASE OF DOULBE RIGHT LEFT ROTATION-----------" << endl;

	//Case 1: h = 0
	outfile  << endl << "Test1: CLOUD POINTER IS THE ROOT" << endl;
	outfile << endl << "Pre: " << endl << endl;
	doubleRightLeftTree.prettyDisplay(outfile);
	outfile << endl << "*Inserting 550" << endl << endl;
	inputItems(infile, doubleRightLeftTree, 1);
	outfile << "Post: " << endl << endl; 
	doubleRightLeftTree.prettyDisplay(outfile);
	
	
	//Case 2: h = 1
	inputItems(infile, doubleRightLeftTree, 4);
	outfile  << endl << "Test2: CASE OF OUTSIDE SUBTREES HEIGHT 2 AND INSIDE HAVE HEIGHT 1" << endl;
	outfile << endl << "Pre: " << endl << endl;
	doubleRightLeftTree.prettyDisplay(outfile);
	outfile << endl << "*Inserting 610" << endl << endl;
	inputItems(infile, doubleRightLeftTree, 1);
	outfile << "Post: " << endl << endl; 
	doubleRightLeftTree.prettyDisplay(outfile);
	
	//Case 3: Cloud pointer is a rightChild

	inputItems(infile, secondDoubleRightLeftTree, 10);
	outfile  << endl << "Test3: CASE OF CLOUD POINTER IS A RIGHT CHILD" << endl;
	outfile << endl << "Pre: " << endl << endl;
	secondDoubleRightLeftTree.prettyDisplay(outfile);
	outfile << endl << "*Inserting 550" << endl << endl;
	inputItems(infile, secondDoubleRightLeftTree, 1);
	outfile << "Post: " << endl << endl; 
	secondDoubleRightLeftTree.prettyDisplay(outfile);
	
	//Case 4: Cloud pointer is rightChild
	inputItems(infile, secondDoubleRightLeftTree, 1);
	outfile  << endl << "Test4: CASE OF CLOUD POINTER IS A LEFT CHILD" << endl;
	outfile << endl << "Pre: " << endl << endl;
	secondDoubleRightLeftTree.prettyDisplay(outfile);
	outfile << endl << "*Inserting 230" << endl << endl;
	inputItems(infile, secondDoubleRightLeftTree, 1);
	outfile << "Post: " << endl << endl; 
	secondDoubleRightLeftTree.prettyDisplay(outfile);
	
	
}

void PrintExceptionMessage(const Exception& except)
{
   cout << endl << endl;
   cout << except.What();
   cout << endl << endl;
}


