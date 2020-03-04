class Solution {
public:
  int maxProduct(vector<int>& nums) {
    int curMax = 1, curMin = 1;
    int res = INT_MIN;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] < 0) {
        swap(curMax, curMin);
      }
      curMax = max(nums[i], curMax * nums[i]);
      curMin = min(nums[i], curMin * nums[i]);
      res = max(res, curMax);
    }
    return res;
  }
};
