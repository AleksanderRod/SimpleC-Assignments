// Author: Aleksander Rodriguez
// Course: COSC 2436
// Program Set 3
// References: https://www.techiedelight.com/insertion-in-bst/  Was used to create a binary tree using a struct
//https://www.geeksforgeeks.org/check-if-two-trees-have-same-structure/amp/ Used to see if the trees are the same 

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Data structure to store a BST node
struct Node
{
	int data;
	Node* left = nullptr, * right = nullptr;

	Node() {}
	Node(int data) : data(data) {}
};

// Function to perform inorder traversal on the tree


// Recursive function to insert a key into a BST using a reference parameter
// call as insert(root, key);
void insert(Node*& root, int key)
{
	// if the root is null, create a new node and return it
	if (root == nullptr)
	{
		root = new Node(key);
		return;
	}

	// if the given key is less than the root node, recur for the left subtree;
	// otherwise, recur for the right subtree
	if (key < root->data) {
		insert(root->left, key);
	}
	// key >= root->data
	else {
		insert(root->right, key);
	}
}

// Function to construct a BST from given keys
Node* constructBST(vector<int> const& keys)
{
	Node* root = nullptr;
	for (int key : keys) {
		insert(root, key);
	}
	return root;
}


int isSameStructure(Node* a, Node* b)
{

	// 1. both empty 

	if (a == NULL && b == NULL)

		return 1;

	// 2. both non-empty -> compare them 

	if (a != NULL && b != NULL)

	{

		return

			(isSameStructure(a->left, b->left) &&

				isSameStructure(a->right, b->right));

	}

	// 3. one empty, one not -> false 

	return 0;
}

int main()
{
	char yes = 'y';
	int insertNum = 0;
	int Case = 0;
	string tree1;
	string tempTree;
	string tree2;
	string tempTree2;
	do {

		if (Case >= 1)
		{
			cin.ignore();
		}
		Case++;
		vector<int> keys;
		vector<int> keys2;
		

		cout << "Enter tree 1: ";
		getline(cin, tree1);
		cout << "Enter tree 2: ";
		getline(cin, tree2);

		// turns string into int values for the binary tree 1
		for (int x = 0; x < tree1.size(); x++)
		{
			if ((tree1[x] >= '1' && tree1[x] <= '9') || tree1[x] <= '0')
			{
				tempTree += tree1[x];
			}

			if (tree1[x] == ' ' || (x + 1) == tree1.size())
			{
				

				insertNum = stoi(tempTree);
				keys.push_back(insertNum);

				tempTree.clear();
			}
		}
		// turns string into int values for the binary tree 2
		for (int x = 0; x < tree2.size(); x++)
		{
			if ((tree2[x] >= '1' && tree2[x] <= '9') || tree2[x] <= '0')
			{
				tempTree += tree2[x];
			}

			if (tree2[x] == ' ' || (x + 1) == tree2.size())
			{


				insertNum = stoi(tempTree);
				keys2.push_back(insertNum);

				tempTree.clear();
			}
		}


		// send the keys to for each tree 
		Node* root = constructBST(keys);
		Node* root2 = constructBST(keys2);

		
		cout << endl;
		
		// if the are the same the if statment will output "Same Stucture." otherwise "Not Same Structure.
		if (isSameStructure(root, root2))
			cout << "Same structure." << endl;

		else
			cout << "Not same structure." << endl;

		cout << endl << "Run Again (Y/N): ";
		cin >> yes;
		cout << endl << endl;

	} while (yes == 'Y' || yes == 'y');
	return 0;
}