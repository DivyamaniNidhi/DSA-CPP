/*Given an array of integers. Write a program to find the K-th largest sum of contiguous subarray within the 
array of numbers that has both negative and positive numbers.

Examples: 

Input: arr[] = {20, -5, -1}, K = 3
Output: 14
Explanation: All sum of contiguous subarrays are (20, 15, 14, -5, -6, -1) 
so the 3rd largest sum is 14.

Input: arr[] = {10, -10, 20, -40}, k = 6
Output: -10
Explanation: The 6th largest sum among sum of all contiguous subarrays is -10. */

#include <queue>
int getKthLargest(vector<int> &arr, int k)
{
	priority_queue<int, vector<int>, greater<int>> pq;
	int n = arr.size();
	for(int i = 0; i < n; i++) {
		int sum = 0;
		for(int j = i; j < n; j++) {
			sum += arr[j];
			if(pq.size() < k) {
				pq.push(sum);
			}
			else {
				if(pq.top() < sum) {
					pq.pop();
					pq.push(sum);
				}
			}
		}
	}
	return pq.top();
}