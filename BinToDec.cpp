#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int res=0;
    int i=0;

    while(n!=0){
        int digit = n%10;
        if(digit==1){
            res+=pow(2,i);
        }

        n = n/10;
        i++;
    }
    cout<<res<<endl;
}