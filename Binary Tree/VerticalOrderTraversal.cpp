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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, map<int, vector<int>>> nodes; //map<hd, map<level, listOfNodes>>>
        queue<pair<TreeNode*, pair<int, int>>> q; //q<{node, {hd, level}}>

        if(root == NULL){
            return ans;
        } 

        q.push({root, {0,0}}); //here 0, 0 are horizontal distance and level respectively

        while(!q.empty()){
            pair<TreeNode*, pair<int, int>> temp = q.front();
            q.pop();
            TreeNode* frontNode = temp.first;
            int hd = temp.second.first;
            int level = temp.second.second;

            nodes[hd][level].push_back(frontNode->val);

            if(frontNode->left != NULL){
                q.push(make_pair(frontNode->left, make_pair(hd-1, level+1)));
            }
            if(frontNode->right != NULL){
                q.push(make_pair(frontNode->right, make_pair(hd+1, level+1)));
            }
        }

        for (auto it : nodes){
            vector<int> v;
            for (auto j : it.second){
                sort(j.second.begin(), j.second.end()); // Sort nodes within each level
                v.insert(v.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(v);
        }

        return ans;
    }
};