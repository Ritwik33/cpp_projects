#include<bits/stdc++.h>
using namespace std;

int lde(int a, int b, int& x0, int& y0) {
    if(b == 0) {
        x0 = 1;
        y0 = 0;
        return a;
    }
    int x1, y1;
    int g = lde(b, a%b, x1, y1);
    x0 = y1;
    y0 = x1 - (a/b)*y1;
    return g;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int x0, y0;
    int g = lde(a, b, x0, y0);
    x0 = (x0*c)/g;
    y0 = (y0*c)/g;
    for(int k = 0;k<=10;k++) {
        x0 += (k*b)/g;
        y0 -= (k*a)/g;
        cout << x0 << " " << y0 << "\n";
    }
    return 0;
}