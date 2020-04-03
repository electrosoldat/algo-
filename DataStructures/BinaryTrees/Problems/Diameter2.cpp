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

class Pair_hd
{
public:
	int h; // height
	int d; // diameter
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

Pair_hd FastDiameter(TreeNode* root)
{
	Pair_hd p;
	if(root == NULL)
	{
		p.h = 0;
		p.d = 0;
		return p;
	}

	Pair_hd pLeft = FastDiameter(root->left);
	Pair_hd pRight = FastDiameter(root->right);

	p.h = max(pLeft.h,pRight.h) + 1;
	p.d = max(pLeft.h+pRight.h,max(pLeft.d,pRight.d));

	return p;
}

int main()
{
	// Type your code here.
	TreeNode* root = BuildTree();
	PrintPREORDER(root);
	cout << endl;

	Pair_hd ans = FastDiameter(root);
	cout << ans.d << endl;


	return 0;
}