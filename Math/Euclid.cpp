#include<bits/stdc++.h>
using namespace std;

// int GCD(int c, int d){
//     if(c==0){
//         return d;
//     }
//     if(d==0){
//         return c;
//     }
//     while(c!=d){
//         if(c>d){
//             c=c-d;
//         }
//         else{
//             d=d-c;;
//         }
//     }
//     return c;
// }

// The modulo based algo is better and efficient
int GCD(int c, int d){
    int temp;
    while(d!=0){
        temp=d;
        d=c%d;
        c=temp;
    }
    return c;
}

int main(){
    int a,b;
    cout<<"Enter the values of a and b"<<endl;
    cin>>a>>b;
    int ans=GCD(a,b);
    cout<<"The GCD of "<<a<<" & "<<b<<" is "<<ans<<endl;
    return 0;
}