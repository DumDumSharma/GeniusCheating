


#include <iostream>
#include<bits/stdc++.h>
using namespace std ;

class node {
    public:
        int data;
        node* left;
        node* right;

    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root) {

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);    

    if(data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;

}

void inorder(node* root) {
    if(root == NULL) {
        return ;
    }

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);

}

void preorder(node* root) 
{
    if(root == NULL) {
        return ;
    }
    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

void postorder(node* root)
{
    if(root == NULL) {
        return ;
    }
    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";
}

int depth(node* root) {
    if(root == NULL) {
        return 0 ;
    }

    int l =  depth(root->left) ;
    int r = depth(root->right);

    return max(l, r) + 1 ;
}

void displayLeafNode(node* root)
{
    if(root == NULL) {
        return ;
    }

    if (root -> left == NULL && root -> right == NULL) 
    {
        cout << "Leaf node of BT" << root -> data << endl ;
    }
    displayLeafNode(root -> left); 
    displayLeafNode(root -> right);
}

node* copyTree(node* root) {
    if (root == NULL)
        return NULL;

    node* newNode = new node (root->data);
    newNode->left = copyTree(root->left);
    newNode->right = copyTree(root->right);

    return newNode;
}



int main()
{
    /*
    node* root = NULL;
    root = buildTree(root);
    inorder(root);
    cout << endl ;
    cout << "Depth of Binary Tree: " << depth(root) << endl ;
    displayLeafNode(root) ;
    node* newRoot = copyTree(root);
    cout << "Inorder traversal of copied tree: ";
    inorder(newRoot);
    cout << endl;
    cout << "Preorder traversal of copied tree: ";
    preorder(newRoot);
*/
    node* root = NULL;
    node* newRoot = NULL;
    int choice;

    do {
        cout << "Menu:" << endl ;
        cout << "1. Build Tree" << endl ;
        cout << "2. Inorder Traversal" << endl ;
        cout << "3. Preorder Traversal" << endl ;
        cout << "4. Postorder Traversal" << endl ;
        cout << "5. Display Depth of Tree" << endl ;
        cout << "6. Display Leaf Nodes" << endl ;
        cout << "7. Copy Tree" << endl ;
        cout << "8. Inorder Traversal of Copied Tree" << endl ;
        cout << "9. Preorder Traversal of Copied Tree" << endl ;
        cout << "10. Exit" << endl ;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                root = buildTree(root);
                cout << "Tree built successfully.\n";
                break;
            case 2:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;
            case 3:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;
            case 4:
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
                break;
            case 5:
                cout << "Depth of Binary Tree: " << depth(root) << endl;
                break;
            case 6:
                cout << "Leaf Nodes:" << endl ;
                displayLeafNode(root);
                break;
            case 7:
                newRoot = copyTree(root);
                cout << "Tree copied successfully." << endl ;
                break;
            case 8:
                if (newRoot) {
                    cout << "Inorder Traversal of Copied Tree: ";
                    inorder(newRoot);
                    cout << endl;
                } else {
                    cout << "Copied tree does not exist." << endl ;
                }
                break;
            case 9:
                if (newRoot) {
                    cout << "Preorder Traversal of Copied Tree: ";
                    preorder(newRoot);
                    cout << endl;
                } else {
                    cout << "Copied tree does not exist." << endl ;
                }
                break;
            case 10:
                cout << "Exit" << endl ;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl ;
        }
    } while (choice != 10);

    return 0 ;
}
