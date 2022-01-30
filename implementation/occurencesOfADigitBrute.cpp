#include<bits/stdc++.h>
using namespace std;

int cntDigitsD(int num, int digit) {
    int cnt = 0;
    while(num != 0) {
        int temp = num%10;
        num /= 10;
        if(temp == digit) cnt++; 
    }
    return cnt;
}

int main() {
    int l, r, d, k;
    cin >> l >> r >> d >> k;
    int cnt = 0;
    for(int i = l;i<=r;i++) {
        if(cntDigitsD(i, d) == k) cnt++;
    }
    cout << cnt << endl;
    return 0;
}