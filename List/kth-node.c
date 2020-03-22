/**
 * struct ListNode {
 *   int val;
 *   struct ListNode *next;
 * };
 */

int kthToLast(struct ListNode* head, int k) {
  struct ListNode *fast = head, *slow = head;
  while (k--) {
    fast = fast->next;
  }
  while (fast) {
    fast = fast->next;
    slow = slow->next;
  }
  return slow->val;
}
