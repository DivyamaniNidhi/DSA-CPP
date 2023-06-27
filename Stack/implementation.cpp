#include<iostream>
using namespace std;

class Stack {
    public:
        int* arr;
        int index;
        int size;

    Stack(int size){
        this -> size = size;
        arr = new int[size];
        index = -1;
    }

    void push (int element) {
        if(size - index > 1){
            index++;
            arr[index] = element;
        }
        else{
            cout<<"Stack Overflowed"<<endl;
        }
    }

    void pop (){
        if(index >= 0){
            index--;
        }
        else{
            cout<<"Stack Underflowed"<<endl;
        }
    }

    int top (){
        if(index >= 0){
            return arr[index];
        }
        else{
            cout<<"Stack is Empty ";
            return -1;
        }
    }

    bool empty(){
        if(index < 0){
            return true;
        }
        return false;
    }
};

int main() {

    //create new stack
    Stack st(5);

    st.push(1);
    st.push(2);
    st.push(3);

    cout<<st.top()<<endl; //3

    st.pop();

    cout<<st.top()<<endl; //2

    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7); //Stack Overflowed

    cout<<st.top()<<endl; //6
    
    cout<<st.empty()<<endl; //0 (false)

    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop(); 

    cout<<st.top()<<endl; //Stack is Empty -1

    st.pop(); //Stack underflowed

    cout<<st.empty()<<endl; //1 (true)
}