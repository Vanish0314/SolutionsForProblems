/*
 * @Author: Vanish
 * @Date: 2024-09-22 16:26:20
 * @LastEditTime: 2024-09-22 16:35:39
 * Also View: http://vanishing.cc
 * Copyright@ https://creativecommons.org/licenses/by/4.0/deed.zh-hans
 */
/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
class Solution {
public:
    ListNode* FindMiddle(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
            return nullptr;

        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* MergeSort(ListNode *head, ListNode *tail)
    {
        if(head == nullptr || head->next == nullptr)
            return head;

        ListNode *middle = FindMiddle(head);

        if(middle != nullptr)
        {
            MergeSort(head, middle);
            MergeSort(middle->next, tail);
        }

        ListNode *left = head;
        ListNode *right = middle->next;
        ListNode *dummy = new ListNode(0);
        ListNode *temp = dummy;

        while(left != middle && right != tail)
        {
            if(left->val < right->val)
            {
                temp->next = left;
                left = left->next;
            }
            else
            {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }
        if(left != middle)
            temp->next = left;
        else
            temp->next = right;

        return dummy->next;
    }

    ListNode* sortList(ListNode *head) 
    {
        return MergeSort(head, nullptr);
    }
};
// @lc code=end

