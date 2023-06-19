#include<iostream>
using namespace std;

class Node {

    public:
    Node* prev;
    int data;
    Node* next;

    //constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL;
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
void insertAtHead(Node* &head, Node* &tail, int data){
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(data);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
    
}

//**********************************   INSERT AT END OF LINKED LIST    *************************************//
void insertAtTail(Node* &head, Node* &tail, int data){
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(data);
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }

}

//*******************************   INSERT IN MIDDLE AT GIVEN POSITION    ************************************//
void insertAtPosition( Node* &head, Node* &tail, int pos, int data){
    //at start position//
    if(pos == 1){
        insertAtHead(head, tail, data);
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
        insertAtTail(head, tail, data);
        return;
    }
    //create a node for data
    Node* NodeToInsert = new Node(data);

    NodeToInsert -> next = temp -> next;
    temp -> next = NodeToInsert;
    NodeToInsert -> prev = temp;
    temp -> next -> prev = NodeToInsert;
}

//*********************************************   DELETE A NODE  *******************************************//
void deleteNode(int position, Node* &head, Node* &tail){
    //delete first node
    if(position == 1){
        Node* temp = head;
        head = head -> next;
        head -> prev = NULL;
        //free memory
        temp -> next = NULL;
        delete temp;
    }
    else{ //delete any middle or last position 
        Node *curr = head;
        Node *pre = NULL;

        int count = 1;
        while(count < position){
            pre = curr;
            curr = curr -> next;
            count++;
        }
        
        curr -> prev = NULL;
        pre -> next = curr -> next;
        curr -> next = NULL;

        if(pre -> next == NULL){
            tail = pre;
        }

        delete curr;
    }
}

//**************************************   TRAVERSE THE LINKED LIST    *************************************//
void print(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}
//**********************************  GET LENGTH OF THE LINKED LIST    *************************************//
int getLength(Node* head){
    int len = 0;
    Node* temp = head;

    while(temp != NULL){
        len++;
        temp = temp -> next;
    }
    return len;
}

int main(){
    //create a new node
    // Node* node1 = new Node(10);

    //point head to new node
    Node* head = NULL;
    Node* tail = NULL;
    // print(head); //10

    insertAtHead(head, tail, 12);
    print(head); //12

    insertAtHead(head, tail, 15);
    print(head); //15 12

    insertAtTail(head, tail, 20);
    print(head); //15 12 20

    insertAtPosition(head, tail, 3, 30);
    print(head); //15 12 30 20

    insertAtPosition(head, tail, 5, 40);
    print(head); //15 12 30 20 40


    deleteNode(2, head, tail);
    print(head); //15 30 20 40

    deleteNode(1, head, tail);
    print(head); // 30 20 40


    deleteNode(3, head, tail);
    print(head); //30 20
    cout<<"head : "<<head->data;
    cout<<endl;
    cout<<"tail : "<<tail->data;
}