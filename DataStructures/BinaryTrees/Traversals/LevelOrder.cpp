// Code Author : TAVISH CHADHA

#include <iostream>
using namespace std;

class Treenode
{
public:
	int data;
	Treenode* left;
	Treenode* right;

	Treenode(int d)
	{
		data = d;
		this->left = NULL;
		this->right = NULL;
	}
};

Treenode* Buildtree()
{
	int d;
	cin >> d;

	if(d == -1)
		return NULL;

	Treenode* root = new Treenode(d);
	root->left = Buildtree();
	root->right = Buildtree();

	return root;
}

void PrintPREORDER(Treenode* root)
{
	if(root == NULL)
	{
		return;
	}

	cout << root->data << " ";
	PrintPREORDER(root->left);
	PrintPREORDER(root->right);
}

int height(Treenode* root)
{
	if(root == NULL)
		return 0;

	int h1 = height(root->left);
	int h2 = height(root->right);

	int h = max(h1,h2) + 1;

	return h;
}

void PrintKthLevel(Treenode* root, int k)
{
	if(root == NULL)
	{
		return;
	}

	if(k==1)
	{
		cout << root->data << " ";
		return;
	}

	PrintKthLevel(root->left , k-1);
	PrintKthLevel(root->right , k-1);

	return;

}

void PrintLevelOrder(Treenode* root)
{
	int h = height(root);  

	for(int i=1;i<=h;i++)
	{
		PrintKthLevel(root,i);
		cout << endl;
	}

	return;
}

int main()
{
	// Type your code here.
	Treenode* root = Buildtree();

	PrintPREORDER(root);
	cout << endl;

	PrintLevelOrder(root);

	return 0;
}