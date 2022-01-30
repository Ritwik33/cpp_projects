#include<bits/stdc++.h>
using namespace std;

int maxHeightOfTriangle(int coin) {
    long a = 1, c = 1;
    long count = 1;
    while(1) {
        if(c == coin) {
            return count;
        } else if(c>coin) {
            count--;
            return count;
        } else {
            a++;
            c += a;
            count++;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    vector<int> coins(t);
    for(int i = 0;i<t;i++) cin >> coins[i];
    for(int i = 0;i<t;i++) {
        cout << maxHeightOfTriangle(coins[i]) << "\n";
    }
    return 0;
}