/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *l1 = list1, *l2 = list2;
        ListNode *dummyHead = new ListNode();
        ListNode *result = new ListNode();
        dummyHead->next = result;


        while(l1 && l2)
        {
            if(l1->val < l2->val)
            { 
                result->next = l1;
                l1 = l1->next;
            }
            else
            {
                result->next = l2;
                l2 = l2->next;
            }
            result = result->next;
        }

        if(l1)
            result->next = l1;
        else
            result->next = l2;\

        return dummyHead->next->next;
    }
};
// @lc code=end

