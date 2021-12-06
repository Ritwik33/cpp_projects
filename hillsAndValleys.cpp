#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vi2 vector<vector<int>>
#define rep(i, a, b) for(int i = a;i<b;i++)
#define repd(i, a) for(int i = a;i>=0;i--)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int size = n + m + 2;
        int i = 0;
        string str = "";
        if(n >= m) str += '0';
        else str += '1';
        while(i < size - 1) {
            if(str[i] == '0') str += '1';
            else str += '0';
            i++;
        }
        cout << size << "\n" << str << "\n";
    }
    return 0;
}