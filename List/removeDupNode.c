// values range from 0 to 20000

struct ListNode* removeDuplicateNodes(struct ListNode* head) {
	int hlist[20001] = {0};
	struct ListNode fake_head;
	fake_head.next = head;
	struct ListNode* s = &fake_head, *p = head;
	
	while (p) {
		if (hlist[p->val] == 1) {
			s->next = p->next;
		} else {
			s->next = s->next;
			hlist[p->val] = 1;
		}
		p = p->next;
	}
	return head;
}
