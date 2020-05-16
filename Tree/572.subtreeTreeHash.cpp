class Solution {
public:
	static constexpr int MAX_N = 1000 + 5;
	static constexpr int MOD = int(1E9) + 7;

	bool vis[MAX_N];
	int p[MAX_N], tot;
	void getPrime() {
		vis[0] = vis[1] = 1; tot = 0;
		for (int i = 2; i < MAX_N; ++i) {
			if (!vis[i]) p[++tot] = i;
			for (int j = 1; j <= tot && i * p[j] < MAX_N; ++j) {
				vis[i * p[j]] = 1;
				if (i % p[j] == 0) break;
			}
		}
	}

	struct Status {
		int f, s;
		Status(int ff = 0, int ss = 0) : f(ff), s(ss) {}
	};

	unordered_map<TreeNode *, Status> hs, ht;

	void dfs(TreeNode* o, unordered_map<TreeNode *, Status> &h) {
		h[o] = Status(o->val, 1);
		if (!o->left && !o->right) return;
		if (o->left) {
			dfs(o->left, h);
			h[o].s += h[o->left].s;
			h[o].f = (h[o].f + (31LL * h[o->left].f * p[h[o->left].s]) % MOD) % MOD;
		}
		if (o->right) {
			dfs(o->right, h);
			h[o].s += h[o->right].s;
			h[o].f = (h[o].f + (179LL * h[o->right].f * p[h[o->right].s]) % MOD) % MOD;
		}
	}
	
	bool isSubtree(TreeNode* s, TreeNode* t) {
		getPrime();
		dfs(s, hs);
		dfs(t, ht);

		int tHash = ht[t].f;
		for (const auto &[k,v] : hs) {
			if (v.f == tHash) {
				return true;
			}
		}
		return false;
	}
};
