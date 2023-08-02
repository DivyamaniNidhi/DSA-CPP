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
    class info {
        public:
            int maxi;
            int mini;
            bool isBST;
            int maxSum;
    };  
public:
    info solve(TreeNode* root, int &ans) {
        if(root == NULL){
            return {INT_MIN, INT_MAX, true, 0};
        }

        info left = solve(root->left, ans);
        info right = solve(root->right, ans);
        info curr;

        if(left.isBST && right.isBST && (root->val > left.maxi && root->val < right.mini)) {
            curr.isBST = true;
            curr.maxSum = left.maxSum + right.maxSum + root->val;
            curr.mini = min(root->val, left.mini);
            curr.maxi = max(root->val, right.maxi);
        }
        else{
            curr.isBST = false;
            curr.maxSum = max(left.maxSum, right.maxSum);
        }

        ans = max(ans, curr.maxSum);
        return curr;
    }
    int maxSumBST(TreeNode* root) {
        int sum = 0;
        solve(root, sum);
        return sum;
    }
};