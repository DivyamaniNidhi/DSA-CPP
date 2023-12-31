/*Given a binary tree with a value associated with each node, we need to choose a subset of 
these nodes such that sum of chosen nodes is maximum under a constraint that no two chosen 
node in subset should be directly connected that is, if we have taken a node in our sum then 
we can’t take its any children or parents in consideration and vice versa.*/

class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    pair<int, int> solve(Node* root){
        //base case
        if(root == NULL){
            pair<int, int> p = {0,0};
            return p;
        }
        
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);
        
        pair<int, int> res;
        
        //max sum including all nodes at current level
        res.first = root->data + left.second + right.second;
        //max sum excluding all nodes at current level
        res.second = max(left.first, left.second) + max(right.first, right.second);
        
        return res;
    }
    int getMaxSum(Node *root) 
    {
        pair<int, int> ans; //exclude node, include node
        ans = solve(root);
        return max(ans.first, ans.second);
    }
};