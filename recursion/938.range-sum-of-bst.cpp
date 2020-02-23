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
public:
  void solve(TreeNode* node, int L, int R) {
    if (node == NULL) return;
    solve(node->left, L, R);
    if (node->val <= R && node->val >= L) ans += node->val;
    solve(node->right, L, R);
  }

  int rangeSumBST(TreeNode* root, int L, int R) {
    ans = 0;
    if (root == NULL) return 0;
    solve(root, L, R);

    return ans;
  }
};
