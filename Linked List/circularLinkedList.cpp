#include<iostream>
using namespace std;

class Node {

    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    //destructor
    ~Node(){
        if(this -> next != NULL){
            delete next;
            next = NULL;
        }
    }
};

//******************************************  INSERT A NODE   *********************************************//
void insertNode(Node* &tail, int element, int data){
    if(tail == NULL){
        Node* temp = new Node(data);
        tail = temp;
        temp -> next = temp;
    }
    else{ //assume that element is present
        Node* curr = tail;
        while(curr -> data != element){
            curr = curr -> next;
        }

        //element and curr is at element
        Node* temp = new Node(data);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
}

//******************************************  DELETE A NODE   *********************************************//
void deleteNode(Node* &tail, int value){
    if(tail == NULL){
        cout<<"linked list is empty"<<endl;
        return;
    }
    else{
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != value){
            prev = curr;
            curr = curr -> next;
        }
        prev -> next = curr -> next;

        if(curr == prev){
            tail = NULL;
        }

        else if(curr == tail){
            tail = prev;
        }
        curr -> next = NULL;
        delete curr;
    }   
}

//**************************************   TRAVERSE THE LINKED LIST    *************************************//
void print(Node* tail){
    Node* temp = tail;
    if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }
    
    do{
        cout<< tail -> data<< " ";
        tail = tail -> next;
    } while(tail != temp);
    cout<<endl;
}

int main(){
    Node* tail = NULL;
    insertNode(tail, 5, 10);
    print(tail); //10

    insertNode(tail, 10, 20);
    print(tail); //10 20

    insertNode(tail, 20, 30);
    print(tail); //10 20 30

    insertNode(tail, 20, 40);
    print(tail); //10 20 40 30

    insertNode(tail, 30, 50);
    print(tail); //10 20 40 30 50

    deleteNode(tail, 20);
    print(tail); //10 40 30 50

    deleteNode(tail, 50);
    print(tail); //10 40 30

    deleteNode(tail, 10);
    print(tail); //30 40    

}