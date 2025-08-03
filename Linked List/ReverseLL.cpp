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

// Node *reverseUsingStack(Node *head)
// {
//     Node *temp = head;
//     stack<int> st;
//     while (temp != NULL)
//     {
//         st.push(temp->data);
//         temp = temp->next;
//     }
//     temp = head;
//     while (temp != NULL)
//     {
//         temp->data = st.top();
//         st.pop();
//         temp = temp->next;
//     }
//     return head;
// }

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

int main()
{
    vector<int> arr = {2, 5, 1, 7, 9, 6, 8};
    Node *head = convertArrToLL(arr);
    print(head);
    // head = reverseUsingStack(head);
    head = reverse(head);
    print(head);
    return 0;
}