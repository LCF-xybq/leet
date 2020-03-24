/**
 * Definition for singly-linked list.
 * struct ListNode {
 *   int val;
 *   struct ListNode *next;
 * };
 *
 * [1, 2, 3, 3, 2, 1] -> [1, 2, 3]
 *
 */


struct ListNode* removeDuplicateNodes(struct ListNode* head){
	if (head == NULL || head->next == NULL) {
		return head;
	}

	struct ListNode *cur = head, *p, *pre;
	while (cur) {
		int val = cur->val;
		p = cur->next;
		pre = cur;
		while (p) {
			if (val == p->val) {
				pre->next = p->next;
				p = pre->next;
			} else {
				pre = p;
				p = p->next;
			}
		}
		cur = cur->next;
	}

	return head;
}
