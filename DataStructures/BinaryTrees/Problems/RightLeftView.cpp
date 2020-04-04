// Code Author : TAVISH CHADHA

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class TreeNode
{
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	vector <int> v;
	int max_level = -1;

	void helperR(TreeNode* root, int level)
	{
		if(root == NULL) return;
		if(max_level < level)
		{
			max_level = level;
			v.push_back(root->val);
		}
		helperR(root->right,level+1);
		helperR(root->left,level+1);
	}

	void helperL(TreeNode* root, int level)
	{
		if(root == NULL) return;
		if(max_level < level)
		{
			max_level = level;
			v.push_back(root->val);
		}

		helperL(root->left,level+1);
		helperL(root->right,level+1);
		
	}

	vector <int> rightSideView(TreeNode* root)
	{
		// logic
		helperR(root,0);
		return v;
	}

	vector <int> leftSideView(TreeNode* root)
	{
		helperL(root,0);
		return v;
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
			cout << cur_node->val << " ";
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

int main()
{
	// Type your code here.

	Solution sr,sl;
	TreeNode* root = BuildTree();
	vector <int> ansR = sr.rightSideView(root);
	vector <int> ansL = sl.leftSideView(root);

	BFS(root);
	cout << endl;

	cout << "Right Side View" << endl;
	for(int i=0;i<ansR.size();i++)
	{
		cout << ansR[i] << endl;
	}

	cout << "Left Side View" << endl;
	for(int i=0;i<ansL.size();i++)
	{
		cout << ansL[i] << endl;
	}


	return 0;
}