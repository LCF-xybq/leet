/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;

        int cnt = 0, lev = 0;
        queue<TreeNode *> q;
        q.push(root);
        cnt++;
        res.push_back(vector<int>());
        res[lev++].push_back(root->val);
        TreeNode* h = nullptr;
        while (!q.empty()) {            
            int temp = cnt;
            cnt = 0;
            res.push_back(vector<int>());
            while (temp--) {
                h = q.front();
                q.pop();
                if (h->left) {
                    res[lev].push_back(h->left->val);
                    q.push(h->left);
                    cnt++;    
                }

                if (h->right) {
                    res[lev].push_back(h->right->val);
                    q.push(h->right);
                    cnt++;    
                }
            }
            lev++;
        }
        res.pop_back();

        return res;
    } 
};
// @lc code=end

