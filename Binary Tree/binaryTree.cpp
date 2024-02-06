#include<iostream>
#include<queue>

using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* createTree(Node* root){

    int data;
    cout<<"\nEnter data: ";
    cin>>data;

    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"\nEnter data to the left of "<<data;
    root->left = createTree(root->left);

    cout<<"\nEnter data to the right of "<<data;
    root->right = createTree(root->right);

    return root;
}

void inorder(Node *root){
    if(!root)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root){

    if(root == NULL){
        return;
    }

    cout<< root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){

    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<< root->data<<" ";
}


void levelOrderTraversal(Node *root){

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){

        Node *front = q.front();
        q.pop();

        if(front == NULL){
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
        }
        else{
            cout<<front->data<<" ";

            if(front->left)
                q.push(front->left);
            
            if(front->right)
                q.push(front->right);
        }
    }

}

int main(){

    Node *root = NULL;

    root = createTree(root);
    cout<<"Inorder Traversal -> ";
    inorder(root);

    cout<<"Preorder Traveral -> ";
    preorder(root);

    cout<<"Postorder Traveral -> ";
    postorder(root);

    cout<<"Level Order Traversal -> ";
    levelOrderTraversal(root);

    return 0;
}