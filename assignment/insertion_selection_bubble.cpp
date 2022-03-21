#include<bits/stdc++.h>
using namespace std;

void print_array(int arr[], int n) {
    cout << "The sorted array is: ";
    for(int i = 0;i<n;i++) cout << arr[i] << ' ';
    cout << endl;
}

void insertion_sort(int arr[], int n) {
    for(int i = 1;i<n;i++) {
        int key = arr[i];
        int j = i-1;
        while(j >= 0 and arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void selection_sort(int arr[], int n) {
    for(int i = 0;i<n-1;i++) {
        int index = i;
        for(int j = i+1;j<n;j++) {
            if(arr[j] < arr[index]) {
                index = j;
            }
        }
        swap(arr[i], arr[index]); 
    }
}

void bubble_sort(int arr[], int n) {
    for(int i = 0;i<n-1;i++) {
        for(int j = 0;j<n-i-1;j++) {
            if(arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
        } 
    }
}

int main() {
    int n;
    cout << "Enter size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter contents of the array:" << endl;
    for(int i = 0;i<n;i++) cin >> arr[i];
    // insertion_sort(arr, n);
    // selection_sort(arr, n);
    bubble_sort(arr, n);
    print_array(arr, n);
    return 0;
}