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

Node *removeHead(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
    return head;
}

Node *removeTail(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}

Node *removeKth(Node *head, int k)
{
    if (head == NULL || k <= 0)
    {
        return head;
    }
    int count = 0;
    Node *kNode = head;
    while (kNode != NULL)
    {
        count++;
        if (count == k)
        {
            break;
        }
        kNode = kNode->next;
    }
    Node *back = kNode->prev;
    Node *front = kNode->next;
    if (back == NULL && front == NULL)
    {
        return NULL;
    }
    else if (back == NULL)
    {
        return removeHead(head);
    }
    else if (front == NULL)
    {
        return removeTail(head);
    }
    back->next = front;
    front->prev = back;
    delete kNode;
    return head;
}

int main()
{
    vector<int> arr = {12, 5, 8, 7};
    Node *head = convertArrToLL(arr);
    head = removeKth(head, 2);
    print(head);
    return 0;
}