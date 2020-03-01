class Solution {
public:
  int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;
    int len = prices.size();
    int mp[len][2], res = 0;
    mp[0][0] = 0;
    mp[0][1] = -prices[0];

    for (int i = 1; i < len; i++) {
      mp[i][0] = max(mp[i - 1][0], mp[i - 1][1] + prices[i]);
      mp[i][1] = max(mp[i - 1][1], mp[i - 1][0] - prices[i]);
      res = max(res, max(mp[i][0], mp[i][1]));
    }

    return res;
  }
};
