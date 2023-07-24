#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure:

    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };

*************************************************************/

void inorderTraversal(TreeNode<int>* root, vector<int>& inorder){
    if(root == NULL){
        return;
    }

    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
}

vector<int> mergedArray(vector<int> a, vector<int> b){
    vector<int> ans(a.size()+b.size());
    int i = 0, j = 0, k = 0;
    while(i < a.size() && j < b.size()){
        if(a[i] < b[j]){
            ans[k++] = a[i];
            i++;
        }
        else {
            ans[k++] = b[j];
            j++;
        }
    }
        
    while(i < a.size()){
        ans[k++] = a[i];
        i++;
    }
        
    while(j < b.size()){
        ans[k++] = b[j];
        j++;
    }
        
    return ans;
}

TreeNode<int>* inorderToBST(int s, int e, vector<int> v){
    if(s > e) {
        return NULL;
    }
    int mid = (s+e)/2;
    TreeNode<int>* root = new TreeNode<int>(v[mid]);
    root->left = inorderToBST(s, mid-1, v);
    root->right = inorderToBST(mid+1, e, v);
    return root;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    vector<int> in1;
    vector<int> in2;
    inorderTraversal(root1, in1);
    inorderTraversal(root2, in2);

    vector<int> inorder = mergedArray(in1, in2);
    return inorderToBST(0, inorder.size()-1, inorder);
}