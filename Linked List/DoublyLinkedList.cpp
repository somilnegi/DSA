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

void removeNode(Node *temp)
{
    Node *back = temp->prev;
    Node *front = temp->next;
    if (front == NULL)
    {
        back->next = NULL;
        delete temp;
        return;
    }
    back->next = front;
    front->prev = back;
    delete temp;
    return;
}

Node *insertBeforeHead(Node *head, int val)
{
    Node *newNode = new Node(val, NULL, head);
    head->prev = newNode;
    return newNode;
}
Node *insertAfterHead(Node *head, int val)
{
    Node *newNode = new Node(val, head, head->next);
    head->next->prev = newNode;
    head->next = newNode;
    return head;
}

Node *insertBeforeTail(Node *head, int val)
{
    Node *newNode = new Node(val);
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    return head;
}

Node *insertAfterTail(Node *head, int val)
{
    Node *newNode = new Node(val);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

Node *insertKth(Node *head, int k, int val)
{
    Node *newNode = new Node(val);
    if (k == 1)
    {
        newNode->next = head;
        if (head != NULL)
        {
            head->prev = newNode;
        }
        return newNode;
    }
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        if (count == k)
        {
            break;
        }
        temp = temp->next;
    }
    newNode->prev = temp->prev;
    newNode->next = temp;
    temp->prev->next = newNode;
    temp->prev = newNode;
    return head;
}

int main()
{
    vector<int> arr = {12, 5, 8, 7};
    Node *head = convertArrToLL(arr);
    // head = removeKth(head, 2);
    // removeNode(head->next);
    head = insertKth(head, 3, 10);
    print(head);
    return 0;
}