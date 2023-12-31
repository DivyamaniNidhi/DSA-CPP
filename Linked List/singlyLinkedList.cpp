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
            this -> next = NULL;
        }
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

//*********************************************   DELETE A NODE  *******************************************//
void deleteNode(int position, Node* &head, Node* &tail){
    //delete first node
    if(position == 1){
        Node* temp = head;
        head = head -> next;
        //free memory
        temp -> next = NULL;
        delete temp;
    }
    else{ //delete any middle or last position 
        Node *curr = head;
        Node *prev = NULL;

        int count = 1;
        while(count < position){
            prev = curr;
            curr = curr -> next;
            count++;
        }
        
        prev -> next = curr -> next;
        if(prev -> next == NULL){
            tail = prev;
        }
        curr -> next = NULL;
        delete curr;
    }
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
    //point tail to last element
    Node* tail = node1;

    print(head); //10

    insertAtHead(head, 12);
    print(head); //12 10

    insertAtHead(head, 15);
    print(head); //15 12 10

    

    insertAtTail(tail, 20);
    print(head); //15 12 10 20

    insertAtPosition(tail, head, 3, 30);
    print(head); //15 12 30 10 20

    deleteNode(2, head, tail);
    print(head); //15 30 10 20

    deleteNode(4, head, tail);
    print(head); //15 30 10


    deleteNode(1, head, tail);
    print(head); //30 10

    cout<<"head : "<<head->data;
    cout<<endl;
    cout<<"tail : "<<tail->data;
}