#include<iostream>
#include<queue>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;
    
    node (int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

// BUILD TREE USING RECURSION ------------------------------------------------------//

node* buildTree (node* root){
    cout<<"Enter the data : ";
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for inserting in left of "<<data<<" : ";
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting in right of "<<data<<" : ";
    root->right = buildTree(root->right);

    return root;
}

// LEVEL ORDER TRAVERSL ------------------------------------------------------//

void levelOrderTraversal(node* root){ //BFS(bredth-first search)
    queue<node*> q;
    q.push(root);
    q.push(NULL); //seperator

    while(!q.empty()){
        node* temp = q.front();
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

// INORDER TRAVERSAL (Left, Node, Right) ------------------------------------------------------//

void inorderTraversal(node* root){
    if(root == NULL){
        return ;
    }

    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

// PREORDER TRAVESRSAL (Node, Left, Right)  ------------------------------------------------------//

void preorderTraversal(node* root){
    if(root == NULL){
        return ;
    }

    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// POSTORDER TRAVERSAL (Left, Right, Node) ------------------------------------------------------//

void postorderTraversal(node* root){
    if(root == NULL){
        return ;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
}

//BUILD TREE USING LEVEL ORDER ------------------------------------------------------//

void buildUsingLevelOrder(node* &root){
    queue<node*> q;
    cout<<"Enter data for root : ";
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"Enter left node for "<<temp->data<<": ";
        int leftData;
        cin>>leftData;

        if(leftData != -1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node for "<<temp->data<<": ";
        int rightData;
        cin>>rightData;

        if(rightData != -1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

int main(){
    node* root = NULL;
    buildUsingLevelOrder(root);
    // root = buildTree(root);
    cout<<"Level Order Traversal :"<<endl;
    levelOrderTraversal(root);
    cout<<"Inorder Traversal : ";
    inorderTraversal(root);
    cout<<endl;
    cout<<"Preorder Traversal : ";
    preorderTraversal(root);
    cout<<endl;
    cout<<"Postorder Traversal : ";
    postorderTraversal(root);
}