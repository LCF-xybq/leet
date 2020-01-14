/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
/* used for dfs */
// private:
//     int max = 1, lev = 1;
public:
    int maxDepth(TreeNode* root) {
        /* BFS */
        if (root == nullptr) return 0;
        int lev = 0, cnt = 0;
        queue<TreeNode *> q;
        q.push(root);
        cnt++;
        lev++;
        TreeNode* h = nullptr;
        while (!q.empty()) {
            int temp = cnt;
            cnt = 0;
            while (temp--) {
                h = q.front();
                q.pop();
                if (h->left) { cnt++; q.push(h->left); }
                if (h->right) { cnt++; q.push(h->right); }
            }
            lev++;
        }
        lev--;
        return lev;

        /* DFS */
        // if (root == nullptr) return 0;
        // if (root->left == nullptr && root->right == nullptr) {
        //     if (lev > max) max = lev;
        // }
        // lev++;
        // maxDepth(root->left);
        // maxDepth(root->right);
        // lev--;

        // return max;
    }
};
// @lc code=end

