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

// Reverse every group 

Node* reverseKGroups(Node* head, int k) {
    if(head==nullptr) {
        return head;
    }
    Node* curr=head;
    Node* newHead=nullptr;
    Node* tail=nullptr;
    while(curr!=nullptr) {
        Node* groupHead=curr;
        Node* prev=nullptr;
        Node* nextNode=nullptr;
        int count=0;
        while(curr!=nullptr && count<k) {
            nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
            count++;
        }
        if(newHead==nullptr) {
            newHead=prev;
        }
        if(tail!=nullptr) {
            tail->next=prev;
        }
        tail=groupHead;
    }
    return newHead;
}

// Leave the non-multiple node as it is

// Node* reverseKGroups(Node* head, int k) {
//     if(head==nullptr) {
//        return head;
//    }
//    Node* curr=head;
//    int size=0;
//    while(curr!=nullptr) {
//        size++;
//        curr=curr->next;
//    }
//    size-=size%k;
//    int limit=0;
//    curr=head;
//    Node* newHead=nullptr;
//    Node* tail=nullptr;
//    while(curr!=nullptr) {
//        Node* groupHead=curr;
//        Node* nextNode=nullptr;
//        Node* prev=nullptr;
//        int count=0;
//        while(curr!=nullptr && count<k) {
//            nextNode=curr->next;
//            curr->next=prev;
//            prev=curr;
//            curr=nextNode;
//            count++;
//            limit++;
//        }
//        if(newHead==nullptr) {
//            newHead=prev;
//        }
//        if(tail!=nullptr) {
//            tail->next=prev;
//        }
//        tail=groupHead;
//        if(limit==size) {
//            tail->next=curr;
//            break;
//        }
//    }
//    return newHead;
// }



int main()
{
    vector<int> arr = {100, 102, 99, 98, 10, 232, 12, 45, 123, 43};
    Node *head = convertArrToLL(arr);
    print(head);
    head = reverseKGroups(head, 2);
    print(head);
    return 0;
}