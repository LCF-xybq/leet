class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node (int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};

class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (head == NULL) return head;
		queue<Node *> q;
		unordered_map<Node *, Node *> mp;
		Node *newHead = new Node(head->val);
		mp[head] = newHead;
		q.push(head);
		while (!q.empty()) {
			Node *cur = q.front();
			q.pop();
			if (cur->next != NULL) {
				auto res = mp.find(cur->next);
				if (res == mp.end()) {
					q.push(cur->next);
					mp[cur->next] = new Node(cur->next->val);
				}
				mp[cur]->next = mp[cur->next];
			}
			if (cur->random != NULL) {
				auto res = mp.find(cur->random);
				if (res == mp.end()) {
					q.push(cur->random);
					mp[cur->random] = new Node(cur->random->val);
				}
				mp[cur]->random = mp[cur->random];
			}
		}
		return newHead;
	}
};
