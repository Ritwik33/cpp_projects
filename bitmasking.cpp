#include<bits/stdc++.h>
using namespace std;
long long st = 0;

void add(int i) {
    st = st|(1<<i);
}

void del(int i) {
    st = st & ~(1<<i);
}

void print() {
    for(int i = 0;i<=60;i++) {
        if(st & (1<<i)) {
            cout << i << " ";
        }
    }
}
int main() {
    add(1);
    add(2);
    add(3);
    add(4);
    print();
    del(2);
    del(4);
    cout << endl;
    print();
    return 0;
}