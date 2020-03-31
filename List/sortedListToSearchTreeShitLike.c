/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* solve(struct ListNode* start, struct ListNode* end) {
  struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  root->left = NULL;
  root->right = NULL;

  if (start == end) {
    root->val = start->val;
    return root;
  }

  struct ListNode* fast = start->next, *slow = start, *pre = start;
  while (fast != end && fast != end->next) {
    pre = slow;
    slow = slow->next;
    fast = fast->next->next;
  }
  if (fast == end) {
    pre = slow;
    slow = slow->next;
  }

  root->val = slow->val;
  root->left = solve(start, pre);
  if (slow != end)
    root->right = solve(slow->next, end);

  return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head){
  if (head == NULL) return NULL;
  struct ListNode* end = head;
  while (end->next) end = end->next;
  return solve(head, end);
}
