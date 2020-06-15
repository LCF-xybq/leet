class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (!strs.size()) return "";
		string first = strs[0];
		int cnt = first.size();

		for (int i = 1; i < strs.size(); i++) {
			int j = 0;
			for (; j < cnt && j < strs[i].size(); j++) {
				if (first[j] == strs[i][j]) continue;
				else break;
			}
			cnt = min(cnt, j);
		}
		return first.substr(0, cnt);
	}
};
