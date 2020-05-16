class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		stack<ListNode *> s;
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* tmp = head, *p = dummy;
		while (1) {
			int count = 0;
			ListNode* tmpHead = tmp;
			while (tmp && count < k) {
				count++;
				s.push(tmp);
				tmp = tmp->next;
			}
			if (count < k) {
				p->next = tmpHead;
				break;
			}
			while (!s.empty()) {
				p->next = s.top();
				s.pop();
				p = p->next;
				p->next = NULL;
			}
		}
		return dummy->next;
	}
};
