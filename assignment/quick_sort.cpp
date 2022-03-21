#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low;j<=high-1;j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return (i+1);
}

void quick_sort(int low, int high, int arr[], int n) {
    if(low >= high) return;
    int pi = partition(arr, low, high);
    quick_sort(low, pi - 1, arr, n);
    quick_sort(pi + 1, high, arr, n);
}

void print_array(int arr[], int n) {
    for(int i = 0;i<n;i++) cout << arr[i] << ' ';
    cout << endl;
}

int main() {
    int n; 
    cout << "Enter size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter contents of the array: " << endl;
    for(int i = 0;i<n;i++) cin >> arr[i];
    quick_sort(0, n-1, arr, n);
    print_array(arr, n);
    return 0;
}