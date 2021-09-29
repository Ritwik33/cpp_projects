#include<bits/stdc++.h>
using namespace std;

void swap(int loc1, int loc2, int arr[]) {
    int temp = arr[loc1];
    arr[loc1] = arr[loc2];
    arr[loc2] = temp;
}

int partition(int low, int high, int arr[]) {
    int pivot = arr[high];
    int i = low-1;
    for(int j = low;j<high;j++) {
        if(arr[j] < pivot) {
            i++;
            swap(i, j, arr);
        }
    }
    swap(i+1, high, arr);
    return i+1;
}

void quicksort(int low, int high, int arr[]) {
    if(low >= high) return;
    int pi = partition(low, high, arr);
    quicksort(low, pi-1, arr);
    quicksort(pi+1, high, arr);
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i<n;i++) cin >> arr[i];
    quicksort(0, n-1, arr);
    for(auto it:arr) cout << it << " ";
    return 0;
}