#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* insertionSortList(struct ListNode* head) {
	struct ListNode* res = (struct ListNode*)malloc(sizeof(struct ListNode));
	res->next = head;
	res->val = ~(unsigned int)0 / 2 + 1;
	struct ListNode* pre = res;
	struct ListNode* end = res;
	struct ListNode* cur = head;
	while (cur != NULL) {
		if (end->val < cur->val) {
			end->next = cur;
			end = cur;
			cur = cur->next;
		} else {
			struct ListNode* tmp = cur->next;
			end->next = tmp;
			while (pre->next != NULL && pre->next->val < cur->val) {
				pre = pre->next;
			}
			cur->next = pre->next;
			pre->next = cur;
			pre = res;
			cur = tmp;
		}
	}
	return res->next;
}

static void printList(struct ListNode* head) {
	struct ListNode* p = head;
	while (p) {
		printf("%d\n", p->val);
		p = p->next;
	}
}

int main() {
	struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* p1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* p2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* p3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	
	head->val = 4;
	p1->val = 2;
	p2->val = 1;
	p3->val = 3;

	head->next = p1;
	p1->next = p2;
	p2->next = p3;
	p3->next = NULL;

	printList(head);
	struct ListNode* res = insertionSortList(head);
	printf("\n");
	printList(res);
	return 0;
}
