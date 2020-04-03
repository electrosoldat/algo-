// Code Author : TAVISH CHADHA

// In this problem, we have to build a height balanced tree using the given array.

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

class TreeNode
{
public:
	int data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int d)
	{
		this->data = d;
		this->left = NULL;
		this->right = NULL;
	}
};

TreeNode* BuildTree()
{
	int d;
	cin >> d;

	if(d==-1)
		return NULL;

	TreeNode* root = new TreeNode(d);
	root->left = BuildTree();
	root->right = BuildTree();

	return root;
}

void BFS(TreeNode* root)
{
	queue<TreeNode*> q_bfs;
	q_bfs.push(root);
	q_bfs.push(NULL);

	while(!q_bfs.empty())
	{
		// 1. Pick the node at the front of the node.
		TreeNode* cur_node = q_bfs.front();
		if(cur_node == NULL)
		{
			cout << endl;
			q_bfs.pop();
			if(!q_bfs.empty())
				q_bfs.push(NULL);
		}
		
		else
		{
			cout << cur_node->data << " ";
			// 2. Pop the element at the front.
			q_bfs.pop();
			// 3. Push the children of the element just popped.
			if(cur_node->left)
				q_bfs.push(cur_node->left);

			if(cur_node->right)
				q_bfs.push(cur_node->right);
		}
	}
}

TreeNode* BuildTreeFromArray(int* a, int s, int e)
{
	if(s>e)
		return 	NULL;

	int mid = (s+e)/2;
	TreeNode* root = new TreeNode(a[mid]);
	root->left = BuildTreeFromArray(a,s,mid-1);
	root->right = BuildTreeFromArray(a,mid+1,e);

	return root;
}

int main()
{
	// Type your code here.
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	int n = 10;
	TreeNode* root = BuildTreeFromArray(a,0,n-1);

	BFS(root);
	cout << endl;





	return 0;
}