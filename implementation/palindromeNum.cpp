#include<bits/stdc++.h>
using namespace std;

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    int num_clone = num;
    int sum = 0;
    while(num>0) {
        sum = sum*10 + num%10;
        num /= 10;
    }
    if(sum == num_clone) cout << "yes";
    else cout << "no";
    return 0;
}