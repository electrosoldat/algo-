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

pair<int,bool> DistanceFromRoot(TreeNode* root,TreeNode* node)
{
	pair <int, bool > p;
	if(root == NULL)
	{
		p.first = 0;
		p.second = false;
		return p;
	}
	if(root == node)
	{
		p.first = 0;
		p.second = true;
		return p;
	}

	pair<int,bool> left = DistanceFromRoot(root->left,node);
	pair<int,bool> right = DistanceFromRoot(root->right,node);

	if(left.second == true)
	{
		p.first = left.first + 1;
		p.second = true;
	}
	else if(right.second == true)
	{
		p.first = right.first + 1;
		p.second = true;
	}
	else
	{
		p.first = 0;
		p.second = false;
	}

	return p;
}

int main()
{
	// Type your code here.
	TreeNode* root = BuildTree();

	BFS(root);
	cout << endl;

	TreeNode* p = root->right->left->right;
	pair<int,bool> ans = DistanceFromRoot(root,p);
	cout << ans.first ;

	return 0;
}