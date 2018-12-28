//AVLTree.cpp

#include "AVLTree.h"

using namespace std;

const int MAXHEIGHT = 10;

struct SearchPath
{
   TreeNode* path[MAXHEIGHT];
   int pathSize;
   int pivotIndex; // to be explained later
   SearchPath();
};

void BSTinsertAndMakeSearchPath(const ItemType& newitem, Node*& treeptr,  SearchPath& search) throw (Exception)
{
	search.path[search.pathSize] = treeptr;			//assign current node in path
	search.pathSize = search.pathSize + 1;			//update path size
	
	if(treeptr == nullptr)
	{
		treeptr = new (nothrow) TreeNode(newitem, nullptr, nullptr);
		search.path[search.pathSize - 1] = treeptr;			//update from nullptr to new node
		if (treeptr == nullptr)
			throw Exception("No room in memory");
	}
	else if (newitem == treeptr -> item)
		throw Exception("Phone number already exists in the dictionary");
	
	else if (newitem < treeptr -> item)
		BSTinsertAndMakeSearchPath(newitem, treeptr -> leftChild, search);
	
	else
		BSTinsertAndMakeSearchPath(newitem, treeptr -> rightChild, search);

}

   
SearchPath::SearchPath() // constructor for the struct
{
	for(int k = 0; k < MAXHEIGHT; k++)
	{
		path[MAXHEIGHT] = nullptr;
	}
	pathSize = 0;
	pivotIndex = -1;
}

AVLTree::AVLTree()
{
}

AVLTree::~AVLTree()
{	
}

void AVLTree::insert(const Item& newItem) throw (Exception)
{
}

