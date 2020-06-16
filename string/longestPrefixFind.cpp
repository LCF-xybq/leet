class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string res = strs.empty() ? "" : strs[0];
		for (string s : strs) 
			while (s.find(res) != 0) res = res.substr(0, res.size() - 1);
		return res;
	}
};
