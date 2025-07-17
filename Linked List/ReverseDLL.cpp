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

Node* reverse(Node* head) {
    if(head==NULL || head->next==NULL) {
        return head;
    }
    Node* back=NULL;
    Node* curr=head;
    while(curr!=NULL) {
        back=curr->prev;
        curr->prev=curr->next;
        curr->next=back;
        curr=curr->prev;
    }
    return back->prev;
}

int main()
{
    vector<int> arr = {12, 5, 8, 7};
    Node *head = convertArrToLL(arr);
    print(head);
    head = reverse(head);
    print(head);
    return 0;
}