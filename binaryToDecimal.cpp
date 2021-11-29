#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define rep(i, a, b) for(int i = a;i<b;i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int val = 0;
    rep(i, 0, s.size()) {
        val += (s[i] - '0')*pow(2, s.size() - 1 - i);
    }
    cout << val << "\n";
    return 0;
}