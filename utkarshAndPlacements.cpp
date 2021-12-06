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
        char first, second, third;
        cin >> first >> second >> third;
        map<char, int> priority;
        priority[{first}] = 3;
        priority[{second}] = 2;
        priority[{third}] = 1;
        char x, y;
        cin >> x >> y;
        if(priority[{x}] > priority[{y}]) cout << x << "\n";
        else cout << y << "\n";
    }
    return 0;
}