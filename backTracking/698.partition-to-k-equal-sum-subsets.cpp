class Solution {
private:
  int n;
  int target;
  vector<int> path;
public:
  bool dfs(vector<int> nums, int cur, int k) {
    if (cur == n) return true;
    if (nums[cur] > target) return false;

    for (int i = 0; i < path.size(); i++) {
      if (path[i] + nums[cur] > target) continue;
      path[i] += nums[cur];
      if (dfs(nums, cur + 1, k)) return true;
      path[i] -= nums[cur];
    }
    if (path.size() == k) return false;
    path.push_back(nums[cur]);
    if (dfs(nums, cur + 1, k)) return true;
    path.pop_back();
    return false;
  }

  bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = 0;
    for (auto x : nums) sum += x;
    target = sum / k;
    sort(nums.begin(), nums.end(), greater<int>());
    n = nums.size();

    return dfs(nums, 0, k);
  }
};
