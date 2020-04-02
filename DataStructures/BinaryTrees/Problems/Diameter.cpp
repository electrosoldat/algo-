// Code Author : TAVISH CHADHA

#include <iostream>
#include <cmath>
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

int height(TreeNode* root)
{
	if(root == NULL)
		return 0;

	int h1 = height(root->left);
	int h2 = height(root->right);

	int h = max(h1,h2) + 1;

	return h;
}

int Diameter(TreeNode* root)
{
	if(root == NULL)
		return 0;

	int hl = height(root->left);
	int hr = height(root->right);

	int op1 = hl + hr;
	int op2 = Diameter(root->left);
	int op3 = Diameter(root->right);
	
	int ans1 = max(op1,op2);
	int ans = max(op3,ans1);

	return ans;
}

int main()
{
	// Type your code here.
	TreeNode* root = BuildTree();
	PrintPREORDER(root);
	cout << endl;

	int d = Diameter(root);
	cout << d << endl;


	return 0;
}