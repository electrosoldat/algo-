// Code Author : TAVISH CHADHA

#include <iostream>
#include <vector>
#include <map>
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

void verticalOrderPrint(TreeNode*root,int d,map<int,vector<int> >&m)
{
	if(root == NULL)
		return ;

	m[d].push_back(root->data);
	verticalOrderPrint(root->left,d-1,m);
	verticalOrderPrint(root->right,d+1,m);

	return;
}

int main()
{
	// Type your code here.

	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->left->right->right = new TreeNode(8);
	root->right = new TreeNode(3);
	root->right->right = new TreeNode(7);
	root->right->right->right = new TreeNode(9);
	root->right->left = new TreeNode(6);

	map< int,vector<int> >m;
	int d=0;
	verticalOrderPrint(root,d,m);

	for(auto p:m)
	{
		cout << p.first << "-> ";
		for(int x : p.second)
		{
			cout << x << ", ";
		}
		cout << endl;
	}

	return 0;
}