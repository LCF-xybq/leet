class Solution {
public:
	bool similar(TreeNode* s, TreeNode* t) {
		if (!s && !t) {
			return true;
		}
		if (s && t && s->val == t->val) {
			return similar(s->left, t->left) && similar(s->right, t->right);
		}
		return false;
	}

	bool isSubtree(TreeNode* s, TreeNode* t) {
		if (!s && t) return false;
		return similar(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
	}
}
