/* Given an integer array nums and an integer k, return the k most frequent elements. You may return the 
answer in any order.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1] */

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int>mp;
        for(auto i : nums){
            mp[i]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(auto i : mp) {
            pq.push({i.second, i.first});
            if(pq.size() > k) {
                pq.pop();
            }
        }

        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};