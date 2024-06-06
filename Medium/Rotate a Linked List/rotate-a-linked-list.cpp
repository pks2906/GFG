//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends

class Solution
{
    public:
    
    Node* rotate(Node* head, int k)
    {
        if (head == NULL || k == 0) return head;

       
        Node* current = head;
        int count = 1;

       
        while (current->next != NULL) {
            current = current->next;
            count++;
        }

        
        if (k == count) return head;

        
        current->next = head;

       
        current = head;
        for (int i = 0; i < k - 1; i++) {
            current = current->next;
        }

        
        Node* new_head = current->next;

        
        current->next = NULL;

        return new_head;
    }
};
    


//{ Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends