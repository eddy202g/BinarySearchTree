// BST.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

using namespace std;


int i = 0; // Global variable for counting insertion steps
int y = 0; // Global variable for counting search steps

// Struct creates the root node, assigning the fields to be used for the node.
// Holds data, and left and right are fields that will store a reference to the let and right fields
struct bstNode
{
	int data;
	bstNode* left;
	bstNode* right;
};

// This method creaes a new node in memory. A pointer to new node is created, data is inserted to 
// the node, and the left and right fields are set to null. The method returns the address of the new node
bstNode* getNewNode(int data)
{
	bstNode* newNode = new bstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;

	return newNode;
}

// This function takes in the root pointer and data to be inserted. If the tree is empty, a new node will
// be created. If data to be inserted is <= data in root, insert data in left side of node. Or if data is greater, 
// insert into right side of node. 
bstNode* insert(bstNode* root, int data)
{
	if (root == NULL)
	{

		root = getNewNode(data);
	}

	else if (data <= root->data)
	{
		root->left = insert(root->left, data);
	}
	else
	{
		root->right = insert(root->right, data);
	}

	return root;
}

// Similar to the above function, but has a counter added to count the steps to insert a puece of data
bstNode* insertWithCount(bstNode* root, int data)
{
	if (root == NULL)
	{
		root = getNewNode(data);
	}

	else if (data <= root->data)
	{
		root->left = insertWithCount(root->left, data);
		i++;
	}

	else
	{
		root->right = insertWithCount(root->right, data);
		i++;
	}

	return root;
}

// Function will search from root, if the data is present in the tree will rturn true, 
// if data is missing, will return false. Has a counter added to cound the steps to search for a 
// piece of data
bool search(bstNode* root, int data)
{
	if (root == NULL)
	{
		return false;
	}
	else if (root->data == data)
	{
		y++;
		return true;
	}
	else if (data <= root->data)
	{
		y++;
		return search(root->left, data);
	}
	else
	{
		y++;
		return search(root->right, data);
	}
}

// This function takes in the pointer to root, starts from the left side then traverses to the right
// and prints the data set in ascending order
void inorder(bstNode* root)
{
	if (root->left != NULL)
		inorder(root->left);
	cout << root->data << endl;
	if (root->right != NULL)
		inorder(root->right);
}




// The main function holds the pointer to the root node, a small menu tochosse froma a data scenario, 
// allows the user to input a number into the data set for the purpose of calculating steps and prints
// the inOrder function. The data scenarios allow the user to enter a number to search the tree with, 
// if the data is present returns true, otherwise returns false.
int main()
{
	int number;
	int numInsert;
	int option;
	bstNode* root = NULL; // Pointer to root node, sets up empty tree


	cout << "1: Best Case Scenario \n";
	cout << "2: Worst Case Scenario \n";
	cout << "Enter number for scenario: \n";
	cin >> option;

	switch (option)
	{
	case 1:
	{
		root = insert(root, 15);
		root = insert(root, 10);
		root = insert(root, 20);
		root = insert(root, 25);
		root = insert(root, 8);
		root = insert(root, 12);
		root = insert(root, 19);
		root = insert(root, 11);
		root = insert(root, 22);
		root = insert(root, 26);
		root = insert(root, 7);
		root = insert(root, 13);
		root = insert(root, 18);
		root = insert(root, 9);
		root = insert(root, 21);
		root = insert(root, 27);
		root = insert(root, 5);
		root = insert(root, 1);
		root = insert(root, 17);
		root = insert(root, 4);

		root = insert(root, 98);
		root = insert(root, 63);
		root = insert(root, 81);
		root = insert(root, 62);
		root = insert(root, 100);
		root = insert(root, 33);
		root = insert(root, 52);
		root = insert(root, 93);
		root = insert(root, 46);
		root = insert(root, 80);
		root = insert(root, 101);
		root = insert(root, 30);
		root = insert(root, 99);
		root = insert(root, 102);



		cout << "Enter number to be searched: ";
		cin >> number;
		cout << "\n";

		if (search(root, number) == true)
		{
			cout << "Found in " << y << " steps\n";
		}
		else
		{
			cout << "Not Found\n";
		}

		cout << "Enter number to be inserted: \n";
		cin >> numInsert;

		root = insertWithCount(root, numInsert);

		cout << "Count: " << i << "\n";


	}
	break;

	case 2:
	{
		root = insert(root, 1);
		root = insert(root, 2);
		root = insert(root, 3);
		root = insert(root, 4);
		root = insert(root, 5);
		root = insert(root, 6);
		root = insert(root, 7);
		root = insert(root, 8);
		root = insert(root, 9);
		root = insert(root, 10);
		root = insert(root, 11);
		root = insert(root, 12);
		root = insert(root, 13);
		root = insert(root, 14);
		root = insert(root, 15);
		root = insert(root, 16);
		root = insert(root, 17);
		root = insert(root, 18);
		root = insert(root, 19);
		root = insert(root, 20);
		root = insert(root, 21);
		root = insert(root, 22);
		root = insert(root, 23);
		root = insert(root, 24);
		root = insert(root, 25);
		root = insert(root, 26);
		root = insert(root, 27);
		root = insert(root, 28);
		root = insert(root, 29);
		root = insert(root, 30);
		root = insert(root, 31);
		root = insert(root, 32);
		root = insert(root, 33);
		root = insert(root, 34);

		cout << "Enter number to be searched: ";
		cin >> number;
		cout << "\n";

		if (search(root, number) == true)
		{
			cout << "Found in " << y << " steps\n";
		}
		else
		{
			cout << "Not Found\n";
		}

		cout << "Enter number to be inserted: \n";
		cin >> numInsert;

		root = insertWithCount(root, numInsert);

		cout << "Count: " << i << "\n";
	}
	break;
	}

	cout << "Enter number to be inserted: \n";
	cin >> numInsert;

	root = insertWithCount(root, numInsert);

	cout << "Count: " << i << "\n";

	inorder(root);

	cin.get();
	cin.ignore();
	return 0;
}



