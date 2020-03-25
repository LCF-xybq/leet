struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
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

	pre->next = l1 == NULL ? l2 : l1;

	return head->next;
}

// recursion

/**
 * list1[0] + merge(list1[1], list2)  list1[0] < list2[0]
 * list2[0] + merge(list1, list2[1])
 */
struct ListNode* mergeLists(struct ListNode* l1, struct ListNode* l2) {
	if (l1 == NULL) {
		return l2;
	} else if (l2 == NULL) {
		return l1;
	} else if (l1->val < l2->val) {
		l1->next = mergeLists(l1->next, l2);
		return l1;
	} else {
		l2->next = mergeLists(l1, l2->next);
		return l2;
	}
}
