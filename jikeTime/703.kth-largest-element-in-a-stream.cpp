/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */

// @lc code=start
class KthLargest {
    priority_queue<int, vector<int>, greater<int> > q;
    int kk;
public:
    KthLargest(int k, vector<int>& nums) {
        kk = k;
        for (int i = 0; i < nums.size(); i++) {
            q.push(nums[i]);
            if (q.size() > k) q.pop();
        }
    }
    
    int add(int val) {
        q.push(val);
        if (q.size() > kk) q.pop();
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

