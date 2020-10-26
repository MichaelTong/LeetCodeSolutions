/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (37.28%)
 * Likes:    2077
 * Dislikes: 113
 * Total Accepted:    272.2K
 * Total Submissions: 726.1K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 * 
 * Return the linked list sorted as well.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2->3->3->4->4->5
 * Output: 1->2->5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 1->1->1->2->3
 * Output: 2->3
 * 
 * 
 */

#include "lc.hpp"
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(-1);
        ListNode *prev = &dummy;
        ListNode *p = head;
        prev->next = p;
        bool delink = false;
        int delink_val = -1;

        while (p != nullptr) {
            if (!delink && p->next != nullptr && p->val == p->next->val) {
                delink = true;
                delink_val = p->val;
                prev->next = p->next;
                p = p->next;
            } else if (delink) {
                if (p->val == delink_val) {
                    prev->next = p->next;
                    p = p->next;
                } else {
                    delink = false;
                    delink_val = -1;
                }
            } else {
                prev = p;
                p = p->next;
            }
        }
        return dummy.next;
    }
};
// @lc code=end

