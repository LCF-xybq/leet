/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
class Solution {
    deque<int> data;
public:
    void push(int n) 
    {
    	while (!data.empty() && data.back() < n)
	    	data.pop_back();
	    data.push_back(n);
    }

    int max()
    {
	    return data.front();
    }

    void pop(int n)
    {
	    if (!data.empty() && data.front() == n)
		    data.pop_front();
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
	    for (int i = 0; i < nums.size(); i++) {
	    	if (i < k - 1) {
			    push(nums[i]);
		    } else {
		    	push(nums[i]);
			    res.push_back(max());
			    pop(nums[i-k+1]);
		    }
	    }
	    return res;
    }   
};
// @lc code=end

