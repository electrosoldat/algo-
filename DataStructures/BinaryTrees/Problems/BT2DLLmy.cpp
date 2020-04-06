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

class DLLpair
{
public:
	TreeNode* head;
	TreeNode* tail;
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

DLLpair BT2DLL(TreeNode* root)
{
	DLLpair p;
	if (root == NULL)
	{
		p.head = NULL;
		p.tail = NULL;
		return p;
	}

	// in case of a leaf node
	if(root->left == NULL && root->right == NULL)
	{
		p.head = root;
		p.tail = root;
		return p;
	}
	
	// in case RST is not there
	if(root->left != NULL && root->right == NULL)
	{
		DLLpair leftDLL = BT2DLL(root->left);
		p.head = leftDLL.head;
		leftDLL.tail->right = root;
		root->left = leftDLL.tail;
		p.tail = root;
		return p;
	}

	// in case LST is not there
	if(root->left == NULL && root->right != NULL)
	{
		DLLpair rightDLL = BT2DLL(root->right);
		root->right = rightDLL.head;
		rightDLL.head->left = root;
		p.tail = rightDLL.tail;
		p.head = root;
		return p;
	}

	// in case both LST and RST are present
	if(root->left!= NULL && root->right!=NULL)
	{
		DLLpair leftDLL = BT2DLL(root->left);
		DLLpair rightDLL = BT2DLL(root->right);
		leftDLL.tail->right = root;
		root->left = leftDLL.tail;
		p.head = leftDLL.head;
		root->right = rightDLL.head;
		rightDLL.head->left = root;
		p.tail = rightDLL.tail;
		return p;
	}
}

int main()
{
	// Type your code here.
	TreeNode* root = BuildTree();

	BFS(root);
	cout << endl;

	DLLpair ans = BT2DLL(root);

	PrintDLL(ans.head);
	cout << endl;

	return 0;
}