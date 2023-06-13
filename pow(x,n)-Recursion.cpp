#include<iostream>
using namespace std;


int power(int x, int n){

    //base case
    if(n == 0){
        return 1;
    }

    if(n == 1){
        return x;
    }

    int ans = power(x, n/2);

    //n is odd
    if(n & 1){
        return x * ans * ans;
    }
    else{ //n is even
        return ans * ans;
    }
}
int main(){

    int x, n;
    cout<<"To find pow(x, n) : ";
    cout<<endl;
    cout<<"Enter the value of x - ";
    cin>>x;
    cout<<"Enter the value of n - ";
    cin>>n;

    int ans = power(x, n);
    cout<<"pow("<<x<<","<<n<<") is - "<<ans; 
    
}

