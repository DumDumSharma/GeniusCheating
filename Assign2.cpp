#include<bits/stdc++.h>
using namespace std ;

class Node
{
    public :
        char data ;
        Node* left ;
        Node* right ;
    
    Node(char data)
    {
        this -> data = data ;
        this -> left = NULL ;
        this -> right = NULL ;
    }
} ;

class ETree
{
    Node* root ;
    public :
        Node* constructTree(string postfix)
        {
            stack<Node*> st ;
            for(char ch : postfix)
            {
                if(isalnum(ch))
                {
                    st.push(new Node(ch));
                }
                else
                {
                    Node* rightNode = st.top() ;
                    st.pop() ;

                    Node* leftNode = st.top() ;
                    st.pop() ;

                    Node* newNode = new Node(ch) ;
                    newNode -> left = leftNode ;
                    newNode -> right = rightNode ;

                    st.push(newNode) ;

                }
                
            }
            cout << "Expression tree constructed successfully" <<endl ;
            return st.top() ;
        }
} ;

/*
void inorder(Node* root)
{
    if (!root)
    {
        
        cout << "Expression tree is empty" << endl ;
        return ;
    }

    stack<Node*> st ;
    Node* curr = root ;

    cout << "Non-Recursive Inorder Traversal: " ;
    while (curr != NULL || st.empty())
    {
        while(curr != NULL)
        {
            st.push(curr) ;
            curr = curr -> left ;
        }

        curr = st.top();
        st.pop() ;
        cout << curr -> data << " ";

        curr = curr -> right ;
    }
    
    cout << endl ;
}
*/

void postorder(Node* root)
{
    if(!root)
    {
        cout << "Expresion tree is empty" << endl ;
        return ;
    }

    stack<Node*> st1, st2 ;
    st1.push(root) ;
    while (!st1.empty())
    {
        Node* curr = st1.top();
        st1.pop() ;
        st2.push(curr) ;

        if(curr -> left) st1.push(curr -> left) ;
        if(curr -> right) st1.push(curr -> right) ;
    }

    cout << "Non-Recursive postorder" << endl ;
    while (!st2.empty()) 
    {
        Node* curr = st2.top() ;
        st2.pop() ;

        cout << curr -> data << " " ;
    }
    
}

void preorder(Node* root)
{
    if (!root) 
    {
        cout << "Expression tree is empty" << endl ;
        return ;
    }

    stack<Node*> st ;
    st.push(root) ;
    
    cout << "Non-Recursive preorder : " << endl ; 
    while (!st.empty())
    {
        Node* curr = st.top() ;
        st.pop() ;
        
        cout << curr -> data << " " ;
        if (curr -> left)
        {
            st.push(curr -> left) ;
        }

        if (curr -> right)
        {
            st.push(curr -> right) ;
        }
    }
}

void inorder(Node* root)
{
    if(!root)
    {
        cout << "Expression tree is empty" << endl ;
        return ;
    }
    
    stack<Node*> st ;
    Node* curr = root ;
    
    cout << "Non-Recursive Travesal : " << endl ;
    while(curr != NULL || !st.empty())
    {
        while(curr != NULL)
        {
            st.push(curr) ;
            curr = curr -> left ;
        }
        
        curr = st.top() ;
        st.pop() ;
        
        cout << curr -> data << " " ;
        curr = curr -> right ;
    }
    
}


int main()
{
    string postfix = "ab+cde+**" ;

    ETree tree ;
    Node* root = tree.constructTree(postfix) ;
    // inorder(root) ;
    postorder(root) ;
    preorder(root) ;
    return 0;
}
