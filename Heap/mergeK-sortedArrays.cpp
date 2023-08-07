#include <bits/stdc++.h> 
class node {
    public:
        int data;
        int i; 
        int j;
    
    node(int data, int row, int col) {
        this->data = data;
        i = row;
        j = col;
    }
};

class compare {
    public:
        bool operator()(node* a, node* b) {
            return a->data > b->data;
        }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<node*, vector<node*>, compare> pq; 

    //step 1 - put first element of each array in min heap
    for(int i = 0; i < k; i++) {
        node* temp = new node(kArrays[i][0], i, 0);
        pq.push(temp);
    }

    vector<int> ans;

    //step 2 - put top element of min heap in ans array
    while(pq.size() > 0) {
        node* topNode = pq.top();
        ans.push_back(topNode->data);
        pq.pop();

        int i = topNode->i;
        int j = topNode->j;

        if(j+1 < kArrays[i].size()) {
            node* next = new node(kArrays[i][j+1], i, j+1);
            pq.push(next);
        }
    }
    return ans;
}
