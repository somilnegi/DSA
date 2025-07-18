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

Node *removeNthFromEnd(Node *head, int k)
{
    Node *fast = head, *slow = head;
    for (int i = 0; i < k; i++)
    {
        fast = fast->next;
    }
    if (fast == nullptr)
    {
        return head->next;
    }
    while (fast->next != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }
    Node *delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;
    return head;
}

int main()
{
    vector<int> arr = {9, 9, 7, 3, 1, 9, 9};
    Node *head = convertArrToLL(arr);
    print(head);
    head = removeNthFromEnd(head, 7);
    print(head);
    return 0;
}