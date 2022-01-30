#include<bits/stdc++.h>
using namespace std;

bool subs(int count, int index, vector<int> &ds, vector<int> &vec, int size, int sum) {
    if(index == size) {
        if(sum == count) {
            for(auto it:ds) cout << it << " ";
            return true;
        }
        return false;
    }
    ds.push_back(vec[index]);
    if(subs(count+vec[index], index+1, ds, vec, size, sum)==true) return true;
    ds.pop_back();
    if(subs(count, index+1, ds, vec, size, sum)==true) return true;
    return false;
}

int  main() {
    int size;
    cout << endl << "Enter size: ";
    cin >> size;
    vector<int> vec(size,0);
    cout << endl << "Enter the elements:" << endl;
    for(int i = 0;i<size;i++) cin >> vec[i];
    int sum;
    cout << endl << "Enter sum: ";
    cin >> sum;
    vector<int> ds;
    cout << endl << "One subsequence with such a sum is:" << endl;
    subs(0, 0, ds, vec, size, sum);
    return 0;
}