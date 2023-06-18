#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int>& arr, int n){
    
    //base case
    if(n == 0 || n == 1) return;

    for(int i = 0; i < n-1; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }

    bubbleSort(arr, n-1);
}
int main(){
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

    bubbleSort(arr, n);  

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }  
}