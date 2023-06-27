#include<iostream>
#include<stack>
using namespace std;

string reverseString(string s){
    stack<char> st;

    for(int i = 0; i < s.length(); i++){
        st.push(s[i]);
    }

    string ans = "";
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main(){
    string s;
    cout<<"Enter the string - ";
    cin>>s;
    cout<<"Reversed String is - "<<reverseString(s)<<endl;
}