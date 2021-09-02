#include<bits/stdc++.h>
using namespace std;

int sum(int x1, int y1, int x2, int y2, vector<vector<int>>& prefix) {
    int temp = prefix[x2][y2];
    if(y1>0 && y2>0) temp -= prefix[x2][y1-1];
    if(x1>0 && x2>0) temp -= prefix[x1-1][y2];
    if(x1>0 && y1>0 && x2>0 && y2>0) temp += prefix[x1-1][y1-1];
    return temp;
}

void formPrefix(vector<vector<int>>& prefix, vector<vector<int>>& arr) {
    for(int i = 0;i<arr.size();i++) {
        for(int j = 0;j<arr[i].size();j++) {
            prefix[i][j] = arr[i][j];
            if(j>0) prefix[i][j] += prefix[i][j-1];
            if(i>0) prefix[i][j] += prefix[i-1][j];
            if(i>0 && j>0) prefix[i][j] -= prefix[i-1][j-1];
        }
    }
}

void display(vector<vector<int>>& mat) {
    for(int i = 0;i<mat.size();i++) {
        for(int j = 0;j<mat[i].size();j++) cout << mat[i][j] << " ";
        cout << "\n";
    }
}

int main() {
    int m, n;
    cout << "Enter rows and columns: ";
    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n, 0));
    cout << "Enter elements of the matrix:\n";
    for(int i = 0;i<m;i++) {
        for(int j = 0;j<n;j++) cin >> arr[i][j];
    }
    vector<vector<int>> prefix(m, vector<int>(n, 0));
    formPrefix(prefix, arr);
    cout << "The prefix matrix is:\n";
    display(prefix);
    int q;
    cout << "Enter number of queries: ";
    cin >> q;
    int x1, y1;
    int x2, y2;
    while(q--) {
        cout << "Enter x1, y1: ";
        cin >> x1 >> y1;
        cout << "Enter x2, y2: ";
        cin >> x2 >> y2;
        cout << "The sum is: " << sum(x1, y1, x2, y2, prefix) << "\n";  
    }
    return 0;
}