#include<bits/stdc++.h>
using namespace std;

int countSubs(int count, int index, int arr[], int sum, int size) {
    if(index == size) return count == sum;
    int pick = countSubs(count+arr[index], index+1, arr, sum, size);
    int not_pick = countSubs(count, index+1, arr, sum, size);
    return pick + not_pick;
}

int main() {
    int size;
    cout << "size: ";
    cin >> size;
    int arr[size];
    cout << "elements:"<<endl;
    for(int i = 0;i<size;i++) cin >> arr[i];
    int sum;
    cout << "sum: ";
    cin >> sum;
    cout << "number of such subsequences = "<<countSubs(0, 0, arr, sum, size)<<endl;
    return 0;
}