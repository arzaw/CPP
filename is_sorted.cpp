//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node (int x)
    {
        data=x;
        next=NULL;
    }
        
};


void displayList(Node *head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}



// } Driver Code Ends

//User function Template for C++

/*
struct Node
{
    int data;
    Node * next;
    Node (int x)
    {
        data=x;
        next=NULL;
    }
        
};
*/

bool isSorted(Node * head)
{
    //Your code here
    if(head==NULL)
        return false;
    
    Node *p=head,*q;
    
    bool x=true,y=true;
    
    while(p){
        if(p->next != NULL){
           if(p->data > p->next->data){
                x=false;
            } 
            if(p->data < p->next->data){
                y=false;
            } 
        }
        p = p->next;
    }
    
    return x || y;
}
    


//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < n-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        cout<<isSorted(head) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends