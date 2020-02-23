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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int L1, int R1, int L2, int R2) {
        if (L1 > R1 || L2 > R2) return NULL;
        if (L1 == R1 || L2 == R2) return new TreeNode(preorder[L1]);
        TreeNode* node = new TreeNode(preorder[L1]);
        int i = L2;
        while(i <= R2 && inorder[i] != preorder[L1]) i++;
        int len = i - L2;
        TreeNode* left = build(preorder, inorder, L1 + 1, L1 + len, L2, i - 1);
        TreeNode* right = build(preorder, inorder, L1 + len + 1, R1, i + 1, R2);
        node->left = left;
        node->right = right;
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return NULL;
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
