class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL || (root->left == NULL && root->right == NULL)) {
			return root;
		}
		TreeNode* tmp = root->left;
		root->left = invertTree(root->right);
		root->right = invertTree(tmp);

		return root;
	}
};
