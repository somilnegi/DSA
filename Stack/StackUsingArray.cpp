#include<bits/stdc++.h>
using namespace std;

class Stack {

    int *arr;
    int capacity;
    int topElement;

    public:

        Stack(int cap) {
            capacity=cap;
            arr=new int[capacity];
            topElement=-1;
        }

        void push(int x) {
            if(topElement==capacity-1) {
                cout<<"Stack Overflow\n";
                return;
            }
            arr[++topElement]=x;
        }

        int pop() {
            if(topElement==-1) {
                cout<<"Stack Underflow\n";
                return -1;
            }
            return arr[topElement--];
        }

        int top() {
            if(topElement==-1) {
                cout<<"Stack is empty!\n";
                return -1;
            }
            return arr[topElement];
        }

        bool isEmpty() {
            return topElement==-1;
        }

        bool isFull(){
            return topElement==capacity-1;
        }
};

int main() {
    Stack st(4);
    st.push(1);
    st.push(8);
    st.push(4);
    st.push(13);
    cout<<"Top element:"<<st.top()<<"\n";
    cout<<"Popped:"<<st.pop()<<"\n";
    cout<<"Is stack empty:"<<(st.isEmpty()?"Yes": "No")<<"\n";
    cout<<"Is stack full:"<<(st.isFull()?"Yes": "No")<<"\n";
}
