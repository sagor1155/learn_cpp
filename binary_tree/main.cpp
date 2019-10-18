#include <iostream>

using namespace std;

struct node
{
    int key;
    struct node *left, *right;
};

struct node* create_node(int key)
{
    struct node* temp_node = (struct node *)malloc(sizeof(struct node));
    temp_node->key = key;
    temp_node->left = temp_node->right = NULL;
    return temp_node;
}

struct node* insert_node(struct node* newnode, int key)
{
    if(newnode==NULL)
        return create_node(key);

    if(key < newnode->key)
        newnode->left = insert_node(newnode->left, key);
    else if(key > newnode->key)
        newnode->right = insert_node(newnode->right, key);

    return newnode;
}

void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        cout << root->key << endl; 
        inorder(root->right); 
    } 
} 

int main()
{
    cout << "Binary Tree Using Linked List \n";
    struct node *root = NULL; 
    root = insert_node(root, 50); 
    insert_node(root, 30); 
    insert_node(root, 20); 
    insert_node(root, 40); 
    insert_node(root, 70); 
    insert_node(root, 60); 
    insert_node(root, 80); 
    inorder(root);
    return 0;
}