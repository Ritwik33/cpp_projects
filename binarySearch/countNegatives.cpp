#include<bits/stdc++.h>
using namespace std;

int count(vector<vector<int>>& arr) {
    int low, high = arr[0].size()-1, count = 0;
    for(int i = 0;i<arr.size();i++) {
        low = 0;
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(arr[i][mid] < 0) high = mid-1;
            else low = mid+1;
        }
        count += arr[i].size() - low;
    }
    return count;
}

int main() {
    int row, col;
    cin >> row >> col;
    vector<vector<int>> arr(row, vector<int>(col));
    for(int i = 0;i<row;i++) {
        for(int j = 0;j<col;j++) cin >> arr[i][j];
    }
    cout << count(arr);
    return 0;
}