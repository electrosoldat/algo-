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

int main()
{
	// Type your code here.
	TreeNode* root = BuildTree();
	PrintPREORDER(root);
	cout << endl;
	PrintINORDER(root);
	cout << endl;
	PrintPOSTORDER(root);

	return 0;
}