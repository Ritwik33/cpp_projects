#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i<n;i++) cin >> arr[i];
    int k;
    cin >> k;
    int count = 0;
    for(int num = 0;num<=(1<<n)-1;num++) {
        int sum = 0;
        for(int i = 0;i<n;i++) {
            if(num & (1<<i)) {
                sum += arr[i];
            }
        }
        if(sum%k == 0) {
            count++;
        }
    }
    cout << count;
    return 0;
}