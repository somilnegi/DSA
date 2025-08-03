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

void deleteAllOccurences(Node* head, int key) {
    if(head==nullptr) {
        return;
    }
    Node* curr=head;
    Node* prev=nullptr;
    Node* next;
    while(curr!=nullptr) {
        if(curr->data==key) {
            next=curr->next;
            if(prev==nullptr) {
                next->prev=prev;
            }
            else {
                prev->next=next;
                next->prev=prev;
            }
        }
        prev=curr;
        curr=curr->next;
    }
}

int main()
{
    vector<int> arr = {12, 2, 5, 2, 8, 7, 2, 9};
    Node *head = convertArrToLL(arr);
    print(head);
    deleteAllOccurences(head, 2);
    print(head);
    return 0;
}