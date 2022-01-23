#include<bits/stdc++.h>
using namespace std;

#define endl                                                       '\n'
#define inf                                                        1e18
#define mod                                                        1000000007
#define int                                                        long long
#define vi                                                         vector<int>
#define vvi                                                        vector<vector<int>>
#define pb(x)                                                      push_back(x)
#define ppb                                                        pop_back()
#define rep(i, a, b)                                               for(int i = a;i<b;i++)
#define repd(i, a)                                                 for(int i = a;i>=0;i--)
#define setbits(x)                                                 __builtin_popcountll(x)
#define FIO                                                        ios_base::sync_with_stdio(false); cin.tie(NULL);

class node {
public:
	node *child[2];
	int cnt;
	node() {
		child[0] = child[1] = NULL;
	}
};

class trie {

	node *root = new node();

public:

	void insert(int num) {
		node *curr = root;
		repd(i, 29) {
			int b = (num >> i) & 1;
			if (curr -> child[b] == NULL) curr -> child[b] = new node();
			curr -> cnt++;
			curr = curr -> child[b];
		}
		curr -> cnt++;
	}

	int count(int num) {
		node *curr = root;
		repd(i, 29) {
			int b = (num >> i) & 1;
			if (curr -> child[b] == NULL) return 0;
			curr = curr -> child[b];
		}
		return curr -> cnt;
	}

	void erase(int num) {
		if (!count(num)) {
			cout << "Number DNE";
			return;
		}
		node *curr = root;
		vector<node*> del;
		repd(i, 29) {
			curr -> cnt--;
			int b = (num >> i) & 1;
			node *go_to = curr -> child[b];
			if (go_to -> cnt == 1) {
				curr -> child[b] = NULL;
				del.pb(go_to);
			}
			curr = go_to;
		}
		curr -> cnt--;
		for (node *temp : del) delete temp;
	}
};

void solve() {

}

int32_t main() {
	FIO;

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}