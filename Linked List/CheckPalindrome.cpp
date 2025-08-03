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

bool checkUsingStack(Node* head) {
    Node *temp = head;
    stack<int> st;
    while (temp != NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    int num;
    while (temp != NULL)
    {
        num=st.top();
        st.pop();
        if(temp->data!=num) {
            return false;
        }
        temp=temp->next;
    }
    return true;
}



int main()
{
    vector<int> arr = {2, 5, 1, 5, 2};
    Node *head = convertArrToLL(arr);
    print(head);
    cout<<checkUsingStack(head)<<endl;
    return 0;
}