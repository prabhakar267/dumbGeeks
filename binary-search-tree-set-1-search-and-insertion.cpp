#include<bits/stdc++.h>
using namespace std;

struct node{
    struct node *right, *left;
    int data;
};

struct node* insert_binary_tree(struct node* root, int new_key){
    if(root == NULL){
        root = new node;
        root->left = NULL;
        root->right = NULL;
        root->data = new_key;
    } else {
        if(new_key < root->data)
            root->left = insert_binary_tree(root->left, new_key);
        else
            root->right = insert_binary_tree(root->right, new_key);
    }
    return root;
}

void print_binary_tree(struct node *root){
    if(root != NULL){
        print_binary_tree(root->left);
        cout<<root->data<<" ";
        print_binary_tree(root->right);
    }
}



int main(){
    struct node *root = NULL;
    root = insert_binary_tree(root, 50);
    insert_binary_tree(root, 30);
    insert_binary_tree(root, 20);
    insert_binary_tree(root, 40);
    insert_binary_tree(root, 70);
    insert_binary_tree(root, 60);
    insert_binary_tree(root, 10);
    insert_binary_tree(root, 80);
    insert_binary_tree(root, 45);

    print_binary_tree(root);
    cout<<"\n";
    return 0;
}
