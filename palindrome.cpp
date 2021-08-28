#include<bits/stdc++.h>
using namespace std;

bool palindrome(int l, int r, string &name) {
    if(l>=r) return true;
    else if(name[l]!=name[r]) return false;
    return palindrome(++l,--r,name);
}

int main() {
    string name;
    cout<<"Enter a string: ";
    cin >> name;
    int l = 0;
    int r = name.length() - 1;
    if(palindrome(l,r,name)==false) cout<<"not a palindrome"<<endl;
    else cout<<"palindrome"<<endl;
    return 0;
}