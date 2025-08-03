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

// Node* findIntersection(Node* head1, Node* head2) {
//     map<Node*, int> mp;
//     Node* temp=head1;
//     while(temp!=NULL) {
//         mp[temp]=1;
//         temp=temp->next;
//     }
//     temp=head2;
//     while(temp!=NULL) {
//         if(mp.find(temp)!=mp.end()) {
//             return temp;
//         }
//         temp=temp->next;
//     }
//     return NULL;
// }

// Node* findIntersection(Node* head1, Node* head2) {
//     Node* t1=head1;
//     int n1=0;
//     while(t1!=NULL) {
//         n1++;
//         t1=t1->next;
//     }
//     Node* t2=head2;
//     int n2=0;
//     while(t2!=NULL) {
//         n2++;
//         t2=t2->next;
//     }
//     if(n1<n2) {
//         return collisionPoint(head1, head2, n2-n1);
//     }
//     else {
//         return collisionPoint(head2, head1, n1-n2);
//     }
// }

// Node* collisionPoint(Node* smallerLL, Node* largerLL, int n) {
//     Node* large=largerLL;
//     for(int i=0; i<n; i++) {
//         large=large->next;
//     }
//     Node* small=smallerLL;
//     while(large!=small) {
//         large=large->next;
//         small=small->next;
//     }
//     return large;
// }

Node* findIntersection(Node* head1, Node* head2) {
    Node* temp1=head1;
    Node* temp2=head2;
    while(temp1!=temp2) {
        temp1=temp1? temp1->next: head2;
        temp2=temp2? temp2->next: head1;
    }
    return temp1;
}

int main()
{
    vector<int> arr1 = {3, 1, 4, 6, 2};
    vector<int> arr2 = {1, 2, 4, 5, 4, 6, 2};
    Node *head1 = convertArrToLL(arr1);
    Node *head2 = convertArrToLL(arr2);
    print(head1);
    print(head2);

    return 0;
}