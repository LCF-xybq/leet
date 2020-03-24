/**
 * struct ListNode {
 *   int val;
 *   struct ListNode *next;
 * };
 */

struct ListNode *reverseList(struct ListNode* head) {
/*
	if (head == NULL || head->next == NULL) {
		return head;
	}

	struct ListNode *pre = NULL;
	while (head) {
		struct ListNode *tmp = head->next;
		head->next = pre;
		pre = head;
		head = tmp
	}

	return pre;
*/
	
	// extrance
	if (head == NULL || head->next == NULL) {
		return head;
	}

	// recursion
	struct ListNode *res = reverseList(head->next);

	// operation
	head->next->next = head;
	head->next = NULL;

	// return
	return res;
}
