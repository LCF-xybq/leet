class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (!strs.size()) {
			return "";
		} else {
			return longCommon(strs, 0, strs.size() - 1);
		}
	}

	string longCommon(vector<string>& strs, int start, int end) {
		if (start == end) {
			return strs[start];
		}
		int mid = start + (end - start) / 2;
		string lcLeft = longCommon(strs, start, mid);
		string lcRight = longCommon(strs, mid + 1, end);
		return solve(lcLeft, lcRight);
	}

	string solve(const string lcLeft, const string lcRight) {
		int cnt = min(lcLeft.size(), lcRight.size());
		for (int i = 0; i < cnt; i++) {
			if (lcLeft[i] != lcRight[i]) {
				return lcLeft.substr(0, i);
			}
		}
		return lcLeft.substr(0, cnt);
	}
};
