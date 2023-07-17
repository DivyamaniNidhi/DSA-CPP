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
    int findPosition(vector<int>& in, int element, int n){
        for(int i = 0; i < n; i++){
            if(element == in[i]){
                return i;
            }
        }
        return -1;
    }
    TreeNode* solve(vector<int>& pre, vector<int>& in,  int& preIdx, int inStart, int inEnd, int n){
        //base case
        if(preIdx >= n || inStart > inEnd){
            return NULL;
        }

        int element = pre[preIdx++];
        TreeNode* root = new TreeNode(element);
        int pos = findPosition(in, element, n);

        root->left = solve(pre, in, preIdx, inStart, pos-1, n);
        root->right = solve(pre, in, preIdx, pos+1, inEnd, n);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderIndex = 0;
        int n = inorder.size();
        int inorderEnd = n-1;
        int inorderStart = 0;
        TreeNode* tree = solve(preorder, inorder, preorderIndex, inorderStart, inorderEnd, n);
        return tree;
    }
};


///////////////-------------------USING MAP------------------------///////////////////
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
    void createMapping(vector<int>& in, map<int, int>& nodeToIndex, int n){
        for(int i = 0; i < n; i++){
            nodeToIndex[in[i]] = i;
        }
    }
    TreeNode* solve(vector<int>& pre, vector<int>& in,  int& preIdx, int inStart, int inEnd, int n, map<int, int>&nodeToIndex){
        //base case
        if(preIdx >= n || inStart > inEnd){
            return NULL;
        }

        int element = pre[preIdx++];
        TreeNode* root = new TreeNode(element);
        int pos = nodeToIndex[element];

        root->left = solve(pre, in, preIdx, inStart, pos-1, n, nodeToIndex);
        root->right = solve(pre, in, preIdx, pos+1, inEnd, n, nodeToIndex);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderIndex = 0;
        int n = inorder.size();
        int inorderEnd = n-1;
        int inorderStart = 0;
        map<int, int> nodeToIndex;
        createMapping(inorder, nodeToIndex, n);
        TreeNode* tree = solve(preorder, inorder, preorderIndex, inorderStart, inorderEnd, n, nodeToIndex);
        return tree;
    }
};