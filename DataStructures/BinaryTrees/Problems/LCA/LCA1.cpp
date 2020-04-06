// Code Author : TAVISH CHADHA

#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
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

bool checkAnc(TreeNode* target, TreeNode* root, vector<TreeNode*> &target_anc)
{
	if(root == NULL)
		return false;
	if(root == target)
	{
		target_anc.push_back(root);
		return true;
	}

	if(checkAnc(target,root->left,target_anc) || checkAnc(target,root->right,target_anc))
	{
		target_anc.push_back(root);
		return true;
	}

	return false; // else, return false.
}


TreeNode* LCA(TreeNode*p,TreeNode*q,TreeNode*root)
{
	vector <TreeNode*> p_anc, q_anc, common_anc; // these vectors will contain all the ancestors of p and q resp

	checkAnc(p,root,p_anc);
	checkAnc(q,root,q_anc);

	int min_size = min(p_anc.size(),q_anc.size());
	int j=min_size;

	for(int i=0;i<min_size && j>=0;i++)
	{
		if(p_anc[i]==q_anc[i])
		{
			j-- ;
			common_anc[j] = p_anc[i];
		}
	}

	if(j!=-1)
		return common_anc[j];
	else
		return NULL;

}

int main()
{
	// Type your code here.
	TreeNode* root = BuildTree();

	BFS(root);
	cout << endl;

	TreeNode* p;
	TreeNode* q;
	p = root->left->left->right;
	q = root->left->right->right;

	TreeNode* ans = LCA(p,q,root);

	cout << ans->data << endl;



	return 0;
}