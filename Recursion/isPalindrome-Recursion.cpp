#include<iostream>
#include<string>
using namespace std;

bool checkPalindrome(int i, int j, string str){

    //base case
    if(i > j){
        return true;
    }

    if(str[i] != str[j]){
        return false;
    }
    else{
        return checkPalindrome(i+1, j-1, str);
    } 
}

int main(){
    string s;
    cout<<"Enter the string - ";
    cin>>s;

    bool ans = checkPalindrome(0, s.length()-1, s);
    
    if(ans){
        cout<<"Its a Palindrome";
    }
    else{
        cout<<"Its not a Palindrome";
    }
}