#include<bits/stdc++.h>
using namespace std;

int main() {
    int ps;
    cin >> ps;
    vector<int> road(ps + 1, 0);
    vector<int> prefix(ps+2, 0);
    int strLig;
    cin >> strLig;
    int xi, ri;
    int l, r;
    while(strLig--) {
        cin >> xi >> ri;
        l = xi-ri;
        r = xi+ri;
        if(l < 0) l = 0;
        if(r > ps) r = ps;
        prefix[l] += 1;
        prefix[r+1] -= 1;
    }
    int count = 0;
    for(int i = 0;i<ps+1;i++) {
        if(road[i] != 1) count++;
        else count = 0;
        if(count > ps+1) count = ps+1;
    }
    cout << count;
    return 0;
}