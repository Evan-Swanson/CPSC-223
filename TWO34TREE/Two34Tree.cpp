// Specification of ADT 2-3-4 Tree
//     data object: a 2-3-4 tree (a tree containing 2-nodes,
//                  3-nodes, and 4-nodes) where a k-node has
//                  k children
// note: this is not the formal definition that takes 2 pages in textbook
//     operations: create, destroy, insert, display
// Programmer: Evan Swanson, Ryan Schoenlein
// Filename: Two34Tree.cpp
//
// class Two34TreeNode specifies and implements a node for a
//    2-3-4 tree with room for 1-3 data items from class citem and
//    0-4 children

#include "Two34Tree.h"

using namespace std;

// recursive helper functions to be cut and copied into .cpp

   // frees the heap memory of a tree
   // pre: treep is assigned but may be empty
   // post: all nodes in the tree with root treep
   //       have been released back to the heap and
   //       treep is empty
   // usage: destroyTree (mroot);
   void destroyTree(Two34Tree*& treep)
   {
   }

   // shows the data in the tree in inorder
   // pre: treep is assigned but may be empty
   //      output is open
   // post: the data items in the nodes of treep's tree
   //       are printed to output in inorder
   void inorder(ostream& output, Two34TreeNode*& treep)
   {
	   if(treep != nullptr)
	   {
			inorder(output, treep -> kids[0]);
			inorder(output, treep -> kids[2]);
			for(int k = 0; k < treep -> numberOfKeys; k++)
			{
				output << treep -> keys[k] << " ";
			}
			inorder(output, treep -> kids[3]);
			inorder(output, treep -> kids[1]);
			
	   }
   }

   // shows the data in the tree in its tree structure
   // pre: output is open. treep is assigned a tree.
   //      level is assigned
   // post: the data items of the nodes of treep at level
   //       in the tree are printed to output with spacing
   //       to denote the level.
   // usage: pretty (output, mroot, 1);
   void pretty(ostream& output, Two34TreeNode* treep, int level)
   {
	   if(treep != nullptr)
	   {
			pretty(output, treep -> kids[1], level + 1);
			pretty(output, treep -> kids[3], level + 1);
	
			for(int k = 0; k < level; k++)				//space for level
			{
				output << "		";
			}
			
			for(int k = 0; k < treep -> numberOfKeys; k++)	//output node
			{
				output << treep -> keys[k] << " ";
			}
			
			output << endl;

			pretty(output, treep -> kids[2], level + 1);
			pretty(output, treep -> kids[0], level + 1);
	   }
	   
	   
   }
   
   
   //inserts a new key into a node in its correct spot
   //pre: treep points to the desired node, newKey has been assigned
   //post: the node now contains newKey and is sorted
   //usage: insertIntoLeaf(parentPtr, newKey);
   void insertIntoLeaf(Two34TreeNode*& treep, const Key& newKey)
   {
		treep -> keys[treep -> numberOfKeys] = newKey;		//put at the end
		treep -> numberOfKeys = treep -> numberOfKeys + 1;  //update numberOfKeys
		
		
		for(int k = 0; k < treep -> numberOfKeys - 1; k++)
		{
			for(int k = 0; k < treep -> numberOfKeys -1; k++)
			{
				if(treep -> keys[k+1] < treep -> keys[k])	//bubble sort
				{
					Key tempKey;
					tempKey = treep -> keys[k+1];
					treep -> keys[k+1] = treep -> keys[k];
					treep -> keys[k] = tempKey; 
				}
			}
		}
   }
   
   
   //Finds the correct leaf that a new item should be placed in, or a full node is encountered
   //pre: treep points to the root, topPtr points to the root, newKey has been assigned, foundFullNode is false
   //post: treep points to the leaf, topPtr points to its parent, or foundFullNode is true and topPtr points to the full node
   //usage: findLeaf(bottomPtr, topPtr, foundFullNode, newKey);
   void findLeaf(Two34TreeNode*& treep, Two34TreeNode*& topPtr, bool& foundFullNode, const Key& newKey)
   {
	   //find leaf
	   while(treep -> numberOfKids != 0 && !foundFullNode)
	   {
		   if(treep -> numberOfKeys == 3)
				foundFullNode = true;
	   
		   //less than (rightmost)
		   else if(newKey < treep -> keys[0])
		   {
			   topPtr = treep;
			   treep = treep -> kids[0];
		   }
		   
		   //greater than (leftmost)
		   else if (treep -> keys[treep -> numberOfKeys - 1] < newKey)
		   {
			   topPtr = treep;
			   treep = treep -> kids[1];
		   }
		   
		   //inbetween
		   else
		   {
			   cout << "test" ;
			   topPtr = treep;
			   treep = treep -> kids[2];

		   }
	   }
	   
	   if(treep -> numberOfKeys == 3)
		   foundFullNode = true;
   }
   
   
   //Splits a full node so that the middle item goes up and the two left are their own nodes
   //pre: parentPtr points to the parent of the full node, childPtr points to the full node, root is the root
   //post: the node has been split and the correct children have been created
   //usage: splitNode(topPtr, bottomPtr, root);
   void splitNode(Two34TreeNode*& parentPtr, Two34TreeNode*& childPtr, Two34TreeNode*& root)
   {
	   //root node
	   if(childPtr == root)
	   {
		   Two34TreeNode* tempPtr;
		   tempPtr = new Two34TreeNode(parentPtr -> keys[2]); //tempPtr points to new node with rightmost key
		   root = new Two34TreeNode(parentPtr -> keys[1], parentPtr ,tempPtr); //root is a new node with middle key and points to original node and new node
		   parentPtr->cleanUpNode();
		   parentPtr -> kids[0] = nullptr;
		   parentPtr -> kids[1] = nullptr;
		   parentPtr -> numberOfKids = 0;
		   parentPtr = root;		//move parent back to the new parent
	   }
	   
	   else
	   {
			if(parentPtr -> kids[1] == childPtr)					//right node
			{
				parentPtr -> keys[parentPtr -> numberOfKeys] = childPtr -> keys[1]; //middle one goes up
				parentPtr -> numberOfKeys = parentPtr -> numberOfKeys + 1;			//numberOfKeys incremented
				parentPtr -> kids[parentPtr -> numberOfKids] = childPtr;
				parentPtr -> kids[1] = new Two34TreeNode(childPtr -> keys[2]);  //right items gets a new node (leftChild: kids[1])
				parentPtr -> numberOfKids = parentPtr -> numberOfKids + 1;
			}
			else
			{
				parentPtr -> keys[2] = parentPtr -> keys[1];
				parentPtr -> keys[1] = parentPtr -> keys[0];
				parentPtr -> keys[0] = childPtr -> keys[1]; 	//middle one goes up
				parentPtr -> numberOfKeys = parentPtr -> numberOfKeys + 1;			//numberOfKeys incremented
				if(parentPtr -> numberOfKeys == 3)
				{
					parentPtr -> kids[3] = parentPtr -> kids[2];
					parentPtr -> kids[2] = new Two34TreeNode(childPtr -> keys[2]);
					parentPtr -> numberOfKids = parentPtr -> numberOfKids + 1;
					
				}
				else
				{
					parentPtr -> kids[parentPtr -> numberOfKids] = new Two34TreeNode(childPtr -> keys[2]);  //right items gets a new node (leftChild: kids[1]) //changed%
					parentPtr -> numberOfKids = parentPtr -> numberOfKids + 1;
				}
			}
			
			childPtr->cleanUpNode();
		   
	   }
   }
   
   //inserts an item into the correct child node of a parent
   //pre: parentPtr points to the parent of the nodes that the newKey can go into, newKey is assigned
   //post: newKey has been inserted into the correct position
   //usage: insertIntoChild(parentPtr, newKey);
   void insertIntoChild(Two34TreeNode*& parentPtr, const Key& newKey)
   {
	   if(parentPtr -> numberOfKeys == 1)
	   {
			if(newKey < parentPtr -> keys[0])
				insertIntoLeaf(parentPtr -> kids[0], newKey);
			else
				insertIntoLeaf(parentPtr -> kids[1], newKey);
	   }
	   
	   else if (parentPtr -> numberOfKeys == 2)
	   {
			if(newKey < parentPtr -> keys[0]) 			//smaller (rightmost)
				insertIntoLeaf(parentPtr -> kids[0], newKey);
			else if(parentPtr -> keys[1] < newKey )		//greater (leftmost)
				insertIntoLeaf(parentPtr -> kids[1], newKey);
			else										//middle
				insertIntoLeaf(parentPtr -> kids[2], newKey);
	   }
	   else if (parentPtr -> numberOfKeys == 3)
	   {
			if(newKey < parentPtr -> keys[0]) 			//smaller (rightmost)
				insertIntoLeaf(parentPtr -> kids[0], newKey);
			else if(parentPtr -> keys[1] < newKey )		//greater (leftmost)
				insertIntoLeaf(parentPtr -> kids[1], newKey);
			else if(newKey < parentPtr -> keys[2])		//middle right
				insertIntoLeaf(parentPtr -> kids[3], newKey);
			else										//middle left
				insertIntoLeaf(parentPtr -> kids[2], newKey);
	   }
   }
   

   
   // creates an empty 2-3-4 Tree
   // post: object is empty
   Two34Tree::Two34Tree()
   {
	   root = nullptr;
   }

   // destroys a 2-3-4 Tree
   // pre: object exists
   // post: object does not exist, all pre-memory released
   Two34Tree::~Two34Tree()
   {
	   
   }

   // inserts a new key into the tree
   // pre: tree object exists. newKey is assigned.
   // post: newKey is placed in the appropriately sorted
   //       position in the 2-3-4 tree object
   // usage: tree.insert(mykey);
   void Two34Tree::insert(const Key& newKey)
   {
	   bool foundFullNode;
	   Two34TreeNode* bottomPtr = root;
	   Two34TreeNode* topPtr = root;
	   
	   
	   if(root == nullptr)
	   {
		   root = new Two34TreeNode(newKey);
	   }
	   
	   else
	   {
			findLeaf(bottomPtr, topPtr, foundFullNode, newKey);
	   
			if(foundFullNode)
			{
				splitNode(topPtr, bottomPtr, root);
				insertIntoChild(topPtr, newKey);
			}
			
			else
			{
				insertIntoLeaf(bottomPtr, newKey);
			}
	   }
	   
   }

   // displays a tree in one of two formats
   // pre: which is either 'i' or 'p'
   //      output is open
   // post: if which is 'i' the tree is displayed inorder
   //       else the tree is displayed showing its tree
   //       structure
   // usage: tree.display (cout, 'p');
   void Two34Tree::display(ostream& output, char which)
   {
	   if(which == 'i')
	   {
			inorder(output, root);
	   }
	   
	   else
	   {
		   pretty(output, root, 1);
	   }
   }



