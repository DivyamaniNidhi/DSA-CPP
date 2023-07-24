#include <bits/stdc++.h> 
/***********************************************************

	Following is the Binary Tree node structure:

	class binaryTreeNode{

	public :
		int data ;
		binaryTreeNode* left ;
		binaryTreeNode* right;

		binaryTreeNode(int data)
		{
			this -> data = data;
			this -> left = NULL;
			this -> right = NULL;
		}
	};

*********************************************************/

vector<int> findPreSuc(binaryTreeNode *root, int key)
{
	int pred = -1;
	int succ = -1;

	//find key
	binaryTreeNode* temp = root;

	while(temp->data != key){
		if(temp->data > key){
			succ = temp->data;
			temp = temp->left;
		}
		else{
			pred = temp->data;
			temp = temp->right;
		}

	}

	//predecessor
	binaryTreeNode* leftTree = temp->left;
	while(leftTree != NULL){
		pred = leftTree -> data;
		leftTree = leftTree->right;
	}

	//successor
	binaryTreeNode* rightTree = temp->right;
	while(rightTree != NULL){
		succ = rightTree -> data;
		rightTree = rightTree->left;
	}

	vector<int> ans;
	ans.push_back(pred);
	ans.push_back(succ);

	return ans;
}