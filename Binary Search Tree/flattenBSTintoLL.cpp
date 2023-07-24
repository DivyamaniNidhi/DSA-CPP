#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void inorderTraversal(TreeNode<int>* root, vector<int>& inorder){
        if(root == NULL){
            return;
        }

        inorderTraversal(root->left, inorder);
        inorder.push_back(root->data);
        inorderTraversal(root->right, inorder);
    }
TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int> inorder;
    inorderTraversal(root, inorder);
    int n = inorder.size();
    TreeNode<int>* newRoot = new TreeNode<int>(inorder[0]);
    TreeNode<int>* curr = newRoot;

    for(int i = 1; i < n; i++){
        TreeNode<int>* temp = new TreeNode<int>(inorder[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    curr->left = NULL;
    curr->right = NULL;

    return newRoot;
}
