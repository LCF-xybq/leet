class Solution {
public:
  int maxProfit(int k, vector<int>& prices) {
    if (prices.empty()) return 0;
    int len = prices.size();
    if (k > len / 2) return greedy(prices);

    int mp[len][2][k + 1];
    for (int i = 0; i <= k; i++) {
      mp[0][0][i] = 0;
      mp[0][1][i] = -prices[0];
    }
    for (int i = 1; i < prices.size(); i++) {
      for (int j = 0; j <= k; j++) {
        if (j == 0) {
          mp[i][0][j] = mp[i - 1][0][j];
        } else {
          mp[i][0][j] = max(mp[i - 1][0][j], mp[i - 1][1][j - 1] + prices[i]);
        }
        mp[i][1][j] = max(mp[i - 1][1][j], mp[i - 1][0][j] - prices[i]);
      }
    }

    int Max = INT_MIN;
    for (int i = 0; i <= k; i++) {
      Max = max(Max, mp[len - 1][0][i]);
    }

    return Max;
  }

  int greedy(vector<int> prices) {
    int Max = 0;
    for (int i = 1; i < prices.size(); i++) {
      if (prices[i] > prices[i - 1])
        max += prices[i] - prices[i - 1];
    }
    return max;
  }
};
