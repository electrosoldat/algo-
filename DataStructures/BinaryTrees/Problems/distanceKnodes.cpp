// Code Author : TAVISH CHADHA

#include <iostream>
#include <queue>
#include <vector>
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

vector <int> result;

void traverseDownforTarget(TreeNode* root, int K)
{
	// Base case
	if(root == NULL || K<0) 
		return;

	// Recursive case
	if(K==0) // i.e. we have reached the K distance node.
	{
		result.push_back(root->data);
		return;
	}

	else // if not reached, then check for the same in the left and the right subtrees.
	{
		traverseDownforTarget(root->left,K-1);
		traverseDownforTarget(root->right,K-1);
	}
}

int KdistanceNodes(TreeNode* root , int K, TreeNode* target)
{
	if(root == NULL)
		return -1;

	if(root == target)
	{
		traverseDownforTarget(root,K);
		return 0;
	}

	else
	{
		// check for the left subtree.
		int L = KdistanceNodes(root->left,K,target);

		if(L != -1) // check if the target node is found in the left subtree.
		{
			if(L+1 == K) // the ancestor is at distance K.
				result.push_back(root->data);
			else
			{   // check for the target in the right subtree of the ancestor.
				traverseDownforTarget(root->right,K-L-2);
			}

			return L+1;
		}

		// check for the right subtree
		int R = KdistanceNodes(root->right,K,target);
		if(R != -1) // check if the target node is found in the right subtree
		{
			if(R+1 == K)
				result.push_back(root->data);
			else
			{
				traverseDownforTarget(root->left,K-R-2);
			}

			return R+1;
		}

		// if the target was not found in the left and the right subtrees, then 
		return -1;
	}
}

int main()
{
	// Type your code here.
	TreeNode* root = BuildTree();

	BFS(root);
	cout << endl;

	KdistanceNodes(root,3,root->left->right);

	for(int i=0;i<result.size();i++)
	{
		cout << result[i] << " ";
	}

	return 0;
}