
#include <iostream>
#include<bits/stdc++.h>
using namespace std ;

class node
{
    public :
        int data ;
        node* left ;
        node* right ;

        node(int data)
        {
            this -> data = data ;
            this -> left = NULL ;
            this -> right = NULL ;
        }
} ;

node* buildTree(node* root)
{
    cout << "Enter the Data : " << endl ;
    int data;
    cin >> data ;
    root = new node(data) ;

    if (data == -1)
    {
        return NULL ;
    }
    
    cout << "Enter the data for left child : " << data << endl ;
    root -> left = buildTree(root -> left) ;

    cout << "Enter the data for right child : " << data << endl ;
    root -> right = buildTree(root -> right) ;

    return root ;
}

void inorder(node* root)
{
    if (root == NULL)
    {
        return ;
    }
    inorder(root -> left) ;
    cout << root -> data << " " ;
    inorder(root -> right) ;
    
}

void preorder(node* root)
{
    if (root == NULL)
    {
        return ;
    }
    cout << root -> data << " " ;
    preorder(root -> left) ;
    preorder(root -> right) ;
}

void postorder(node* root)
{
    if (root == NULL)
    {
        return ;
    }
    postorder(root -> left) ;
    postorder(root -> right) ;
    cout << root -> data << " " ;
}

int main()
{
     

    return 0 ;
}