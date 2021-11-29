#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string str = "";
    while(n) {
        if(n%2) str += '1';
        else str += '0';
        n = n>>1;
    }
    
    int l = 0, r = str.size() - 1;
    while(l<=r) {
        swap(str[l], str[r]);
        l++;
        r--;
    }
    
    cout << str << "\n";
    return 0;
}