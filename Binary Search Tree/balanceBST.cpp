/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorderTraversal(TreeNode* root, vector<int>& inorder){
        if(root == NULL){
            return;
        }

        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }

    TreeNode* inorderToBST(int s, int e, vector<int> v){
        if(s > e) {
            return NULL;
        }

        int mid = (s+e)/2;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = inorderToBST(s, mid-1, v);
        root->right = inorderToBST(mid+1, e, v);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        inorderTraversal(root, inorder);
        int n = inorder.size();
        return inorderToBST(0, n-1, inorder);
    }
};