struct ListNode* mergeTwo(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *head = (struct ListNode*) malloc(sizeof(struct ListNode));
	struct ListNode *pre = head;
	while (l1 && l2) {
		if (l1->val < l2->val) {
			pre->next = l1;
			l1 = l1->next;
		} else {
			pre->next = l2;
			l2 = l2->next;
		}
		pre = pre->next;
	}
	pre->next = (l1 == NULL) ? l2 : l1;
	return head->next;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
	if (listsSize == 0) return NULL;
	struct ListNode *p = lists[0];
	for (int i = 1; i < listsSize; ++i) {
		if (i == 1)
			p = mergeTwo(lists[i-1], lists[i]);
		else
			p = mergeTwo(p, lists[i]);
	}
	return p;
}
