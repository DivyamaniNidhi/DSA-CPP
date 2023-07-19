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

//------------INSERT A NODE IN BST-------------------------------------------------------//
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

//-----------------------LEVEL ORDER TRAVERSL ------------------------------------------------------//

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

///-----------------------------------MINIMUM VALUE IN BST------------------------//////////////
Node* minVal(Node* root) {
    Node* temp = root;

    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

///------------------------------------MAXIMUM VALUE IN BST------------------------//////////////
Node* maxVal(Node* root){
    Node* temp = root;

    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

//----------------DELETE FROM BST------------------------------------------------------//
Node* deleteNode(Node* root, int val){
    //base case
    if(root == NULL){
        return root;
    }
    if(root->data == val){ //delete
        // 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // 1 child
        if(root->left != NULL && root->right == NULL){ // only left child is present
            Node* temp = root->left;
            delete root;
            return temp;
        }
        if(root->left == NULL && root->right != NULL){ // only right child is present
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if(root->left != NULL && root->right != NULL){
            int mini = minVal(root->right) -> data;
            root->data = mini;
            root->right = deleteNode(root->right, mini);
            return root;
        }
    }
    else if(root->data > val){
        root->left = deleteNode(root->left, val);
        return root;
    }
    else{
        root->right = deleteNode(root->right, val);
        return root;
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

    cout<<"Enter data to create BST : "<<endl; //50 20 70 10 30 90 110 -1
    takeInput(root);

    cout<<"Level order traversal of BST :"<<endl;
    levelOrderTraversal(root);

    cout<<endl;
    cout<<"Minimum value is : "<<minVal(root)->data<<endl;
    cout<<"Maximum value is : "<<maxVal(root)->data<<endl;

    //after deleting node with value 30
    root = deleteNode(root, 30);
    cout<<"Level order traversal of BST :"<<endl;
    levelOrderTraversal(root);

    cout<<endl;
    cout<<"Minimum value is : "<<minVal(root)->data<<endl;
    cout<<"Maximum value is : "<<maxVal(root)->data<<endl;
}