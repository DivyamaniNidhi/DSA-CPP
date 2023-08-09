/* You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at 
least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

Example 1:

Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].

Example 2:

Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1] */

class Solution {
public:
    class node {
        public:
        int data;
        int row; 
        int col;

        node (int data, int row, int col) {
            this->data = data;
            this->row = row;
            this->col = col;
        }
    };

    class compare {
        public:
        bool operator()(node* a, node* b) {
            return a->data > b->data;
        }
    };

    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini = INT_MAX, maxi = INT_MIN;
        int k = nums.size();

        priority_queue<node*, vector<node*>, compare> minHeap;

        // push 1st element of each row in minHeap and find min and max
        for(int i = 0; i < k; i++) {
            int ele = nums[i][0];
            maxi = max(maxi, ele);
            mini = min(mini, ele);
            minHeap.push(new node(ele, i, 0));
        }

        //initial range
        int start = mini, end = maxi;

        //process ranges
        while(!minHeap.empty()) {
            node* temp = minHeap.top();
            minHeap.pop();

            //next col exists
            if(temp->col + 1 < nums[temp->row].size()) {
                minHeap.push(new node(nums[temp->row][temp->col + 1], temp->row, temp->col + 1));

                mini = minHeap.top() -> data;
                maxi = max(maxi, nums[temp->row][temp->col+1]);

                //update range
                if(maxi - mini < end - start) {
                    start = mini;
                    end = maxi;
                }
            }
            else{ //next col does not exist
                break;
            }
        }
        return {start, end};
    }
};