bool isPalindrome(struct ListNode* head) {
	if (!head || !head->next) {
		return true;
	}
	
	struct ListNode *slow = head, *fast = head;
	struct ListNode *tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
	tmp->next = NULL;
	
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		head->next = tmp->next;
		tmp->next = head;
		head = slow;
	}
	// odd
	if (fast) {
		slow = slow->next;
	}
	head = tmp->next;
	while (head) {
		if (head->val != slow->val) {
			return false;
		}
		head = head->next;
		slow = slow->next;
	}

	return true;
}
