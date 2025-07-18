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

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* segregateOddEven(Node* head) {
    Node* even=nullptr;
    Node* odd=nullptr;
    Node* curr=head;
    Node* temp1;
    Node* temp2;
    while(curr!=NULL) {
        if(curr->data%2==0) {
            if(even==nullptr) {
                even=curr;
                temp1=even;
            }
            else {
                even->next=curr;
                even=even->next;
            } 
        }
        else {
            if(odd==nullptr) {
                odd=curr;
                temp2=odd;
            }
            else {
                odd->next=curr;
                odd=odd->next;
            } 
        }
        curr=curr->next;
    }
    odd->next=nullptr;
    even->next=temp2;
    return temp1;
}

int main()
{
    vector<int> arr = {12, 5, 8, 7, 2, 6, 9, 4};
    Node *head = convertArrToLL(arr);
    print(head);
    head = segregateOddEven(head);
    print(head);
    return 0;
}