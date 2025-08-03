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

Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *front;
    while (curr != NULL)
    {
        front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }
    return prev;
}

// Node* add1ToLLusingReverse(Node* head) {
//     head=reverse(head);
//     Node* temp=head;
//     int carry=1;
//     while(temp!=NULL) {
//         temp->data=temp->data+1;
//         if(temp->data<10) {
//             carry=0;
//             break;
//         }
//         else {
//             temp->data=0;
//             carry=1;
//         }
//         temp=temp->next;
//     }
//     head=reverse(head);
//     if(carry==1) {
//         Node* newNode=new Node(1);
//         newNode->next=head;
//         return newNode;
//     }
//     return head;
// }

int helper(Node* temp) {
    if(temp==NULL) {
        return 1;
    }
    int carry=helper(temp->next);
    temp->data=temp->data+carry;
    if(temp->data<10) {
        return 0;
    }
    temp->data=0;
    return 1;
}

Node* add1ToLLUsingRecursion(Node* head) {
    int carry=helper(head);
    if(carry==1) {
        Node* newNode=new Node(1);
        newNode->next=head;
        return newNode;
    }
    return head;
}

int main()
{
    vector<int> arr = {9, 9, 9};
    Node *head = convertArrToLL(arr);
    print(head);
    // head = reverseUsingStack(head);
    head = add1ToLLUsingRecursion(head);
    print(head);
    return 0;
}