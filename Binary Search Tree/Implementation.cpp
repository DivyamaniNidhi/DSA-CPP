#include<iostream>
#include<queue>
using namespace std;

class Node {

public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertIntoBST(Node* root, int d){
    //base case
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(d > root->data){
        //insert in right part
        root->right = insertIntoBST(root->right, d);
    }
    else{
        //insert in left part
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}

// LEVEL ORDER TRAVERSL ------------------------------------------------------//

void levelOrderTraversal(Node* root){ //BFS(bredth-first search)
    queue<Node*> q;
    q.push(root);
    q.push(NULL); //seperator

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){ //last level is completed
            cout<<endl;
            if(!q.empty()){
                q.push(NULL); //seperator
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left != NULL){
                q.push(temp->left);
            }

            if(temp->right != NULL){
                q.push(temp->right);
            }
        }   
    }
}


void takeInput(Node* & root){
    int data;
    cin>>data;

    while(data != -1){
        root = insertIntoBST(root, data);
        cin>>data;
    }
}

int main(){

    Node* root = NULL;

    cout<<"Enter data to create BST : "<<endl;
    takeInput(root);
    
    cout<<"Level order traversal of BST :"<<endl;
    levelOrderTraversal(root);
}