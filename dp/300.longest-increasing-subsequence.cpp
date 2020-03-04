class Solution {
public:
  int lengthOfLTS(vector<int>& nums) {
    if (nums.empty()) return 0;
    int len = nums.size();
    if (len == 1) return 1;
    int dp[len];
    dp[0] = 1;
    for (int i = 0; i < len; i++) {
      int max = 0;
      for (int j = 0; j < i; j++) {
        if (max <= dp[j] && nums[j] < nums[i]) max = dp[j];
      }
      dp[i] = max + 1;
    }
    int res = 0;
    for (int i = 0; i < len; i++) {
      if (res < dp[i]) res = dp[i];
    }
    return res;
  }
};
