#include<bits/stdc++.h>
using namespace std;

bool palindrome(int l, int r, string s) {
    if(s[l] != s[r]) return false;
    else if(l>r) return true;
    else return palindrome(++l, --r, s);
}

int main() {
    string s;
    cin >> s;
    int count = 0;
    bool b = palindrome(0, s.size()-1, s);
    if(b == true) cout << "Yes";
    else cout << "No";
    return 0;
}