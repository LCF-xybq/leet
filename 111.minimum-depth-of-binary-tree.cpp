/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int lev = 0, cnt = 0;
        queue<TreeNode *> q;
        q.push(root);
        cnt++;
        lev++;
        TreeNode* h = nullptr;
        bool flag = false;
        while (!q.empty()) {
            int temp = cnt;
            cnt = 0;
            while (temp--) {
                h = q.front();
                q.pop();
                if (h->left == nullptr && h->right == nullptr) { flag = true; break; }
                if (h->left) { cnt++; q.push(h->left); }
                if (h->right) { cnt++; q.push(h->right); }
            }
            if (flag) break;
            lev++;         
        }
        
        return lev;
    }
};
// @lc code=end

