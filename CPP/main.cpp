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


bool isSorted(Node * head)
{
    //Your code here
    if(head==NULL)
        return false;

    Node *p=head,*q;

    int i=0,j=0,l=0;

    while(p){
        l++;
        q=p;
        p=p->next;

        if(p->data > q->data){
            i++;
        } else if(p->data > q->data) {
            j++;
        } else {
            i++; j++;
        }
    }

    if(l==(i+1) || l==(j+1))
        return true;
    else
        return false;
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
