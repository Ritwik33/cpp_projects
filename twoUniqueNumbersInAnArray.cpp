#include<bits/stdc++.h>
using namespace std;

void twoUniqueNumbers(vector<int>& arr) {
    int synd = 0;
    for(int i = 0;i<arr.size();i++) synd ^= arr[i]; // XORing over all the elements of the array ...
    int pos = 0;
    while(synd) { 
        // knowing the position of the first bit where the two numbers differ ...
        if(synd & 1) break;
        pos++;
        synd >>= 1;
    }
    int var1 = 0, var2 = 0;
    for(int i = 0;i<arr.size();i++) {
        // loop to segregate the numbers of the array according to the first different bit ... 
        if(arr[i] & (1<<pos)) var1 ^= arr[i]; // condition to check whether the bit of the arr[i] is set or not ...
        else var2 ^= arr[i]; // eventually the duplicates will get cancelled and only the unique one will be remaining ...
    }
    cout << var1 << " " << var2;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0;i<n;i++) cin >> arr[i];
    twoUniqueNumbers(arr);
    return 0;
}