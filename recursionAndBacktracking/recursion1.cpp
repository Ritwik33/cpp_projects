#include<bits/stdc++.h>
#define N 10
using namespace std;

void print(int num) {
    if(num>N) return;
    else cout<<num<<" ";
    print(num+1);
}

int main() {
    int num;
    cin>>num;
    print(num);
    return 0;
}