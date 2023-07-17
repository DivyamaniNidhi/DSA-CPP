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
    void createMapping(vector<int>& inorder, map<int, int>& nodeToIndex, int n){
        for(int i = 0; i < n; i++){
            nodeToIndex[inorder[i]] = i;
        }
    }

    TreeNode* solve(vector<int>& in, vector<int>& post,  int& postIdx, int inStart, int inEnd, int n, map<int, int>&nodeToIndex){
        //base case
        if(postIdx < 0 || inStart > inEnd){
            return NULL;
        }

        int element = post[postIdx--];
        TreeNode* root = new TreeNode(element);
        int pos = nodeToIndex[element];
        
        root->right = solve(in, post, postIdx, pos+1, inEnd, n, nodeToIndex);
        root->left = solve(in, post, postIdx, inStart, pos-1, n, nodeToIndex);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int postIdx = n-1;
        map<int, int> nodeToIndex;
        createMapping(inorder, nodeToIndex, n);
        TreeNode* tree = solve(inorder, postorder, postIdx, 0, n-1, n, nodeToIndex);
        return tree;
    }
};