//
//  BST.h
//  Program5BST
//
//  Created by Nicholas Sullivan on 4/15/18.
//  Copyright � 2018 Nicholas Sullivan. All rights reserved.
//

#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

#include <stdio.h>
#include <iostream>
#include "TreeNode.h"
using namespace std;


class BST
{
public:

	/***** Function Members *****/
	BST();
	bool empty() const;
	bool search(const int & item) const;
	void insert(const int & item);
	void remove(const int & item);
	void inorder(ostream & out) const;
	void preorder(ostream & out) const;
	void postorder(ostream & out) const;
	void graph(ostream & out) const;

private:
	typedef TreeNode * TreeNodePointer;

	/*** Utility Functions Members ***/
	void search2(const int & value, bool & found, TreeNodePointer & locptr, TreeNodePointer & parent) const;
	void inorderAux(ostream & out, TreeNodePointer subtreePtr) const;
	void preorderAux(ostream & out, TreeNodePointer subtreePtr) const;
	void postorderAux(ostream & out, TreeNodePointer subtreePtr) const;
	void graphAux(ostream & out, int indent, TreeNodePointer subtreeRoot) const;

	/***** Data Members *****/
	TreeNodePointer myRoot; // pointer to root of BST

}; // end of class BST declaration

#endif // BST_H_INCLUDED
