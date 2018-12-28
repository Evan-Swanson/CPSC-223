//Clientprogram.cpp
//This program inputs a full binary tree of height 3 and a 
//degenerate tree of height 4 from an input file, and then performs
//3 different traversal methods and displays the results to the screen

//Evan Swanson, Ryan Schoenlein
//2/21/18
//dropoff: eswanson2

#include <iostream>
#include "BinaryTree.h"
#include <fstream>
#include <cstdlib>

using namespace std;

//opens an input file named "Input.dat"
//pre: Input.dat file exists
//post: file has been opened
//usage: openInputFile(infile)
void openInputFile(ifstream& infile);

//reads one tree node from a file
//pre: infile has been opened
//	   infile's pointer is at the beginning of a line
//     the item is on a line
//     the next line are the two integers representing children
//     Example:
//     1111111 Alli F
//     1 2
//
//post: newItem, left, and right have been assigned
//      infile's pointer is after the newline following the 2nd integer
//usage: readOneTreeNode(infile, newItem, left, right);
void readOneTreeNode(ifstream& infile, Item& newItem, int& left, int& right);

//Reads multiple tree nodes and inserts them into a binary tree
//pre: infile has been opened
//     infile's pointer is before the first integer
//     first line has the number of nodes to be read
//     infile has next item on a line
//     the next line are the two integers representing chlidren
//     then the next item is on a new line
//     Example:
//     2
//     1111111 Alli F
//     1 2
//     2222222 Evan S 
//     -1 3
//
//post: tree contains all nodes in infile
//      infile's pointer is left after the newline following the last set of children
//usage: readTreeNodesAndInsert(infile, myTree);
void readTreeNodesAndInsert(ifstream& infile, BinaryTree& tree);

//prints this particular full tree of height 3
//post: the screen displays the full tree 
//usage: printFullTree()
void printFullTree();

//prints this particular degenerate tree of height 4
//post: the screen displays the degenerate tree
//usage: printDegenerateTree()
void printDegenerateTree();

//traverses a binary tree using preorder, inorder, and postorder methods,
//  and prints the results to the screen
//pre: theTree has been assigned
//post: the screen displays the 3 methods of traversal and their results
//usage: treeTraversal(myTree)
void treeTraversal(BinaryTree& theTree);

  
 int main()
 {
	BinaryTree fullTree, degenerateTree; 
	ifstream infile;
	
	openInputFile(infile);
	
	readTreeNodesAndInsert(infile, fullTree);
	printFullTree();
	treeTraversal(fullTree);
	
	readTreeNodesAndInsert(infile, degenerateTree);
	printDegenerateTree();
	treeTraversal(degenerateTree);
	
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

//reads one tree node from a file
//pre: infile has been opened
//	   infile's pointer is at the beginning of a line
//     the item is on a line
//     the next line are the two integers representing children
//     Example:
//     1111111 Alli F
//     1 2
//
//post: newItem, left, and right have been assigned
//      infile's pointer is after the newline following the 2nd integer
//usage: readOneTreeNode(infile, newItem, left, right);
void readOneTreeNode(ifstream& infile, Item& newItem, int& left, int& right)
{
	char newLine;
	
	infile >> newItem;
	infile >> left;
	infile >> right;
	infile.get(newLine);
}

//Reads multiple tree nodes and inserts them into a binary tree
//pre: infile has been opened
//     infile's pointer is before the first integer
//     first line has the number of nodes to be read
//     infile has next item on a line
//     the next line are the two integers representing chlidren
//     then the next item is on a new line
//     Example:
//     2
//     1111111 Alli F
//     1 2
//     2222222 Evan S 
//     -1 3
//
//post: tree contains all nodes in infile
//      infile's pointer is left after the newline following the last set of children
//usage: readTreeNodesAndInsert(infile, myTree);
void readTreeNodesAndInsert(ifstream& infile, BinaryTree& tree)
{
	int numberOfNodes;
	char newLine;
	int left, right;
	Item newItem;
	
	infile >> numberOfNodes;
	infile.get(newLine);
	
	for(int k = 0; k < numberOfNodes; k++)
	{
		readOneTreeNode(infile, newItem, left, right);
		tree.insert(newItem, left, right);
	}
}

//prints this particular full tree of height 3
//post: the screen displays the full tree 
//usage: printFullTree()
void printFullTree()
{
	cout << endl << "Full Tree: " << endl;
	cout << "                       111-1111 Alli F" << endl;
	cout << "                       /            \\    " << endl;
	cout << "         222-2222 Evan S               333-3333 Mason D" << endl;
	cout << "         /           \\                  /          \\  " << endl;
	cout << " 444-4444 Bert Z  555-5555 Jake M   666-6666 Peter D  777-7777 Andrew C" << endl << endl;
}

//prints this particular degenerate tree of height 4
//post: the screen displays the degenerate tree
//usage: printDegenerateTree()
void printDegenerateTree()
{
	cout << endl << "Degenerate Tree: " << endl;
	cout << "                     111-1111 Alli F" << endl;
	cout << "                           /" << endl;
	cout << "                  222-2222 Evan S" << endl;
	cout << "                        /" << endl;
	cout << "               333-3333 Bert Z " << endl;
	cout << "                     / " << endl;
	cout << "            444-4444 Johan J" << endl << endl;
}

//traverses a binary tree using preorder, inorder, and postorder methods,
//  and prints the results to the screen
//pre: fullTree has been assigned
//post: the screen displays the 3 methods of traversal and their results
//usage: traversal(myTree)
void treeTraversal(BinaryTree& theTree)
{
	theTree.preorder();
	theTree.inorder();
	theTree.postorder();
}