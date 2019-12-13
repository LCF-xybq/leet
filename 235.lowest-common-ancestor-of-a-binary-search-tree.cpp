/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start
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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {      
        int a = root->val;
        int pv = p->val;
        int qv = p->val;

        if (pv > a && qv > a)
            return lowestCommonAncestor(root->right, p, q);
        else if (pv < a && qv < a)
            return lowestCommonAncestor(root->left, p, q);
        else
            return root;
    }
};
// @lc code=end

