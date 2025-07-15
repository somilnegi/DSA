#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
        int data;
        Node* next;
        Node(int data1, Node* next1) {
            data=data1;
            next=next1;
        }
        Node(int data1) {
            data=data1;
            next=nullptr;
        }
};

Node* convertArrToLL(vector<int> &arr) {
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1; i<arr.size(); i++) {
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

int lengthOfLL(Node *head) {
    int cnt=0;
    Node* temp=head;
    while(temp!=nullptr) {
        cnt++;
        temp=temp->next;
    }
    return cnt;
}

bool checkIfPresent(Node* head, int val) {
    Node* temp=head;
    while(temp!=nullptr) {
        if(temp->data==val) {
            return true;
        }
        temp=temp->next;
    }
    return false;
}

void print(Node* head) {
    while(head!=NULL) {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

Node* removeHead(Node* head) {
    if(head==NULL) {
        return head;
    }
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;
}

Node* removeTail(Node* head) {
    if(head==NULL || head->next==NULL) {
        return head;
    }
    Node* temp=head;
    while(temp->next->next!=NULL) {
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
    return head;
}

Node* removeKth(Node* head, int k) {
    if(head==NULL || k<=0) {
        return head;
    }
    if(k==1) {
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    int count=0;
    Node* temp=head; 
    Node* prev=NULL;
    
    while(temp!=NULL) {
        count++;
        if(count==k) {
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

Node* removeElement(Node* head, int val) {
    if(head==NULL) {
        return head;
    }
    if(head->data==val) {
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    Node* temp=head; 
    Node* prev=NULL;
    while(temp!=NULL) {
        if(temp->data==val) {
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

Node* removeAllOccurences(Node* head, int val) {
    if(head==NULL) {
        return head;
    }      
    Node* curr=head;
    Node* prev=NULL;
    while(curr!=NULL) {
        if(curr->data==val) {
            if(prev==NULL) {
                head=curr->next;
            }
            else {
                prev->next=curr->next;
            }
            curr=curr->next;
        }
        else {
            prev=curr;
            curr=curr->next;
        }
    }
    return head;
}

Node* insertHead(Node* head, int val) {
    Node* newNode=new Node(val, head);
    return newNode;
}
  
Node* insertLast(Node* head, int val) {
    Node* newNode=new Node(val, NULL);
    if(head==NULL) {
        return newNode;
    }
    Node* temp=head;
    while(temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}

Node* insertKth(Node* head, int element, int k) {
    if(head==NULL) {
        if(k==1) {
            return new Node(element);
        }
        else {
            return NULL;
        }
    }
    if(k==1) {
        Node* newNode=new Node(element, head);
        return newNode;
    }
    int count=1;
    Node* temp=head;
    while(temp!=NULL) {
        if(count+1==k){
            Node* newNode=new Node(element);
            newNode->next=temp->next;
            temp->next=newNode;
            break;
        }
        temp=temp->next;
        count++;
    }
    return head;
}

Node* insertBeforeValue(Node* head, int x, int val){
    if(head==NULL){
        return NULL;
    }
    Node* temp=head;
    Node* newNode=new Node(x);
    if(head->data==val) {
        newNode->next=head;
        return newNode;
    }
    while(temp->next!=NULL) {
        if(temp->next->data==val) {
            newNode->next=temp->next;
            temp->next=newNode;
            break;
        }
        temp=temp->next;
    }
    return head;
}

int main() {
    vector<int> arr={12, 5, 8, 7};
    Node* head=convertArrToLL(arr);
    head=insertKth(head, 0, 3);
    print(head);
    return 0;
}