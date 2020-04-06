// Code Author : TAVISH CHADHA

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

class TreeNode
{
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Custom
{
public:
	bool haskey1;
	bool haskey2;
	TreeNode* node;
};

Custom* helper(TreeNode* root, TreeNode*p,TreeNode*q)
{
	// Base case
	if(root == NULL) 
		return NULL;

	Custom* leftans = helper(root->left,p,q);
	Custom* rightans = helper(root->right,p,q);

	if(leftans!=NULL && leftans->node!=NULL)
		return leftans;

	if(rightans!=NULL && rightans->node!=NULL)
		return rightans;

	Custom* result = new Custom();

	if(leftans!=NULL && rightans!=NULL)
	{
		// LCA was not found till now.
		// LCA is found at this node.
		result->node = root;
		result->haskey1 = true;
		result->haskey2 = true;
		return result;
	}
	else if(root->val == p->val) // p is found, now look for q
	{
		result->haskey1 = true;
		// now , check for q in the subtrees of p.

		result->haskey2 = ((leftans)?leftans->haskey2:false || (rightans)?rightans->haskey2:false);

		if(result->haskey1 && result->haskey2)
			result->node = root;

		return result;
	}
	else if(root->val == q->val) // q is found, now look for p
	{
		result->haskey2 = true;
		// now , check for p in the subtrees of q.

		result->haskey1 = ((leftans)?leftans->haskey1:false || (rightans)?rightans->haskey1:false);

		if(result->haskey1 && result->haskey2)
			result->node = root;

		return result;
	}
	// now, we will check for the condition where only one of p and q has been found till now.
	else if(leftans)
		return leftans;
	else if(rightans)
		return rightans;

	// now, we have reached the situation where, neither of p and q are present in the given BT.
	else
	{
		return NULL;
	}
}

TreeNode* LowestCommonAncestor(TreeNode* root, TreeNode*p,TreeNode*q)
{
	Custom * result = helper(root,p,q);
	if(result == NULL)
		return NULL;
	else
		return result->node;
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

int DistanceBWnodes(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if(root == NULL)
	{
		return 0;
	}
	else
	{
		TreeNode* lca = LowestCommonAncestor(root,p,q);
		pair<int,bool> d_p = DistanceFromRoot(root,p);
		pair<int,bool> d_q = DistanceFromRoot(root,q);
		pair<int,bool> d_lca = DistanceFromRoot(root,lca);

		int ans = d_p.first + d_q.first - 2 * d_lca.first;

		return ans;
	}
}

int main()
{
	TreeNode* root = BuildTree();
	TreeNode* p = root->left->right;
	TreeNode* q = root->right->left->right;

	int distance = DistanceBWnodes(root,p,q);
	cout << distance << endl;

	return 0;
}