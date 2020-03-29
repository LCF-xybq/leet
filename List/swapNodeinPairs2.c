struct ListNode* swapPairs(struct ListNode* head) {
  // end condition
  if (head == NULL || head->next == NULL) {
    return head;
  }

  // Nodes to swap
  struct ListNode* first = head;
  struct ListNode* second = head->next;

  // swap
  first->next = swapPairs(second->next);
  second->next = first;

  return second;
}
