#include<bits/stdc++.h>
using namespace std;

void print_array(int arr[], int n) {
    for(int i = 0;i<n;i++) cout << arr[i] << ' ';
    cout << endl << endl;
}

void insert_element(int ele, int pos, int arr[], int n) {
    for(int i = n-1;i>pos;i--) {
        arr[i] = arr[i-1];
    }
    arr[pos] = ele;
}

void delete_element(int ind, int arr[], int n) {
    for(int i = ind;i<n-1;i++) {
        arr[i] = arr[i+1];
    }
}

int find_key(int key, int arr[], int n) {
    for(int i = 0;i<n;i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n; 
    cout << "Enter size of the array: ";
    cin >> n;
    int arr[n];
    cout << endl;
    cout << "Enter the elements of the array:" << endl;
    for(int i = 0;i<n;i++) cin >> arr[i];
    int choice;
    cout << endl << endl;
    do {
        cout << "MAIN MENU" << endl;
        cout << "1. display array" << endl;
        cout << "2. Insert an element" << endl;
        cout << "3. Delete an element" << endl;
        cout << "4. Search an element" << endl;
        cout << "5. Exit" << endl;
        cout << "----------------" << endl;
        cout << "Enter a valid choice: ";
        cin >> choice;
        cout << endl << endl;
        switch(choice) {

            case 1:
            print_array(arr, n);
            break;

            case 2:
            int ele, pos;
            cout << "Enter element and position to insert: ";
            cout << endl;
            cin >> ele >> pos;
            n++;
            insert_element(ele, pos, arr, n);
            break;

            case 3:
            int ind;
            cout << "Enter index to delete the element from: ";
            cout << endl;
            cin >> ind;
            delete_element(ind, arr, n);
            n--;
            break;

            case 4:
            int key;
            cout << "Enter element to search: ";
            cout << endl;
            cin >> key;
            pos = find_key(key, arr, n);
            if(pos != -1) {
                cout << "Element found at " << pos;
                cout << endl << endl;
            } else cout << "Element not found" << endl << endl;
            break;

            default:
            cout << "Exiting..." << endl << endl;
            break;
        }
    } while(choice >= 1 and choice <= 4);
    return 0;
}