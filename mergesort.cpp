#include<bits/stdc++.h>
using namespace std;

void mergeSubs(int arr[], int low, int mid, int high) {
    int leftSize = mid-low+1;
    int rightSize = high-mid;
    int left[leftSize];
    int right[rightSize];
    for(int i = 0;i<leftSize;i++) left[i] = arr[low+i];
    for(int i = 0;i<rightSize;i++) right[i] = arr[mid+1+i];
    int i, j, k;
    i = j = 0;
    k = low;
    while(i < leftSize && j < rightSize) {
        if(left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while(i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int low, int high, int n) {
    if(low >= high) return;
    int mid = low + (high-low)/2;
    mergesort(arr, low, mid, n);
    mergesort(arr, mid+1, high, n);
    mergeSubs(arr, low, mid, high);
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i<n;i++) cin >> arr[i];
    for(int itr:arr) cout << itr << " ";
    mergesort(arr, 0, n-1, n);
    cout << "\n";
    for(int itr:arr) cout << itr << " ";
    return 0;
}