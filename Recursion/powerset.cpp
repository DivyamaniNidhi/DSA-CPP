#include<iostream>
#include<vector>
using namespace std;

void findPowerset(vector<int> arr, vector<int> subset, int i, vector<vector<int>>& powerset){

    //base case
    if(i >= arr.size()){
        powerset.push_back(subset);
        return;
    }

    //exclude
    findPowerset(arr, subset, i+1, powerset);

    //include
    int element = arr[i];
    subset.push_back(element);
    findPowerset(arr, subset, i+1, powerset);
}

int main(){
    //input
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
    //---------------------
    vector<int> subset;
    vector<vector<int>> powerset;
    int index = 0;
    findPowerset(arr, subset, index, powerset);

    //print powerset
    cout<<"Powerset for given array is - "<<endl;
    for(int i = 0; i < powerset.size(); i++){
        cout<<"subset - ";
        for(int j = 0; j < powerset[i].size(); j++){
            cout<<powerset[i][j]<<" ";
        }
        cout<<endl;
    }
}