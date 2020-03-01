class Solution {
public:
  int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;
    int len = prices.size();
    if (len <= 3) return greedy(prices);
    int mp[len][2][3];
    for (int i = 0; i < 3; i++) {
      mp[0][0][i] = 0;
      mp[0][1][i] = -prices[0];
    }

    for (int i = 1; i < len; i++) {
      for (int j = 0; j < 3; j++) {
        if (j == 0) {
          mp[i][0][j] = mp[i - 1][0][j];
        } else {
          mp[i][0][j] = max(mp[i - 1][0][j], mp[i - 1][1][j - 1] + prices[i]);
        }
        mp[i][1][j] = max(mp[i - 1][1][j], mp[i - 1][0][j] - prices[i]);
      }
    }

    int Max = INT_MIN;
    for (int i = 0; i < 3; i++) {
      Max = max(Max, mp[len - 1][0][i]);
    }
  }

  int greedy(vector<int> prices) {
    int max = 0;
    for (int i = 1; i < prices.size(); i++) {
      if (prices[i] > prices[i - 1])
        max += prices[i] - prices[i - 1];
    }
    return max;
  }
};
