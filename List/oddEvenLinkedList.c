struct ListNode* oddEvenList(struct ListNode* head) {
	if (head == NULL || head->next == NULL) return head;
	struct ListNode* odd = head, *even = head->next;
	struct ListNode* tmp = even;
	while (even && even->next) {
		odd->next = even->next;
		odd = odd->next;
		even->next = even->next->next;
		even = even->next;
	}
	odd->next = tmp;
	return head;
}
