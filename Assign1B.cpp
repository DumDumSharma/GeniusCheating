#include <iostream>
#include<queue>
using namespace std;


class node
{
 public:
   int data;
   node* left;
   node* right;

 
 node(int d)
 {
  this->data = d;
  this->left = NULL;
  this->right = NULL;
 }

};
 

node* buildtree(node* root)
{
 int data;
 cout<<"Enter Data : ";
 cin>>data;
 root = new node(data);
  if(data == -1)
  {
   return NULL;
  }
 cout<<"Enter left of "<<data<<" data \n";
 root->left =  buildtree(root->left);
 cout<<"Enter right of "<<data<<" data \n";
 root->right = buildtree(root->right);
 return root;
}

void displayleaf(node *root)
{
 if(root == NULL)
 {
  return;
 }
 if(root->left == NULL && root->right == NULL)
 {
  cout<<root->data<<" ";
 }
 displayleaf(root->left);
 displayleaf(root->right);
}

void display(node *root)
{
 if(root == NULL)
 {
  return;
 }
 display(root->left);
 display(root->right);
 cout<<root->data<<" ";
}

void leveltravel(node* root)
{
  queue<node*> q;
  q.push(root);
  q.push(NULL);
   while(!q.empty())
   {
    node *temp = q.front();
    q.pop();
     if(temp == NULL)
     {
      cout<<"\n";
       if (!q.empty())
       {
        q.push(NULL);
       }
     }
     else
     {
      cout<<temp->data<<" ";
       if(temp->left)
       {
        q.push(temp->left);
       }
       if(temp->right)
       {
        q.push(temp->right);
       }
     }
   }
}

bool search(node* root, int data) 
{
    
  if (root == nullptr) 
  {
      return false;
  }
  if (root->data == data) 
  {
       return true;
  }
  bool foundInLeftSubtree = search(root->left, data);
  if (foundInLeftSubtree) 
  {
      return true;
  }
  bool foundInRightSubtree = search(root->right, data);
  return foundInRightSubtree;
}

node* maxval(node* root) 
{
    while (root->right != NULL) root = root->right;
    return root;
}

node* Deletenode(node* temp, int data) 
{
    if (temp == NULL) 
    {
        return NULL;
    }

    if (temp->data == data) 
    {
        if (temp->left == NULL && temp->right == NULL) 
        {
            delete temp;
            return NULL;
        }
        else if (temp->left == NULL && temp->right != NULL) 
        {
            node* child = temp->right;
            delete temp;
            return child;
        }
        else if (temp->left != NULL && temp->right == NULL) 
        {
            node* child = temp->left;
            delete temp;
            return child;
        }
        else 
        {
            node* child = maxval(temp->left); 
            temp->data = child->data; 
            temp->left = Deletenode(temp->left, child->data);
        }
    }
    else if (data < temp->data) 
    {
        temp->left = Deletenode(temp->left, data);
    }
    else 
    {
        temp->right = Deletenode(temp->right, data);
    }

    return temp;
}

void menu() 
{
 cout << "Menu:\n";
 cout << "1. Insert\n";
 cout << "2. Display \n";
 cout << "3. BFS (Level-order traversal)\n";
 cout <<  "4. Delete Node\n";
 cout << "5. Search data\n";
 cout << "6. Exit\n";
 cout << "Enter your choice: ";
}

int main()
{
 int choice;
 node* root;
   while (true) 
   {
    menu();
     cin >> choice;
      switch (choice) 
      {
        case 1:
           cout<<"Enter Binary Search Tree";
           root = buildtree(root);
           break;
        case 2:
            if (root == NULL) 
            {
              cout << "Tree is empty.\n";
            } 
            else 
            {
              cout << "\n";
              display(root);
              cout << "\n";
            }
            break;
        case 3:
            if (root == NULL) 
            {
              cout << "Tree is empty.\n";
            } else 
            {
              cout << "Level-order Traversal (BFS): \n";
              leveltravel(root);
            }
            break;
        case 4:
            if (root == NULL) 
            {
                cout << "Tree is empty.\n";
            } else 
            {
                int data;
                cout << "Enter the data to delete: ";
                cin >> data;
                root = Deletenode(root, data);
            }
            break;
        case 5:
            if(root == NULL)
            {
             cout << "Tree is empty.\n";
            }
            else 
            {
             int data;
             cout << "Enter value to search: ";
             cin >> data;
              if (search(root, data)) 
              {
                cout << "Value found in the tree!" << endl;
              } else 
              {
                cout << "Value not found in the tree." << endl;
              }
            }

        case 6:
            exit(0);
        default:
            cout << "Invalid choice. Please try again.\n";
      }
   }
 return 0;
}   
