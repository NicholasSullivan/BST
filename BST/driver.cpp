//
//  driver.cpp
//  Program5BST
//
//  Created by Nicholas Sullivan on 4/15/18.
//  Copyright � 2018 Nicholas Sullivan. All rights reserved.
//

// *** Driver to test BST ***

#include <iostream>
using namespace std;
#include "BST.h"

int main(int argc, const char * argv[]) {

	// variables
	bool isValid = false; // for error checking loop.
	int number; // for user input.

	// Testing Constructor and empty()
	BST intBST;            // test the class constructor
	cout << "***Constructing empty BST***\n\n";
	cout << "BST " << (intBST.empty() ? "is" : "is not") << " empty:\n";

	// Testing preorder
	cout << "Preorder Traversal of BST: \n";
	intBST.preorder(cout);
	// Testing inorder
	cout << "Inorder Traversal of BST: \n";
	intBST.inorder(cout);
	// Testing postorder
	cout << "Postorder Traversal of BST: \n";
	intBST.postorder(cout);

	// Testing insert
	cout << endl << endl;
	cout << "Now insert a bunch of integers into the BST (-999 to stop)." << endl;
	number = 0;
	for (;;)
	{
		if (number == -999) break;
		while (!isValid)
		{
			isValid = false;
			cout << "Item to insert: ";
			cin >> number;
			if (number == -999) break;
			else if (!cin)
			{
				cout << "*** Invalid Input ***" << endl;
				cin.clear();
				cin.ignore(999, '\n');
			}
			else
			{
				isValid = true;
				intBST.insert(number);
				cout << "Inserted number " << number << " into the BST." << endl;
				cin.clear();
				cin.ignore(999, '\n');
			}
		}
		isValid = false;
	}

	cout << endl << endl;
	intBST.graph(cout); // output a graphical representation of the BST.

	// show all ordering of tree with inserted values.
	cout << "\n\nBST " << (intBST.empty() ? "is" : "is not") << " empty:\n";
	cout << "Preorder Traversal of BST: \n";
	intBST.preorder(cout);
	cout << "\nInorder Traversal of BST: \n";
	intBST.inorder(cout);
	cout << "\nPostorder Traversal of BST: \n";
	intBST.postorder(cout);

	cout << endl;

	// Testing search()
	cout << "\n\nNow testing the search() operation (-999 to stop)."
		"\nTry both items in the BST and some not in it:\n";
	number = 0;
	for (;;)
	{
		if (number == -999) break;
		while (!isValid)
		{
			isValid = false;
			cout << "Item to find: ";
			cin >> number;
			if (number == -999) break;
			else if (!cin)
			{
				cout << "*** Invalid Input ***" << endl;
				cin.clear();
				cin.ignore(999, '\n');
			}
			else
			{
				isValid = true;
				if (intBST.search(number))
				{
					cout << number << " was found." << endl;
				}
				else
				{
					cout << number << " was NOT found." << endl;
				}
				cin.clear();
				cin.ignore(999, '\n');
			}
		}
		isValid = false;
	}

	// Testing remove()
	cout << "\nNow testing the remove() operation (-999 to stop)."
		"\nTry both items in the BST and some not in it:\n";
	number = 0;
	for (;;)
	{
		if (number == -999) break;
		while (!isValid)
		{
			isValid = false;
			cout << "Item to remove: ";
			cin >> number;
			if (number == -999) break;
			else if (!cin)
			{
				cout << "*** Invalid Input ***" << endl;
				cin.clear();
				cin.ignore(999, '\n');
			}
			else
			{
				isValid = true;
				intBST.remove(number);
				//cout << "Removed number " << number << " from the BST." << endl;
				cin.clear();
				cin.ignore(999, '\n');
			}
		}
		isValid = false;
	}

	cout << endl << endl;
	intBST.graph(cout);// output a graphical representation of the BST.

	// show all ordering of tree with removed values.
	cout << "\nPreorder Traversal of BST: \n";
	intBST.preorder(cout);
	cout << endl;
	cout << "Inorder Traversal of BST: \n";
	intBST.inorder(cout);
	cout << endl;
	cout << "Postorder Traversal of BST: \n";
	intBST.postorder(cout);
	cout << endl;
}
