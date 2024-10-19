/*
 * @Author: Vanish
 * @Date: 2024-09-18 20:56:43
 * @LastEditTime: 2024-09-18 21:01:29
 * Also View: http://vanishing.cc
 * Copyright@ https://creativecommons.org/licenses/by/4.0/deed.zh-hans
 */
/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* pre=dummy;
        while(pre->next!=nullptr && pre->next->next!=nullptr){
            ListNode* p1=pre->next;
            ListNode* p2=pre->next->next;
            pre->next=p2;
            p1->next=p2->next;
            p2->next=p1;
            pre=p1;
        }
        return dummy->next;
    }
};
// @lc code=end

