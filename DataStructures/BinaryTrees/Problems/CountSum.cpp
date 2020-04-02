// Code Author : TAVISH CHADHA

#include <iostream>
using namespace std;

class TreeNode
{
public:
	int data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};

TreeNode* BuildTree()
{
	int d;
	cin >> d;

	if(d == -1)
		return NULL;

	TreeNode* root = new TreeNode(d);
	root->left = BuildTree();
	root->right = BuildTree();

	return root;
}

void PrintPREORDER(TreeNode* root)
{
	if(root == NULL)
	{
		return;
	}

	cout << root->data << " ";
	PrintPREORDER(root->left);
	PrintPREORDER(root->right);
}

void PrintINORDER(TreeNode* root)
{
	if(root == NULL)
		return;

	PrintINORDER(root->left);
	cout << root->data << " ";
	PrintINORDER(root->right);
}

void PrintPOSTORDER(TreeNode* root)
{
	if(root == NULL)
		return;

	PrintPOSTORDER(root->left);
	PrintPOSTORDER(root->right);
	cout << root->data << " ";
}

int count_node(TreeNode* root)
{
	if(root == NULL)
		return 0;
	else
	{
		return 1 + count_node(root->left) + count_node(root->right);
	}
}

int sum_node(TreeNode* root)
{
	if(root == NULL)
		return 0;
	else
	{
		return root->data + sum_node(root->left) + sum_node(root->right);
	}
}

int main()
{
	// Type your code here.
	TreeNode* root = BuildTree();
	PrintPREORDER(root);
	cout << endl;
	PrintINORDER(root);
	cout << endl;
	PrintPOSTORDER(root);
	cout << endl;

	int n_of_nodes = count_node(root);
	cout << n_of_nodes << endl;

	int sum_of_nodes = sum_node(root);
	cout << sum_of_nodes << endl;

	return 0;
}