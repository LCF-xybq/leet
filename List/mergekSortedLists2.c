void swap(struct ListNode** tree, int a, int b) {
	struct ListNode *tmp = tree[a];
	tree[a] = tree[b];
	tree[b] = tmp;
}

void heapify(struct ListNode** tree, int n, int i) {
	if (i >= n) {
		return ;
	}
	int c1 = 2 * i + 1;
	int c2 = 2 * i + 2;
	int min = i;
	
	if (c1 < n && tree[c1]->val < tree[min]->val) {
		min = c1;
	}
	if (c2 < n && tree[c2]->val < tree[min]->val) {
		min = c2;
	}
	if (min != i) {
		swap(tree, min, i);
		heapify(tree, n, min);
	}
}

void buildHeap(struct ListNode** tree, int n) {
	int last_node = n - 1;
	int parent = (last_node - 1) / 2;
	for (int i = parent; i >= 0; --i) {
		heapify(tree, n, i);
	}
}

struct ListNode* mergeKList(struct ListNode** lists, int listsSize) {
	if (listsSize == 0 || list == NULL) return NULL;
	struct ListNode** tree = (struct ListNode**) malloc(sizeof(struct ListNode*) * listsSize);

	for (int i = 0, k = 0, j = listsSize; i < j; ++i) {
		if (!list[i]) listsSize--;
		else tree[k++] = lists[i];
	}
	if (listsSize <= 0) return NULL;

	buildHeap(tree, listsSize);

	struct ListNode* head = (struct ListNode*) malloc (sizeof(struct ListNode));
	struct ListNode* pre = head, *cur;

	whlie (listsSize) {
		cur = tree[0];
		if (cur->next == NULL) {
			swap(tree, listsSize - 1, 0);
			listsSize--;
		} else tree[0] = tree[0]->next;
		pre->next = cur;
		pre = cur;
		heapify(tree, listsSize, 0);
	}
	return head->next;
}
