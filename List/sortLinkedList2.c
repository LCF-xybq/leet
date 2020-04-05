struct ListNode* sortList(struct ListNode* head) {
	struct ListNode* p = head;
	int len = 0, intv = 1;
	while (p) {
		len++;
		p = p->next;
	}
	struct ListNode* res = (struct ListNode*)malloc(sizeof(struct ListNode));
	res->next = head;
	while (intv < len) {
		struct ListNode* pre = res;
		struct ListNode* h = res->next;
		//get h1 and h2
		while (h != NULL) {
			int i = intv;
			struct ListNode* h1 = h;
			for (; h != NULL && i > 0; --i) {
				h = h->next;
			}
			// i > 0 --> h2 is null
			if (i > 0) {
				break;
			}
			struct ListNode* h2 = h;
			i = intv;
			for (; h != NULL && i > 0; --i) {
				h = h->next;
			}
			// get length of h1 and h2
			int c1 = intv;
			int c2 = intv - i;
			// merge
			while (c1 > 0 && c2 > 0) {
				if (h1->val < h2->val) {
					pre->next = h1;
					h1 = h1->next;
					c1--;
				} else {
					pre->next = h2;
					h2 = h2->next;
					c2--;
				}
				pre = pre->next;
			}
			pre->next = c1 > 0 ? h1 : h2;
			while (c1 > 0 || c2 > 0) {
				pre = pre->next;
				c1--;
				c2--;
			}
			pre->next = h;
		}
		intv *= 2;
	}
	return res->next;
}
