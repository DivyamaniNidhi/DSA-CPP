#include <iostream>
#include<vector>
using namespace std;

void merge(vector<int>& arr, int s, int e){

    int mid = s + (e-s)/2;

    int len_left = mid-s+1;
    int len_right = e-mid;

    vector<int> left(len_left);
    vector<int> right(len_right);

    //copy values in new arrays
    int mainArrayIndex = s;
    for(int i = 0; i < len_left; i++){
        left[i] = arr[mainArrayIndex++];
    } 

    mainArrayIndex = mid + 1;
    for(int i = 0; i < len_right; i++){
        right[i] = arr[mainArrayIndex++];
    }

    //merge the sorted arrays
    int index_left = 0;
    int index_right = 0;
    mainArrayIndex = s;

    while(index_left < len_left && index_right < len_right){
        if(left[index_left] < right[index_right]){
            arr[mainArrayIndex++] = left[index_left++];
        }
        else{
            arr[mainArrayIndex++] = right[index_right++];
        }
    }

    //copy remaining elements of left
    while(index_left < len_left){
        arr[mainArrayIndex++] = left[index_left++];
    }
    //copy remaining elements of right
    while(index_right < len_right){
        arr[mainArrayIndex++] = right[index_right++];
    }

    left.clear();
    right.clear();
}

void mergeSort(vector<int>& arr, int s, int e)
{
	// Base case
    if(s >= e){
        return;
    }

    int mid = s + (e-s)/2;

    //sort left part 
    mergeSort(arr, s, mid);

    //sort right part
    mergeSort(arr, mid+1, e);

    //merge both parts
    merge(arr, s, e);
	
}

int main()
{
	int n;
    cout<<"Enter size of array - ";
    cin>>n;
    int a;
    vector<int> arr;
    cout<<"Enter array - ";
    for(int i = 0; i < n; i++){
        cin>>a;
        arr.push_back(a);
    }

    mergeSort(arr, 0, n-1);

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }  
	return 0;
}
