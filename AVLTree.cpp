#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e7+10;

class TreeNode{
public:
    int value;
    TreeNode* left;
    TreeNode* right;
    int height;

    TreeNode(int value){
        this->value = value;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

class AVL{
private:
    TreeNode* root;

    int getHeight(TreeNode* node){
        if(node==NULL) return 0;
        return node->height;
    }

    int getBalance(TreeNode* node){
        return getHeight(node->left)-getHeight(node->right);
    }

    TreeNode* rightRotate(TreeNode* root){
        TreeNode* x = root->left;
        TreeNode* temp = x->right;
        x->right = root;
        root->left = temp;

        root->height= max(getHeight(root->left),getHeight(root->right))+1;
        x->height = max(getHeight(x->left),getHeight(x->right))+1;

        return x;
    }

    TreeNode* leftRotate(TreeNode* root){
        TreeNode* x = root->right;
        TreeNode* temp = x->left;
        x->left = root;
        root->right = temp;

        root->height= max(getHeight(root->left),getHeight(root->right))+1;
        x->height = max(getHeight(x->left),getHeight(x->right))+1;

        return x;
    }
    TreeNode* findMin(TreeNode* node){
        while(node->left!=nullptr){
            node = node->left;
        }
        return node;
    }

    TreeNode* insert(TreeNode* root, int value){
        if(root==NULL) return new TreeNode(value);

        if(value<root->value) root->left = insert(root->left,value);
        else if(value>root->value) root->right = insert(root->right,value);
        else return root;

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));
        int balance = getBalance(root);

        if(balance>1){ //left height bigger
            if( value< root->left->value){
                return rightRotate(root);
            }
            else if(value> root->left->value){
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        }
        else if(balance<-1){ //right height bigger
            if( value > root->left->value){
                return leftRotate(root);
            }
            else if(value> root->left->value){
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
        }
        return root;
    }

    TreeNode* remove(TreeNode* root, int value){
        if(root==NULL) return NULL;
        if(value<root->value) root->left = remove(root->left,value);
        else if(value>root->value) root->right = remove(root->right, value);
        else{
            TreeNode* temp;
            if(!root->left){
                temp = root->right;
                delete root;
                return temp;
            }
            else if(!root->right){
                temp = root->left;
                delete root;
                return temp;
            }
            else{
                temp = findMin(root->right);
                root->value = temp->value;
                root->right = remove(root->right,temp->value);
            }
        }
        if(root==NULL) return root;

        root->height = getHeight(root);
        int balance = getBalance(root);

        if(balance>1){ //left height bigger
            if( value< root->left->value){
                return rightRotate(root);
            }
            else if(value> root->left->value){
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        }
        else if(balance<-1){ //right height bigger
            if( value > root->left->value){
                return leftRotate(root);
            }
            else if(value> root->left->value){
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
        }
        return root;
        
    }
    void printPreOrder(TreeNode* root){
        if(root == nullptr) return;

        cout<<root->value<<"->";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
    void printInOrder(TreeNode* root){
        if(root == nullptr) return;

        printInOrder(root->left);
        cout<<root->value<<"->";
        printInOrder(root->right);
    }
    void printPostOrder(TreeNode* root){
        if(root == nullptr) return;

        printPostOrder(root->left);
        printPostOrder(root->right);
        cout<<root->value<<"->";
    }

public:
    void insert(int value){
        root = insert(root,value);
    }

    void remove(int value){
        root = remove(root,value);
    }
    void printPreOrder(){
        printPreOrder(root);
    }
    void printInOrder(){
        printInOrder(root);
    }
    void printPostOrder(){
        printPostOrder(root);
    }
    

};

int main(){

    AVL* tree = new AVL();
    tree->insert(5);
    tree->insert(2);
    tree->insert(1);
    tree->insert(10);
   // tree->remove(2);
    tree->printInOrder();
    

    return 0;
}
