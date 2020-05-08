class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int row = matrix.size();
		if (row == 0) return 0;
		int col = matrix[0].size();
		if (col == 0) return 0;
		vector<vector<int>> dp(row+1, vector<int>(col+1, 0));

		int len = 0;
		for (int i = 1; i <= row; ++i) {
			for (int j = 1; j <= col; ++j) {
				if (matrix[i-1][j-1] == '1') {
					dp[i][j] = 1 + min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
					len = max(len, dp[i][j]);
				}
			}
		}
		return len * len;
	}
};
