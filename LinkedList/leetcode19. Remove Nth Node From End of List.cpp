"""
description：
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
url :https://leetcode.com/problems/remove-nth-node-from-end-of-list/
hint:  two pointer , first pointer is faster than second pointer ,their distance is n+1;
only n+1 , when first is null , second is the last n+1;
"""

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode * slow = &dummy ;
        ListNode * fast = &dummy ;
        for(int i =0;i<n+1;i++) 
        {
            fast = fast -> next;
        }
        while(fast) 
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;

        return dummy.next ;
        
    }
};