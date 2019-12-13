/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
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
/*
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        set<ListNode *> s;
        s.insert(head);
        ListNode *p = head->next;
        while (p) {
            if (s.count(p)) return true;
            else
            {
                s.insert(p);
                p = p->next;
            }
        }
        return false;
    }
*/
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return false;
        ListNode *s = head;
        ListNode *q = head->next->next;
        while (q) {
            if (q == s) return true;
            s = s->next;
            if (q->next == nullptr) break;
            q = q->next->next;
        }
        return false;
    }
};
// @lc code=end

