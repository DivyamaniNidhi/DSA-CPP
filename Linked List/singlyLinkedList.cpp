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
};

//********************************   INSERT AT START OF LINKED LIST    *************************************//
void insertAtHead(Node* &head, int data){
    //create new node
    Node* temp = new Node(data);

    temp -> next = head;
    head = temp;
}


//**********************************   INSERT AT END OF LINKED LIST    *************************************//
void insertAtTail(Node* &tail, int data){
    //create new node
    Node* temp = new Node(data);

    tail -> next = temp;
    tail = temp;
}

//*******************************   INSERT IN MIDDLE AT GIVEN POSITION    ************************************//
void insertAtPosition(Node* &tail, Node* &head, int pos, int data){
    //at start position//
    if(pos == 1){
        insertAtHead(head, data);
        return;
    }
    Node* temp = head;
    int count = 1;

    while(count < pos-1){
        temp = temp -> next;
        count++;
    }
    //at end position//
    if(temp -> next == NULL){
        insertAtTail(tail, data);
    }
    //create a node for data
    Node* NodeToInsert = new Node(data);

    NodeToInsert -> next = temp -> next;
    temp -> next = NodeToInsert;
}

//**************************************   TRAVERSE THE LINKED LIST    *************************************//
void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main(){
    //create a new node
    Node* node1 = new Node(10);

    //point head to new node
    Node* head = node1;
    print(head); //10

    insertAtHead(head, 12);
    print(head); //12 10

    insertAtHead(head, 15);
    print(head); //15 12 10

    //point tail to last element
    Node* tail = head -> next -> next;

    insertAtTail(tail, 20);
    print(head); //15 12 10 20

    insertAtPosition(tail, head, 3, 30);
    print(head); //15 12 30 10 20

}