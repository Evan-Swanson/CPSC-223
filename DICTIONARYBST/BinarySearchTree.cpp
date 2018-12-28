//BinarySearchTree.cpp
//Evan Swanson, Ryan Schoenlein
// 3/26/18
//
//Implementation of Binary Search Tree
//		abstract definition:  A binary tree where the the keys in the 
//							  left subtree < key in root < keys in the right subtree
//
//		data structure: a linked binary tree

#include "BinarySearchTree.h"
#include <fstream>

using namespace std;

//recursive helpers
//--------------------

//helper function for search 
//pre: treep, targetPhone have been assinged
//post: anItem contains the found contact, or an exception is thrown if it is not found
//usage: searchHelper(root, targetPhone, anItem);
void searchHelper(TreeNode* treep, const Key& targetPhone, Item& anItem) throw (Exception)
{
	if(treep == nullptr)
		throw Exception("Phone number not found in the dictionary");
	else if (targetPhone == treep -> item)
		anItem = treep -> item;
	else if (targetPhone < treep -> item)
		searchHelper(treep -> leftChild, targetPhone, anItem);
	else
		searchHelper(treep -> rightChild, targetPhone, anItem);
}

//helper funcion for insert
//pre: treep, newItem have been assigned
//post: item has been inserted in correct place, or an exception is thrown 
//       if the item already exists or there is no room
//usage: insertHelper(root, newItem);
void insertHelper(TreeNode*& treep, const Item& newItem) throw (Exception)
{
	if(treep == nullptr)
	{
		treep = new (nothrow) TreeNode(newItem, nullptr, nullptr);
		if (treep == nullptr)
			throw Exception("No room in memory");
	}
	else if (newItem == treep -> item)
		throw Exception("Phone number already exists in the dictionary");
	else if (newItem < treep -> item)
		insertHelper(treep -> leftChild, newItem);
	else
		insertHelper(treep -> rightChild, newItem);
}

//inorder helper function
//pre: treep has been assigned
//post: output contains the inorder traversal of the binary tree
//usage: inorderBST(root, cout);
void inorderBST(TreeNode* treep, ostream& output)
{
	if (treep != nullptr)
	{
		inorderBST(treep -> leftChild, output);
		output << treep -> item;
		inorderBST(treep -> rightChild, output);
	}
}

//helper function that reads a sorted list into a minimum height binary search tree
//pre: treep, numberOfKeys have been assigned, infile has been opened
//post: minimum height binary search tree has been created
//usage: readTree(root, numberOfKeys, infile);
void readTree(TreeNode*& treep, int& numberOfKeys, ifstream& infile)
{
	if (numberOfKeys > 0)
	{
		Item blankItem;
		Item newItem;
		treep = new TreeNode(blankItem, nullptr, nullptr);
		int leftChildNumber = numberOfKeys / 2;
		readTree(treep -> leftChild, leftChildNumber, infile);
		infile >> newItem;
		treep -> item = newItem;
		int rightChildNumber = (numberOfKeys - 1) / 2;
		readTree(treep -> rightChild, rightChildNumber, infile);
	}
}

//helper function that removes the leftmost leaf, and gets that node's item
//pre: treep has been assigned (in the case of the inorder successor, 
//     treep has been assinged the rightChild of the node to be removed)
//post: the leftmost leaf has been removed and replacementItem has been assigned that node's item
//usage: removeLeftmostLeaf(treep, replacementItem);
void removeLeftmostLeaf(TreeNode*& treep, Item& replacementItem)
{
	if(treep -> leftChild != nullptr)
	{
		removeLeftmostLeaf(treep -> leftChild, replacementItem);
	}
	
	else
	{
		replacementItem = treep -> item;
		delete treep;
		treep = nullptr;
	}

}

//helper that removes a tree node
//pre: treep and targetPhone have been assigned
//post: targetPhone has been removed from the binary search tree
//usage: removeHelper(root, targetPhone);
void removeHelper(TreeNode*& treep, const Key& targetPhone) throw (Exception)
{
	if(treep == nullptr)
		throw Exception("Phone number not found in the dictionary");
	
	else if (targetPhone == treep -> item)
	{
		if(treep -> leftChild == nullptr and treep -> rightChild == nullptr)
		{
			delete treep;
			treep = nullptr;
		}
		
		else if(treep -> leftChild == nullptr and treep -> rightChild != nullptr)
		{
			TreeNode* delptr = treep;
			treep = treep -> rightChild;
			delete delptr;
		}
		
		else if(treep -> leftChild != nullptr and treep -> rightChild == nullptr)
		{
			TreeNode* delptr = treep;
			treep = treep -> leftChild;
			delete delptr;
		}
		
		else
		{
			Item replacementItem;
			TreeNode* delPtr;
			
			delPtr = treep;
			
			removeLeftmostLeaf(delPtr -> rightChild, replacementItem);

			treep -> item = replacementItem;
		}
	}
	
	else if (targetPhone < treep -> item)
		removeHelper(treep -> leftChild, targetPhone);
	
	else
		removeHelper(treep -> rightChild, targetPhone);
	
}

//--------------

//creates an empty binary search tree (which is-a binary tree)
//post: numberOfItems is 0
//usage: BinarySearchTree zags;
BinarySearchTree::BinarySearchTree()
{
	numberOfItems = 0;
}

BinarySearchTree::~BinarySearchTree()
{
}

BinarySearchTree::BinarySearchTree(const BinarySearchTree& rhsBinarySearchTree) throw (Exception)
{
}

//searchs for an item in the binary search tree
//pre: targetPhone has been assigned
//post: theItem contains the found item, or an exception is thrown if it is not found
//usage: search(targetPhone, theItem)
void BinarySearchTree::search (const Key& targetPhone, Item& theItem) throw (Exception)
{
	searchHelper(root, targetPhone, theItem);
}

//inserts a new item into the binary search tree
//pre: newItem has been assigned
//post: newItem is in the binary search tree
//usage: insert(newItem);
void BinarySearchTree::insert (const Item& newItem) throw (Exception)
{
	insertHelper(root, newItem);
	numberOfItems++;
}

//outputs an inorder traversal of the binary search tree with the
//  number of items first, followed by a new line, with a new line after each item
//pre: output has been opened if it is a file
//post: output contains the number of items and the tree's items in inorder fasion
//usage: inorderTraverse(output)
void BinarySearchTree::inorderTraverse(ostream& output)
{
	output << numberOfItems << endl;
	inorderBST(root, output);
}

//rebalances the tree to make it a minimum height binary search tree
//pre: infile and outfile are not open
//post: dictionary.dat contains the inorder traversal of the tree, and the tree is now minimum height
//usage: rebalance(infile, outfile)
void BinarySearchTree::rebalance(ifstream& infile, ofstream& outfile)
{
	int numberOfKeys;
	char newLine;
	
	outfile.open("dictionary.dat");
	inorderTraverse(outfile);
	outfile.close();
	infile.open("dictionary.dat");
	infile >> numberOfKeys;
	infile.get(newLine);
	readTree(root, numberOfKeys, infile);
	infile.close();
}

//removes an item from the tree
//pre: targetPhone has been assigned
//post: targetPhone is removed from the tree
//usage: remove(targetPhone);
void BinarySearchTree::remove (const Key& targetPhone) throw (Exception)
{
	removeHelper(root, targetPhone);
	numberOfItems--;
}