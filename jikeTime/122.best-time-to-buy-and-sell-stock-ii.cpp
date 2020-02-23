/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int i = 0, j = 1;
        int sum = 0;
        for (; j < len; i++, j++) {
            if (prices[j] <= prices[i]) continue;
            else {
                sum = sum + prices[j] - prices[i];
            }
        }
        return sum;
    }
};
// @lc code=end

