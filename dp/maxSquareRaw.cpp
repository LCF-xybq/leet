class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		if (!matrix.size() || !matrix[0].size()) return 0;
		int row = matrix.size();
		int col = matrix[0].size();
		vector<vector<int>> dp(row, vector<int>(col));
		
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j)
				dp[i][j] = matrix[i][j] - '0';
		}

		int i = row - 2, j = col - 2;
		while (i >= 0 && j >= 0) {
			if (dp[i][j]) {
				dp[i][j] = 1 + min(min(dp[i+1][j], dp[i][j+1]), dp[i+1][j+1]);
			}
			if (j == 0) {
				i--;
				j = col - 2;
			} else {
				j--;
			}
		}

		int len = 0;
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j)
				len = max(len, dp[i][j]);
		}

		return len * len;
	}
};
