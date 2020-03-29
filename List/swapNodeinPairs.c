struct ListNode* swapPairs(struct ListNode* head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }

  struct ListNode* p = head, *q = head->next;
  struct ListNode* pre = NULL;
  head = head->next;

  while (p && q) {
    // swap two nodes
    p->next = q->next;
    q->next = p;

    // link two pairs of node
    if (pre) {
      pre->next = q;
    }
    pre = p;

    // move to next two nodes
    p = p->next;
    if (p == NULL || p->next == NULL) {
      break;
    }
    q = p->next;
  }

  return head;
}
