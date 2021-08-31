#include<bits/stdc++.h>
using namespace std;

int val(char ch) {
    if(ch == 'I') return 0;
    else if(ch == 'V') return 1;
    else if(ch == 'X') return 2;
    else if(ch == 'L') return 3;
    else if(ch == 'C') return 4;
    else if(ch == 'D') return 5;
    else if(ch == 'M') return 6;
}

int main() {
    string s;
    cin >> s;
    int arr[] = {1, 5, 10, 50, 100, 500, 1000};
    int total = 0;
    for(int i = 0;i<s.size();i++) {
        if(val(s[i])<val(s[i+1])) {
            total += -arr[val(s[i])];
        } else {
            total += arr[val(s[i])];
        }
    }
    cout << total;
    return 0;
}