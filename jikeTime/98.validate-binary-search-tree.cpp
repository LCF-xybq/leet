/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    vector<int> res;
public:
    void mid(TreeNode* root) {
        if (root == nullptr) return;
        mid(root->left);
        res.push_back(root->val);
        mid(root->right);
    }

    bool isValidBST(TreeNode* root) {
        mid(root);

        for (int i = 1; i < res.size(); i++)
            if (res[i] <= res[i-1]) return false;
        
        return true;
    }
};
// @lc code=end

