/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution {
private:
	int maxn;
	int n;
	int tot;
	int **vis;
	int c[10];
	vector<vector<string> > res;
public:
	void init(int n) {
		maxn = 105;
		tot = 0;
		this->n = n;
		vis = new int* [3];
		for (int i = 0; i < 3; i++) {
			vis[i] = new int[105];
		}

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 105; j++)
				vis[i][j] = 0;

		for (int i = 0; i < 8; i++) c[i] = 0;
	}

	void solve(int cur) {
		if (cur == n) {
			res.push_back(vector<string>());
			string t;
			char *ch = new char[n];
			for (int i = 0; i < n; i++) ch[i] = '.';
			for (int k = 0; k < n; k++) {
				ch[c[k]] = 'Q';
				for (int j = 0; j < n; j++) t.push_back(ch[j]);			
				res[tot].push_back(t);
				t.clear();
				ch[c[k]] = '.';
			}
			
			tot++;
		}
		else for (int i = 0; i < n; i++) {
			if (!vis[0][i] && !vis[1][cur + i] && !vis[2][cur - i + n]) {
				c[cur] = i;
				vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 1;
				solve(cur + 1);
				vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 0;
			}
		}
	}

	vector<vector<string> > solveNQueens(int n) {
        init(n);
	    solve(0);
	    return res;
	}
};
// @lc code=end

