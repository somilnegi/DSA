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

Node* OddEven(Node* head) {
    Node* resStart=head;
    Node* resEnd=head->next;
    Node* temp=resEnd;
    Node* curr=head->next->next;
    int index=1;
    while(curr!=NULL) {
        if(index%2!=0) {
            resStart->next=curr;
            resStart=resStart->next;
        }
        else {
            resEnd->next=curr;
            resEnd=resEnd->next;
        }
        index++;
        curr=curr->next;
    }
    resStart->next=temp;
    resEnd->next= NULL;
    return head;
}

int main()
{
    vector<int> arr = {12, 5, 8, 7};
    Node *head = convertArrToLL(arr);
    print(head);
    head = OddEven(head);
    print(head);
    return 0;
}