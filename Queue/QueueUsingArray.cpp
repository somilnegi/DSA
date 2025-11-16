#include<bits/stdc++.h>
using namespace std;

class Queue {
    int *arr;
    int capacity;
    int currSize;

    public: 
        Queue(int c) {
            capacity=c;
            arr=new int[capacity];
            currSize=0;
        }

        bool isEmpty() {
            return currSize==0;
        }

        bool isFull() {
            return currSize==capacity;
        }

        void enqueue(int x) {
            if(isFull()) {
                cout<<"Queue is full\n";
                return;
            }
            arr[currSize]=x;
            currSize++;
        }
        
        void dequeue() {
            if(isEmpty()) {
                cout<<"Queue is empty\n";
                return;
            }
            for(int i=1; i<currSize; i++) {
                arr[i-1]=arr[i];
            }
            currSize--;
        }

        int getFront(){
            if(isEmpty()) {
                cout<<"Queue is empty\n";
                return -1;
            }
            return arr[0];
        }

        int getRear(){
            if(isEmpty()) {
                cout<<"Queue is empty\n";
                return -1;
            }
            return arr[currSize-1];
        }
};

int main() {
    Queue q(3);
    q.enqueue(10);
    q.enqueue(19);
    q.enqueue(3);
    cout<<"Front: "<<q.getFront()<<endl;
    q.dequeue();
    cout<<"Front: "<<q.getFront()<<endl;
    cout<<"Rear: "<<q.getRear()<<endl;
    q.enqueue(34);
    return 0;
}