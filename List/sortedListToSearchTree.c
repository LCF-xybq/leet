/**
 * Definition for singly-linked list.
 * struct ListNode {
 *   int val;
 *   struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 *   struct TreeNode *left;
 *   struct TreeNode *right;
 * };
 */

struct TreeNode* solve(struct ListNode* start, struct ListNode* end) {
  if (start == NULL) {
    return NULL;
  }

  struct ListNode* fast = start, *slow = start;
  while (fast != end && fast->next != end) {
    slow = slow->next;
    fast = fast->next->next;
  }

  struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  root->val = slow->val;
  root->left = solve(start, slow);
  root->right = solve(slow->next, end);

  return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
  return solve(head, NULL);
}
