#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    else return gcd(b, a%b);
}

int main() {
    int a, b;
    cout << "Enter numbers: ";
    cin >> a >> b;
    cout <<"The gcd is: "<< gcd(a,b) << endl; // recursive version of gcd
    cout << __gcd(a,b) << endl; // stl function for gcd
    return 0; 
}