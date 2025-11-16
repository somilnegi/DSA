#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node(int x) {
            data=x;
            next=NULL;
        }
};

class Queue {
    Node* front;
    Node* rear;
    int currSize;
    public:
        Queue() {
            currSize=0;
            front=rear=NULL;
        }

        bool isEmpty() {
            return front==NULL;
        }

        void enqueue(int x) {
            Node* node=new Node(x);
            if(isEmpty()) {
                front=rear=node;
            }
            else {
                rear->next=node;
                rear=node;
            }
            currSize++;
        }

        int dequeue() {
            if(isEmpty()) {
                cout<<"Queue Underflow"<<endl;
                return -1;
            }
            Node* temp=front;
            int removedData=temp->data;
            front=front->next;
            if(front==NULL) rear=NULL;
            delete temp;
            currSize--;
            return removedData;
        }

        int getfront() {
            if(isEmpty()) {
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            return front->data;
        }

        int size() {
            return currSize;
        }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    cout<<"Dequeue: "<<q.dequeue()<<endl;
    q.enqueue(30);
    cout<<"Front: "<<q.getfront()<<endl;
    cout<<"Size: "<<q.size()<<endl;
    return 0;
}