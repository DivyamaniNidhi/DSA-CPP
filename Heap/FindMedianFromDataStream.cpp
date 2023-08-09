/* 
Sample Input 1:-
3
3
1 2 3 
2
9 9 
1
4 
Sample Output 1:-
1 1 2
9 9 
4 
Explanation For Sample Input 1:-
For test case 1 
After reading first element of stream , Median of [1] is 1 
After reading second element of stream, Median of [1, 2]  = floor((1+2)/2)  = 1
After reading third element of stream, Median of [1,2,3] = 2
So the output will be 1 1 2. */

#include <queue>

int signum(int a, int b) {
    if(a == b) {
        return 0;
    }
    else if(a > b) {
        return 1;
    }
    else {
        return -1;
    }
}

void callMedian(int element, priority_queue<int>& maxi, 
    priority_queue<int, vector<int>, greater<int>>& mini, int& median) {

    switch(signum(maxi.size(), mini.size())) {
        case 0 : 
            if(element > median) {
                mini.push(element);
                median = mini.top();
            }
            else {
                maxi.push(element);
                median = maxi.top();
            }
            break;
        
        case 1 :
            if(element > median) {
                mini.push(element);
                median = (maxi.top() + mini.top()) / 2;
            }
            else {
                mini.push(maxi.top());
                maxi.pop();
                maxi.push(element);
                median = (maxi.top() + mini.top()) / 2;
            }
            break;
        case -1 :
            if(element > median) {
                maxi.push(mini.top());
                mini.pop();
                mini.push(element);
                median = (maxi.top() + mini.top()) / 2;
            }
            else {
                maxi.push(element);
                median = (maxi.top() + mini.top()) / 2;
            }
            break;
    }
}

vector<int> findMedian(vector<int> &arr, int n){
	vector<int> ans;
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    int median = 0;

    for(int i = 0; i < n; i++) {
        callMedian(arr[i], maxheap, minheap, median);
        ans.push_back(median);
    }
    return ans;
}
