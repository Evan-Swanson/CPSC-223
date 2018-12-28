//TreeNode.cpp
//Evan Swanson, Ryan Schoenlein
// 3/5/18

#include "TreeNode.h"

//creates an empty tree node 
//post: object is an empty tree node
//usage: TreeNode zags;
TreeNode::TreeNode()
{
   leftChild = nullptr;
   rightChild = nullptr;
   balance = 0;
}

//creates a new tree node with specified contents
//post: object is a new tree node 
//usage: TreeNode zags(theItem, left, right);
TreeNode::TreeNode(const Item& newItem, TreeNode* theLeft, TreeNode* theRight)
{
   item = newItem;
   leftChild = theLeft;
   rightChild = theRight;
   balance = 0;
}
