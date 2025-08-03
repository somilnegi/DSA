#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int d)
    {
        data = d;
        prev = NULL;
        next = NULL;
    }
    Node(int d, Node *p, Node *n)
    {
        data = d;
        prev = p;
        next = n;
    }
};

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *convertArrToLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i], prev, NULL);
        prev->next = newNode;
        prev = newNode;
    }
    return head;
}

// Node* findMiddleNode(Node* head) {
//     int len=0;
//     Node* temp=head;
//     while(temp!=NULL) {
//         len++;
//         temp=temp->next;
//     }
//     int mid=len/2;
//     temp=head;
//     while(mid) {
//         temp=temp->next;
//         mid--;
//     }
//     return temp;
// }

Node* findMiddleNode(Node* head) {
    Node* slow=head;
    Node* fast=head;
    while(fast->next!=NULL && fast!=NULL) {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

int main()
{
    vector<int> arr = {3, 1, 4, 6, 2};
    Node *head = convertArrToLL(arr);
    print(head);
    Node* ans=findMiddleNode(head);
    cout<<ans->data;
    return 0;
}