#include <iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int>& arr, int n)
{
	// Base case
	if (n <= 1)
		return;

	insertionSort( arr, n-1 );

	int last = arr[n-1];
	int j = n-2;

	while (j >= 0 && arr[j] > last)
	{
		arr[j+1] = arr[j];
		j--;
	}
	arr[j+1] = last;
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

    insertionSort(arr, n);

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }  
	return 0;
}
