//file BinarySearchTree.h
//Evan Swanson, Ryan Schoenlein
// 3/9/18

// Specification of ADT Binary Search Tree
//    Data object: A binary tree T that is either empty or
//                  in the form of     r
//                                  /    \
//                                TL     TR
//                  where TL and TR are binary trees
//		additionally, the keys in TL < r < keys in TR

//    Operations: 
//       create, destroy, search, insert, remove

// Contract: Assumes the this class can access private data members of class Node.
//    Those data members are: Item item, Node* leftptr, Node* rightptr.
//    There is a constructor that allows caller to give item, left and right ptrs.


#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "BinaryTree.h"
using namespace std;

class BinarySearchTree: public BinaryTree
{
public:

//creates an empty binary search tree
//post: object is an empty binary search tree
//usage: BinarySearchTree zags;
BinarySearchTree();
	
//releases the memory of a binary search tree
//pre: object exists
//post: memory for the object has been released. object theoretically does not exist
//       but in practice, it is empty.
~BinarySearchTree();

//creates a new binary search tree that is a copy of an existing tree
//post object is a copy of rhsBinarySearchTree
//throws an exception if there is not enough room in the heap for
//       an copied tree
//usage: BinarySearchTree zags (bulldog);
BinarySearchTree(const BinarySearchTree& rhsBinarySearchTree) throw (Exception);

//searches for an item in the tree
//pre: targetPhone has been assigned
//post: theItem contains the found item, or an exception is thrown if 
//      the target could not be found
//usgae:  tree.search(targetPhone, theItem)
void search (const Key& targetPhone, Item& theItem) throw (Exception);

//inserts a new item into the tree
//pre: newItem has been assigned
//post: newItem is stored in the tree or an exception is thrown if there is noboolalpha
//       room in the heap
//usage: tree.insert(newItem)
void insert (const Item& newItem) throw (Exception);

//removes an item from the tree
//pre: targetPhone has been assigned
//post: the target item corresponding to targetPhone has been removed from the tree
//      or an exception is thrown if the target is not found
//usage: tree.remove(targetPhone) 
void remove (const Key& targetPhone) throw (Exception);

};
#endif