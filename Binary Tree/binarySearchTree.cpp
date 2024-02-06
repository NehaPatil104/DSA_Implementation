#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
    
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertInBST(Node* &root, int data){
    // base case
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(data > root->data){
        // insert in right subtree
        root->right = insertInBST(root->right, data);
    }
    else{
         // insert in left subtree
        root->left = insertInBST(root->left, data);
    }
    return root;
}

Node* minValue(Node* root){
    if(root == NULL){
        return NULL;
    }

    Node *temp = root;

    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

int maxValue(Node* root){
    if(root == NULL){
        return -1;
    }

    Node *temp = root;

    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp->data;
}

Node* deleteFromBST(Node* root, int val){
    // base case
    if(root == NULL){
        return root;
    }

    if(root->data == val){
        //0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // 1 child

        // left child
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // right child
        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if(root->left != NULL && root->right != NULL){
            int mini = minValue(root->right) -> data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }

    }
    else if(root->data > val){
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else{
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}

void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data != -1){
        insertInBST(root, data);
        cin>>data;
    }
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<< endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
            }
    }
}

int main(){

    Node* root = NULL;

    cout<<"Enter values in Binary Search Tree: "<<endl;
    takeInput(root);

    cout<<"Level Order Traversal: "<<endl;
    levelOrderTraversal(root);

    cout<<"Minimum Value: "<<minValue(root)<<endl;

    cout<<"Maximum Value: "<<maxValue(root)<<endl;

    int x;
    cout<<"Deleting Node: ";
    cin>>x;
    root = deleteFromBST(root, x);
    cout<<"Deleted Node.."<<root->data;

    cout<<"Level Order Traversal: "<<endl;
    levelOrderTraversal(root);

    return 0;
}