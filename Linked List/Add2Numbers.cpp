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

Node *add(Node *head1, Node *head2)
{
    Node *temp1 = head1;
    Node *temp2 = head2;
    Node *dummyNode = new Node(-1);
    Node *curr = dummyNode;
    Node *newNode = NULL;
    int carry = 0;
    while (temp1 != NULL || temp2 != NULL)
    {
        int sum = carry;
        if (temp1)
        {
            sum += temp1->data;
        }
        if (temp2)
        {
            sum += temp2->data;
        }
        newNode = new Node(sum % 10);
        carry = sum / 10;
        curr->next = newNode;
        curr = curr->next;
        if (temp1)
        {
            temp1 = temp1->next;
        }
        if (temp2)
        {
            temp2 = temp2->next;
        }
    }
    if (carry)
    {
        newNode = new Node(carry);
        curr->next = newNode;
    }
    return dummyNode->next;
}

int main()
{
    vector<int> arr1 = {9, 9, 9, 9, 9, 9, 9};
    vector<int> arr2 = {9, 9, 9, 9};
    Node *head1 = convertArrToLL(arr1);
    Node *head2 = convertArrToLL(arr2);
    print(head1);
    print(head2);
    Node *head = add(head1, head2);
    print(head);
    return 0;
}