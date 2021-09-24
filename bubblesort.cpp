#include<bits/stdc++.h>
using namespace std;

void sort(vector<int>& arr) {
    for(int i = 0;i<arr.size()-1;i++) {
        bool swapped = false;
        for(int j = 0;j<arr.size() - i -1;j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        if(!swapped) return;
    }
}

void display(vector<int>& arr) {
    for(auto itr:arr) cout << itr << " ";
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0;i<n;i++) cin >> arr[i];
    sort(arr);
    display(arr);
    return 0;
}