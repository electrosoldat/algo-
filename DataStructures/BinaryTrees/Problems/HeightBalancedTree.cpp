// Code Author : TAVISH CHADHA

// In this problem, we have to check if the given tree is a height balanced tree or not.
// Height Balanced Tree --> if(abs(h1 - h2)) >= 1;

#include <iostream>
#include <cmath>
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

class HBPair
{
public:
	int height;
	bool balanced;
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

HBPair isHeightBalanced(TreeNode* root)
{
	HBPair p;
	if(root == NULL)
	{
		p.height = 0;
		p.balanced = true;
		return p;
	}

	else
	{
		HBPair left = isHeightBalanced(root->left);
		HBPair right = isHeightBalanced(root->right);

		p.height = max(left.height, right.height) + 1;

		if((abs(left.height - right.height) <= 1) && left.balanced && right.balanced)
		{
			p.balanced = true;
		}
		else
			p.balanced = false;

		return p;
	}
}

int main()
{
	// Type your code here.
	TreeNode* root = BuildTree();

	BFS(root);
	cout << endl;

	HBPair ans = isHeightBalanced(root);

	if(ans.balanced)
		cout << "Balanced Tree" << endl;

	else
		cout << "Unbalanced Tree" << endl;

	return 0;
}