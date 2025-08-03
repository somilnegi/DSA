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

// bool detectLoop(Node* head) {
//     map<Node*, int> mp;
//     Node* temp=head;
//     while(temp!=NULL) {
//         if(mp[temp]==1) {
//             return true;
//         } 
//         mp[temp]=1;
//         temp=temp->next;
//     }
//     return false;
// }

bool detecLoop(Node* head) {
    Node* slow=head;
    Node* fast=head;
    while(fast && fast->next!=NULL) {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<int> arr = {3, 1, 4, 6, 2};
    Node *head = convertArrToLL(arr);
    print(head);
    cout<<detectLoop(head);
    return 0;
}