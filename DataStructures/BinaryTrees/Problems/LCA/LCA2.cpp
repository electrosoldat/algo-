// Code Author : TAVISH CHADHA

#include <iostream>
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

int main()
{
	// Type your code here.
	TreeNode* root = BuildTree();
	TreeNode* p = root->right->left->right;
	TreeNode* q = root->left->right;

	TreeNode* lca_ans = LowestCommonAncestor(root,p,q);
	cout << lca_ans->val;
	return 0;
}