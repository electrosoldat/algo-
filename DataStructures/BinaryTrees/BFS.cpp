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
	while(!q_bfs.empty())
	{
		// 1. Pick the node at the front of the node.
		TreeNode* cur_node = q_bfs.front();
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

int main()
{
	// Type your code here.
	TreeNode* root = BuildTree();
	PrintPREORDER(root);
	cout << endl;

	BFS(root);

	return 0;
}