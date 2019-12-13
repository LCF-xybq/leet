/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *cur = dummyHead;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            ListNode *node1 = cur->next;
            ListNode *node2 = cur->next->next;
            ListNode *rear = node2->next;
            cur->next = node2;
            node2->next = node1;
            node1->next = rear;
            cur = node1;
        }

        return dummyHead->next;       
    }
};
// @lc code=end

