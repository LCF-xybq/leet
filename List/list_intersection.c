struct ListNode* getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	struct ListNode *pa = headA, *pb = headB;
	while (pa != pb) {
		if (pa != NULL) {
			pa = pa->next;
		} else {
			pa = headB;
		}

		if (pb != NULL) {
			pb = pb->next;
		} else {
			pb = headA;
		}
	}
	return pa;
}
