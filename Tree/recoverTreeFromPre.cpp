class Solution {
public:
	TreeNode* recoverFromPreorder(string S) {
		stack<TreeNode *> path;
		int pos = 0;
		while (pos < S.size()) {
			int level = 0;
			while (S[pos] == '-') {
				++pos;
				++level;
			}
			int val = 0;
			while (pos < S.size() && S[pos] != '-') {
				val = val * 10 + (S[pos] - '0');
			}
			TreeNode* node = new TreeNode(val);

			if (level == path.size()) {
				if (!path.empty()) {
					path.top()->left = node;
				}
			} else {
				while (level != path.size()) {
					path.pop();
				}
				path.top()->right = node;
			}
			path.push(node);
		}
		while (path.size() > 1) {
			path.pop();
		}
		return path.top();
	}
};
