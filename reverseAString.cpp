#include<bits/stdc++.h>
using namespace std;

int main() {
    string s = "Ritwik";
    int l = 0, r = s.size() - 1;
    char temp;
    while(l<=r) {
        temp = s[l];
        s[l] = s[r];
        s[r] = temp;
        l++;
        r--;
    }
    cout << s;
    return 0;
}