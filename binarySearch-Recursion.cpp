#include<iostream>
using namespace std;

bool binarySearch(int *arr, int s, int e, int k){

    int mid = s + (e-s)/2;

    //base cases
    //if element not found
    if(s > e) return false;
    //element found
    if(arr[mid] == k) return true;

    if(arr[mid] < k){
        return binarySearch(arr, mid+1, e, k);
    }
    else{
        return binarySearch(arr, s, mid-1, k);
    }
}

int main(){
    int size, key;
    cout<<"Size of array ";
    cin>>size;
    int arr[size];
    cout<<"Enter elements of array in increasing order ";
    for(int i = 0; i < size; i++){
        cin>>arr[i];
    }
    cout<<"Enter the element to find in the array ";
    cin>>key;
    cout<<endl;

    bool ans = binarySearch(arr, 0, size-1, key);

    if(ans){
        cout<<key<<" is present in the array";
    }
    else{
        cout<<key<<" is not present in the array";
    }


}