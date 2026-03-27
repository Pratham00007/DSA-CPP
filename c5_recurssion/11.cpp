// fibonnaci series

// need to do

#include<bits/stdc++.h>
using namespace std;

int fib(int num){
    if (num == 0 || num==1){
        return 0;
    }
    int fir=0;
    int sec=1;

    cout<<fir;
    cout<<sec;
    int sum=fir+sec;
    
    for (int i=0;i<=num;i++){
    int temp=sum;
    cout<<sum;
    sum+=temp;
    }
    
}
int main(){
    cout<<"Enter number";
    int num;
    cin>>num;
    fib(num);
}