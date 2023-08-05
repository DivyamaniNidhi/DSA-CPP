/*Given BST is a complete binary tree. Convert it into min heap*/

class Solution {
  public:
    void inorderTraversal(Node* root, vector<int>& in) {
        if(root == NULL)
            return;
        
        inorderTraversal(root->left, in);
        in.push_back(root->data);
        inorderTraversal(root->right, in);
    }
    
    void inorderToMinHeap(Node* root, vector<int> in, int &i) {
        if(root == NULL)
            return;
        
        root->data = in[i++];
        inorderToMinHeap(root->left, in, i);
        inorderToMinHeap(root->right, in, i);
    }

    void BSTtoMinHeap(Node* root) {
        // step 1 - inorder traversal of bst
        vector<int> in;
        inorderTraversal(root, in);

        //Step 2 - inorder to min heap
        int i = 0;
        inorderToMinHeap(root, in, i);
    }
};