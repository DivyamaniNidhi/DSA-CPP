#include<iostream>
#include<vector>
using namespace std;

int minIndex(vector<int>& arr, int i, int j){
    if(i == j) return i;

    int k = minIndex(arr, i+1, j);
    
    if(arr[i] < arr[k]) return i;
    else return k;
}


void selectionSort(vector<int>& arr, int n, int index = 0){
    
    //base case
    if(index == n) return;

    int mini = minIndex(arr, index, n-1);

    if(mini != index){
        swap(arr[index], arr[mini]);
    }

    selectionSort(arr, n, index+1);
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

    selectionSort(arr, n);  

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }  
}