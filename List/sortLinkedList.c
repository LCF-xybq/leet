struct ListNode* sortList(struct ListNode* head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }
  struct ListNode* fast = head->next, *slow = head;
  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }
  struct ListNode* tmp = slow->next;
  slow->next = NULL;
  struct ListNode* left = sortList(head);
  struct ListNode* right = sortList(tmp);

  struct ListNode* h = (struct ListNode*)malloc(sizeof(struct ListNode));
  struct ListNode* res = h;
  while (left != NULL && right != NULL) {
    if (left->val < right->val) {
      h->next = left;
      left = left->next;
    } else {
      h->next = right;
      right = right->next;
    }
    h = h->next;
  }
  h->next = left != NULL ? left : right;

  return res->next;
}