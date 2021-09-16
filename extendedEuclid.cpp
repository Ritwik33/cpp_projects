#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b, int& x0, int& y0) {
    if(b == 0) {
        x0 = 1;
        y0 = 0;
        return a;
    }
    int x1, y1;
    int g = gcd(b, a%b, x1, y1);
    x0 = y1;
    y0 = x1 - (a/b)*y1;
    return g;
}

int main() {
    int a, b;
    cout << "Enter a and b: ";
    cin >> a >> b;
    int x0, y0;
    int g = gcd(a, b, x0, y0);
    cout << "The gcd is: " << g << "\n";
    cout << "The solution to bennot's identity is x0 = " << x0 << " y0 = " << y0 << "\n";
    return 0;
}