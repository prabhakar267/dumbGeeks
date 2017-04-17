#include<bits/stdc++.h>
using namespace std;

struct node{
    int key;
    struct node *left, *right;
};

struct node* insert(struct node* root, int new_key){
    if(root == NULL){
        root = new node;
        root->left = NULL;
        root->right = NULL;
        root->key = new_key;
    } else {
        if(root->key > new_key){
            root->left = insert(root->left, new_key);
        } else {
            root->right = insert(root->right, new_key);
        }
    }
    return root;
}

void print_bst(struct node* root){
    if(root != NULL){
        print_bst(root->left);
        cout<<root->key<<" ";
        print_bst(root->right);
    }
}

struct node *find_next_min_value(struct node *root){
    if(root->left == NULL)
        return root;
    else 
        return find_next_min_value(root->left);
}

struct node *delete_node(struct node *root, int delete_key){
    if(root == NULL){
        return root;
    }

    if(root->key > delete_key){
        root->left = delete_node(root->left, delete_key);
    } else if(root->key < delete_key){
        root->right = delete_node(root->right, delete_key);
    } else {
        if(root->left == NULL){
            struct node *temp = root->right;
            delete root;
            return temp;
        } else if(root->right == NULL){
            struct node *temp = root->left;
            delete root;
            return temp;
        } else {
            struct node *temp = find_next_min_value(root->right);
            root->key = temp->key;
            root->right = delete_node(root->right, temp->key);
        }
    }
    return root;
}

int main(){
    struct node* root;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    root = delete_node(root, 20);
    print_bst(root);
    printf("\n");

    root = delete_node(root, 30);
    print_bst(root);
    printf("\n");

    root = delete_node(root, 50);
    print_bst(root);
    printf("\n");
    return 0;
}
