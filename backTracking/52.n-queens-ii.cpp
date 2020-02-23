/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */

// @lc code=start
class Solution {
private:
	int maxn;
	int n;
	int tot;
	int **vis;
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
	}

	void solve(int cur) {
		if (cur == n) tot++;
		else for (int i = 0; i < n; i++) {
			if (!vis[0][i] && !vis[1][cur + i] && !vis[2][cur - i + n]) {
				vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 1;
				solve(cur + 1);
				vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 0;
			}
		}
	}

    int totalNQueens(int n) {
        init(n);
	    solve(0);
	    return tot;
    }
};
// @lc code=end

