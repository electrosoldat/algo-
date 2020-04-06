// Code Author : TAVISH CHADHA

#include <iostream>
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
		data = d;
		left = NULL;
		right = NULL;
	}
};

class Solution
{
	public:
	TreeNode* prev;
	TreeNode* head;
	void BT2DLL(TreeNode* root)
	{
		if(root == NULL)
			return;

		BT2DLL(root->left);
		if(prev == NULL)
		{
			head = root;
		}
		else
		{
			root->left = prev;
			prev->right = root;
			prev = root;
			BT2DLL(root->right);
		}
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

void PrintDLL(TreeNode* head)
{
	if(head == NULL)
		return;

	cout << head->data << " ";
	PrintDLL(head->right);
}

int main()
{
	// Type your code here.
	TreeNode* root = BuildTree();

	BFS(root);
	cout << endl;

	Solution s;
	s.BT2DLL(root);

	PrintDLL(root);
	cout << endl;


	return 0;
}