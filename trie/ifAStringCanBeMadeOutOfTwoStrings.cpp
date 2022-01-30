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
#define ps(x, y)                                                   fixed << setprecision(y) << x
#define w(q)                                                       int q; cin >> q; while(q--)
#define FIO                                                        ios_base::sync_with_stdio(false); cin.tie(NULL);

class node {
public:
	int ends;
	unordered_map<char, node*> child;
	node() {
		ends = 0, child = {};
	}
};

class trie {
public:
	node *root;
	vector<char> word;
	trie() {
		root = new node();
	}
	void insert(const string& word) {
		node *cur = root;
		for (char ch : word) {
			if (cur -> child[ch] == NULL) cur -> child[ch] = new node();
			cur = cur -> child[ch];
		}
		cur -> ends++;
	}
	int search(const string& word, vector<int>& arr) {
		node *cur = root;
		rep(i, 0, word.size()) {
			if ((cur -> child).count(word[i]) == 0) return false;
			if (cur -> child[word[i]] -> ends >= 1) arr[i] = 1;
			cur = cur -> child[word[i]];
		}
	}
};

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	string a[n];
	rep(i, 0, n) cin >> a[i];
	string fs, bs;
	fs = s;
	bs = string(s.rbegin(), s.rend());
	string aRev[n];
	rep(i, 0, n) {
		aRev[i] = string(a[i].rbegin(), a[i].rend());
	}
	vector<int> prefix(fs.size());
	vector<int> suffix(bs.size());
	trie tf, tb;
	rep(i, 0, n) {
		tf.insert(a[i]);
	}
	rep(i, 0, n) {
		tb.insert(aRev[i]);
	}
	tf.search(fs, prefix);
	tb.search(bs, suffix);
	int flag = 0;
	rep(i, 0, prefix.size() - 1) {
		if (prefix[i] == suffix[suffix.size() - i - 2]) {
			flag = 1;
			break;
		}
	}
	flag ? (cout << "YES" << endl) : (cout << "NO" << endl);
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