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
    TreeNode* childToParentMapping(TreeNode* root, int start, map<TreeNode*, TreeNode*>& mp){
        TreeNode* res = NULL;

        queue<TreeNode*> q;
        q.push(root);
        mp[root] = NULL;

        while(!q.empty()){
            TreeNode* frontNode = q.front();
            q.pop();

            if(frontNode->val == start){
                res = frontNode;
            }

            if(frontNode->left != NULL) {
                mp[frontNode->left] = frontNode;
                q.push(frontNode->left);
            }
            if(frontNode->right != NULL) {
                mp[frontNode->right] = frontNode;
                q.push(frontNode->right);
            }
        }

        return res;
    }

    int infectTree(TreeNode* root, map<TreeNode*, TreeNode*>& mp){
        map<TreeNode*, bool> visited;
        queue<TreeNode*> q;

        q.push(root);
        visited[root] = true;

        int ans = 0;
        while(!q.empty()){
            bool flag = 0;

            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* frontNode = q.front();
                q.pop();

                if(frontNode->left != NULL && visited[frontNode->left] == false){
                    flag = true;
                    q.push(frontNode->left);
                    visited[frontNode->left] = true;
                }
                if(frontNode->right != NULL && visited[frontNode->right] == false){
                    flag = true;
                    q.push(frontNode->right);
                    visited[frontNode->right] = true;
                }
                if(mp[frontNode] != NULL && visited[mp[frontNode]] == false){
                    flag = true;
                    q.push(mp[frontNode]);
                    visited[mp[frontNode]] = true;
                }
            }
            if(flag == true){
                ans++;
            }
        }
        return ans;
    }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> nodeToParent; //child -> parent 
        TreeNode* target = childToParentMapping(root, start, nodeToParent);
        int time = infectTree(target, nodeToParent);

        return time;
    }
};