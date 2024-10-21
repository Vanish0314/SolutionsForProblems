/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 */

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
class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *dummyHead = new ListNode();
        ListNode *largeDummy = new ListNode();
        ListNode *small = new ListNode();
        ListNode *large = new ListNode();
        dummyHead->next = small;
        largeDummy->next = large;
        
        while (head)
        {
            if (head->val < x)
            {
                small->next = head;
                small = small->next;
            }
            else
            {
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }
        large->next = nullptr;
        small->next = largeDummy->next->next;
        return dummyHead->next->next;
    }
};
// @lc code=end
