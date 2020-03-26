class Solution {
public:
	if (head == NULL) return head;
	unorderer_map<Node *, Node *> mp;
	Node *dummyHead = new Node(0);
	Node *p = head, *cur = dummyHead;
	
	while (p) {
		cur->next = new Node(p->val);
		mp[p]= cur->next;
		p = p->next;
		cur = cur->next;
	}
	cur = dummyHead->next;
	while (head) {
		if (head->random) {
			cur->random = mp[head->random];
		}
		cur = cur->next;
		head = head->next;
	}
	return dummyHead->next;
};
