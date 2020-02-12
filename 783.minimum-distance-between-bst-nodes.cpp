/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
  int ans;
  TreeNode* pre;
public:
  void solve(TreeNode* node) {
    if (node == NULL) return;
    solve(node->left);
    if (pre) {
      int tmp = node->val - pre->val;
      ans = min(ans, tmp);
    }
    pre = node;
    solve(node->right);
  }

  int minDiffInBST(TreeNode* root) {
    ans = INT_MAX;
    if (root == NULL) return 0;
    pre = NULL;
    solve(root);
    return ans;
  }
};
