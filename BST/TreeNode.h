//
//  TreeNode.h
//  Program5BST
//
//  Created by Nicholas Sullivan on 4/15/18.
//  Copyright � 2018 Nicholas Sullivan. All rights reserved.
//

#ifndef TREENODE_H_INCLUDED
#define TREENODE_H_INCLUDED

#include <stdio.h>
using namespace std;

class TreeNode {
	friend class BST;
public:
	TreeNode(); //default constructor
	TreeNode(int i, TreeNode* L, TreeNode* R); //explicit value constructor
	int getData() const; // accessor function

private:
	int data;
	TreeNode *Lchild;
	TreeNode *Rchild;
}; // end class TreeNode

inline TreeNode::TreeNode()
{
	Lchild = Rchild = NULL;
}

inline TreeNode::TreeNode(int i, TreeNode *L = 0, TreeNode *R = 0) : data(i), Lchild(L), Rchild(R)
{}

inline int TreeNode::getData() const
{
	return data;
}

#endif // TREENODE_H_INCLUDED
