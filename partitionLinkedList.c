struct ListNode* partiton(struct ListNode* head, int x) {
	struct ListNode* h1 = (struct ListNode*) malloc (sizeof(struct ListNode)), *p1 = h1;
	struct ListNode* h2 = (struct ListNode*) malloc (sizeof(struct ListNode)), *p2 = h2;
	p1->next = NULL;
	p2->next = NULL;
	while (head != NULL) {
		if (head->next < x) {
			p1->next = head;
			p1 = p1->next;
		} else {
			p2->next = head;
			p2 = p2->next;
		}
		head = head->next;
	}
	p1->next = h2->next;
	p2->next = NULL
	
	return h1->next;
}
