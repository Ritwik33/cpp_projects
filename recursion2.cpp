#include<bits/stdc++.h>
#define N 10
using namespace std;

void print(int i) {
    if(i>N) return;
    else {
        print(i+1);
        cout<<i<<" ";
    }
}

int main() {
    int num;
    cin >> num;
    print(num);
    return 0;
}