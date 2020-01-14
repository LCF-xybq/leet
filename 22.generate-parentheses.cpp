/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
/* solution two (87.66%) : recursion */
private:
    vector<string> result;
public:
	void generateOneByOne(string sublist, int left, int right) {
		// cout << sublist << endl;
        //cout << left << " " << right << " " << sublist << endl;
		if (left == 0 && right == 0) {
           // cout << "he" << endl;
			result.push_back(sublist);
			return;
		}
		if (left > 0) {
			sublist.push_back('(');
			generateOneByOne(sublist, left - 1, right);
            int len = sublist.length();
            sublist.erase(len - 1);
		}
		if (right > left) {
			sublist.push_back(')');
			generateOneByOne(sublist, left, right - 1);
            int len = sublist.length();
            sublist.erase(len - 1);
		}
	}

    vector<string> generateParenthesis(int n) {
		if (n == 0) {
			result.push_back("");
			return result;
		}
		generateOneByOne("", n, n);
		return result;
    }
};
// @lc code=end

