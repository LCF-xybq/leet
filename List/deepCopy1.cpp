class Solution {
public:
	Node* copy(Node *head) {
		unordered_map<Node *, Node *> mp;
		return dfs(mp, head);
	}

	Node* dfs(unordered_map<Node *, Node *> &mp, Node *node) {
		if (node == NULL)	return node;
		auto res = mp.find(node);
		if (res != mp.end()) return res->second;
		Node *newNode = new Node(node->val);
		mp[node] = newNode;
		newNode->next = dfs(node->next);
		newNode->random = dfs(node->random);
		return newNode;
	}
};
