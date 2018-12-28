//Implementation of Binary Search Tree
//		abstract definition:
//
//		data structure: a linked binary tree

#include "BinarySearchTree.h"

using namespace std;

//recursive helpers

void searchHelper(TreeNode* treep, const Key& targetPhone, Item& anItem) throw (Exception)
{
	if(treep == nullptr)
		throw Exception("search: phone number not found in the dictionary");
	else if (targetPhone == treep -> item)
		anItem = treep -> item;
	else if (targetPhone < treep -> item)
		searchHelper(treep -> leftChild, targetPhone, anItem);
	else
		searchHelper(treep -> rightChild, targetPhone, anItem);
}

void insertHelper(TreeNode*& treep, const Item& newItem) throw (Exception)
{
	if(treep == nullptr)
	{
		treep = new (nothrow) TreeNode(newItem, nullptr, nullptr);
		if (treep == nullptr)
			throw Exception("insert: no room in the heap");
	}
	else if (newItem == treep -> item)
		throw Exception("Insert: Phone number already exists in the dictionary");
	else if (newItem < treep -> item)
		insertHelper(treep -> leftChild, newItem);
	else
		insertHelper(treep -> rightChild, newItem);
}

BinarySearchTree::BinarySearchTree()
{
}
	
BinarySearchTree::~BinarySearchTree()
{
}

BinarySearchTree::BinarySearchTree(const BinarySearchTree& rhsBinarySearchTree) throw (Exception)
{
}
	
void BinarySearchTree::search (const Key& targetPhone, Item& theItem) throw (Exception)
{
	
}

void BinarySearchTree::insert (const Item& newItem) throw (Exception)
{
}

void BinarySearchTree::remove (const Key& targetPhone) throw (Exception)
{
}