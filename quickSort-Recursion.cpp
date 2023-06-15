#include <iostream>
#include<vector>
using namespace std;

int partition(vector<int>& arr, int s, int e){

    int pivot = arr[s];
    int countSmaller = 0;

    for(int i = s+1; i <= e; i++){
        if(arr[i] <= pivot){
            countSmaller++;
        }
    }

    //place pivot at right place
    int pivotIndex = s+countSmaller;
    swap(arr[s], arr[pivotIndex]);

    //put all smaller in left and bigger in right
    int i = s, j = e;
    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] <= pivot) {
            i++;
        }
        while(arr[j] > pivot) {
            j--;
        }
        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(vector<int>& arr, int s, int e)
{
	// Base case
    if(s >= e){
        return;
    }


    int p = partition(arr, s, e);

    //sort left part
    quickSort(arr, s, p-1);

    //sort right part
    quickSort(arr, p+1, e);
	
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

    quickSort(arr, 0, n-1);

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }  
	return 0;
}
