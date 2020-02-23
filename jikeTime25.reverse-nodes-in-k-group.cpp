/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *pre = dummyHead;
        ListNode *end = dummyHead;
        while (end->next != nullptr) {
            for (int i = 0; i < k && end != nullptr; i++) end = end->next;
            if (end == nullptr) break;
            ListNode *start = pre->next;
            ListNode *next = end->next;
            end->next = nullptr;
            pre->next = reverseList(start);
            start->next = next;
            pre = start;
            end = start;
        }
        return dummyHead->next;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (cur) {
            ListNode *rear = cur->next;
            cur->next = pre;
            pre = cur;
            cur = rear;
        }
        return pre;
    }
};
// @lc code=end

