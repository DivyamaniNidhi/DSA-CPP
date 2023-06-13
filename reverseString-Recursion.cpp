#include<iostream>
#include<string>
using namespace std;

void reverseString(int i, int j, string& s){

    //base case
    if(i > j){
        return;
    }

    swap(s[i], s[j]);
    i++;
    j--;
    
    reverseString(i, j, s);
    
}

int main(){
    string s;
    cout<<"Enter the string - ";
    cin>>s;

    reverseString(0, s.length()-1, s);
    cout<<"Reversed string is - "<<s;
}