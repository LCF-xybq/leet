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
  int solve(TreeNode* node) {
    if (node == NULL) return 0;
    int left = solve(node->left);
    int right = solve(node->right);
    int ansLeft = 0, ansRight = 0;
    if (node->left && node->left->val == node->val) {
      ansLeft = left + 1;
    }
    if (node->right && node->right->val == node->val) {
      ansRight = right + 1;
    }
    ans = max(ans, ansLeft + ansRight);
    return max(ansLeft, ansRight);
  }

  int longestUnivaluePath(TreeNode* root) {
    ans = 0;
    solve(root);
    return ans;
  }
};
