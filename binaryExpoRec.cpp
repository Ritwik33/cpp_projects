#include<bits/stdc++.h>
using namespace std;
 
int power(int base, int n) {
    if(n == 0) return 1;
    else if(n%2 == 0) return power(base*base, n/2);
    else return base*power(base, n-1);
}

int main() {
    int base, n;
    cin >> base >> n;
    cout << power(base, n);
    return 0;
}