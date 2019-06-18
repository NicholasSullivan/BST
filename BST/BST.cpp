//
//  BST.cpp
//  Program5BST
//
//  Created by Nicholas Sullivan on 4/15/18.
//  Copyright � 2018 Nicholas Sullivan. All rights reserved.
//

#include "BST.h"
#include <iostream>
#include <iomanip>
using namespace std;

//--- Definition of constructor, creates a new BST with a root of 0.
BST::BST() : myRoot(0)
{}

//--- Definition of empty(), checks to see if root is 0, returns true, otherwise false.
bool BST::empty() const
{
	return myRoot == 0;
}

//--- Definition of search(), searches for value of user's input, returns true if found and false otherwise.
bool BST::search(const int & item) const
{
	TreeNodePointer locptr = myRoot;
	bool found = false;
	while (!found && locptr != 0)
	{
		if (item < locptr->data)       // descend left
			locptr = locptr->Lchild;
		else if (locptr->data < item)  // descend right
			locptr = locptr->Rchild;
		else                           // item found
			found = true;
	}
	return found;
}

//--- Definition of insert(), inserts node with user's input value.
void BST::insert(const int & item)
{
	TreeNodePointer
		locptr = myRoot,   // search pointer
		parent = 0;        // pointer to parent of current node
	bool found = false;     // indicates if item already in BST
	while (!found && locptr != 0)
	{
		parent = locptr;
		if (item < locptr->data)       // descend left
			locptr = locptr->Lchild;
		else if (locptr->data < item)  // descend right
			locptr = locptr->Rchild;
		else                           // item found
			found = true;
	}
	if (!found)
	{                                 // construct node containing item
		locptr = new TreeNode(item);
		if (parent == 0)               // empty tree
			myRoot = locptr;
		else if (item < parent->data)  // insert to left of parent
			parent->Lchild = locptr;
		else                           // insert to right of parent
			parent->Rchild = locptr;
	}
	else
		cout << "Item already in the tree\n";
}

//--- Definition of remove(), removes node of user's input value, or outputs error message if not in tree.
void BST::remove(const int & item)
{
	bool found;                      // signals if item is found
	TreeNodePointer
		x,                            // points to node to be deleted
		parent;                       //    "    " parent of x and xSucc
	search2(item, found, x, parent);

	if (!found)
	{
		cout << "Item not in the BST.\n";
		return;
	}
	//else
	if (found)
	{
		cout << "Item removed from the BST.\n";
	}
	if (x->Lchild != 0 && x->Rchild != 0)
	{                                // node has 2 children
		// Find x's inorder successor and its parent
		TreeNodePointer xSucc = x->Rchild;
		parent = x;
		while (xSucc->Lchild != 0)       // descend left
		{
			parent = xSucc;
			xSucc = xSucc->Lchild;
		}

		// Move contents of xSucc to x and change x
		// to point to successor, which will be removed.
		x->data = xSucc->data;
		x = xSucc;
	} // end if node has 2 children

	// Now proceed with case where node has 0 or 2 child
	TreeNodePointer
		subtree = x->Lchild;             // pointer to a subtree of x
	if (subtree == 0)
		subtree = x->Rchild;
	if (parent == 0)                  // root being removed
		myRoot = subtree;
	else if (parent->Lchild == x)       // left child of parent
		parent->Lchild = subtree;
	else                              // right child of parent
		parent->Rchild = subtree;
	delete x;
}

//--- Definition of inorder()
void BST::inorder(ostream & out) const
{
	inorderAux(out, myRoot);
}

//--- Definition of preorder()
void BST::preorder(ostream & out) const
{
	preorderAux(out, myRoot);
}

//--- Definition of postorder()
void BST::postorder(ostream & out) const
{
	postorderAux(out, myRoot);
}

//--- Definition of graph()
void BST::graph(ostream & out) const
{
	graphAux(out, 0, myRoot);
}

//--- Definition of search2(), for use with remove.
void BST::search2(const int & item, bool & found,
	TreeNodePointer & locptr,
	TreeNodePointer & parent) const
{
	locptr = myRoot;
	parent = 0;
	found = false;
	while (!found && locptr != 0)
	{
		if (item < locptr->data)       // descend left
		{
			parent = locptr;
			locptr = locptr->Lchild;
		}
		else if (locptr->data < item)  // descend right
		{
			parent = locptr;
			locptr = locptr->Rchild;
		}
		else                           // item found
			found = true;
	}
}

//--- Definition of inorderAux(), for use with inorder.
void BST::inorderAux(ostream & out, TreeNodePointer subtreeRoot) const
{
	if (subtreeRoot != 0)
	{
		inorderAux(out, subtreeRoot->Lchild);    // L operation
		out << subtreeRoot->data << "  ";        // V operation
		inorderAux(out, subtreeRoot->Rchild);    // R operation
	}
}

//--- Definition of preorderAux(), for use with preorder.
void BST::preorderAux(ostream & out, TreeNodePointer subtreeRoot) const
{
	if (subtreeRoot != 0)
	{
		out << subtreeRoot->data << "  ";        // V operation
		preorderAux(out, subtreeRoot->Lchild);    // L operation
		preorderAux(out, subtreeRoot->Rchild);    // R operation
	}
}

//--- Definition of postorderAux(), for use with postorder.
void BST::postorderAux(ostream & out, TreeNodePointer subtreeRoot) const
{
	if (subtreeRoot != 0)
	{
		postorderAux(out, subtreeRoot->Lchild);    // L operation
		postorderAux(out, subtreeRoot->Rchild);    // R operation
		out << subtreeRoot->data << "  ";        // V operation
	}
}

//--- Definition of graphAux(), for use with graph.
void BST::graphAux(ostream & out, int indent, TreeNodePointer subtreeRoot) const
{
	if (subtreeRoot != 0)
	{
		graphAux(out, indent + 8, subtreeRoot->Rchild);
		out << setw(indent) << " " << subtreeRoot->data << endl;
		graphAux(out, indent + 8, subtreeRoot->Lchild);
	}
}
