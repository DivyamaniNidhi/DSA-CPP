#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    // Destructor
    ~Node() {
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
    }
};

void push(Node* &head, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

//-----------------------------------------------------------------------//
void reverseRecursion(Node* &head, Node* curr, Node* prev) {
    if (curr == NULL) {
        head = prev;
        return;
    }

    Node* nextNode = curr->next;
    curr->next = prev;
    reverseRecursion(head, nextNode, curr);
}

void reverse(Node* &head) {
    if (head == NULL || head->next == NULL) {
        return;
    }
    reverseRecursion(head, head, NULL);
}


int main() {
    Node* head = NULL;
    push(head, 10);
    push(head, 20);
    push(head, 30);
    push(head, 40);
    push(head, 50);
    cout << "Given Linked List: ";
    print(head);

    reverse(head);
    cout << "Reversed Linked List: ";
    print(head);

    return 0;
}
