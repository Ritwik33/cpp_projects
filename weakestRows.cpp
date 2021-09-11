#include<bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> mat(m, vector<int>(n));
    for(int i = 0;i<m;i++) {
        for(int j = 0;j<n;j++) cin >> mat[i][j];
    }
    vector<int> vec(m);
    for(int i = 0;i<mat.size();i++) {
        int low = 0;
        int high = mat[i].size() - 1;
        while(low<=high) {
            int mid = low + (high - low)/2;
            if(mat[i][mid] == 0) high = mid-1;
            else low = mid +1;
        }
        vec[i] = low;
    }
    int k;
    cin >> k;
    vector<int> ans(k);
    vector<int> vec_clone(m);
    for(int i = 0;i<m;i++) vec_clone[i] = vec[i];
    sort(vec_clone.begin(), vec_clone.end());
    for(int i = 0;i<k;i++) {
        for(int j = 0;j<m;j++) {
            if(vec[j] == vec_clone[i]) {
                ans[i] = j;
                vec[j] = -1;
                break;
            }
        }
    }
    for(int i:ans) cout << i << " ";
    return 0;
}