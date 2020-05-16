class Solution {
public:
	ListNode* reverse(ListNode* head) {
		if (head == NULL) return NULL;
		ListNode* cur = head, *pre = NULL;
		while (cur) {
			ListNode* tmp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = tmp;
		}
		return pre;
	}

	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* p = head;
		ListNode* newHead = head;
		int len = 0;

		// get length of list
		while (p) {
			len++;
			p = p->next;
		}

		// recuision and ending condition
		if (len < k) {
			return head;
		} else if (len == k) {
			return reverse(head);
		} else {
			int length = k - 1; // split list
			p = head;
			while (length--) p = p->next;
			ListNode* Next = p->next;
			p->next = NULL;
			// recursion
			newHead = reverse(head);
			head->next = reverseKGroup(Next, k);
		}
		return newHead;
	}
};
