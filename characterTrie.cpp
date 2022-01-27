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
	int pre, ends;
	unordered_map<char, node*> child;
	node() {
		pre = ends = 0;
		child = {};
	}
};

class trie {
	node *root;
public:
	trie() {
		root = new node();
	}

	void insert(const string& word) {
		node *curr = root;
		for (char ch : word) {
			curr -> pre++;
			if (!curr -> child[ch]) {
				curr -> child[ch] = new node();
			}
			curr = curr -> child[ch];
		}
		curr -> pre++, curr -> ends++;
	}

	int count(const string& word) {
		node *curr = root;
		for (char ch : word) {
			if (!(curr -> child).count(ch)) return 0;
			curr = curr -> child[ch];
		}
		return curr -> ends;
	}

	int startsWith(const string& prefix) {
		node *curr = root;
		for (char ch : prefix) {
			if (!(curr -> child).count(ch)) return 0;
			curr = curr -> child[ch];
		}
		return curr -> pre;
	}

	bool erase(const string& word) {
		if (!count(word)) return false;
		node *curr = root;
		for (char ch : word) {
			curr -> pre--;
			curr = curr -> child[ch];
		}
		curr -> pre--, curr -> ends--;
		return true;
	}

	node *erase_aux(node *curr, const string& word, int i) {
		curr -> pre--;
		int n = word.length();
		if (i == n - 1) curr -> ends--;
		else {
			curr -> child[word[i + 1]] = erase_aux(curr -> child[word[i + 1]], word, i + 1);
			if (curr -> child[word[i + 1]] == NULL) {
				(curr -> child).erase(word[i + 1]);
			}
		}
		if (curr -> pre) return curr;
		delete curr;
		return NULL;
	}

	bool erase_actual(const string& word) {
		if (!count(word)) return false;
		root -> child[word[0]] = erase_aux(root -> child[word[0]], word, 0);
		return true;
	}

};

void solve() {
	trie t;
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