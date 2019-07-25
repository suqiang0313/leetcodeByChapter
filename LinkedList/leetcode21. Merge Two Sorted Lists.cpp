//https://leetcode.com/problems/merge-two-sorted-lists/
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy = ListNode(-1);
        ListNode* ret = &dummy;
        while(l1&&l2)
        {
            if(l1->val < l2->val) 
            {
                ret->next = l1;
                l1 = l1->next;
                ret = ret->next;
            }
            else
            {
                ret->next = l2;
                l2 = l2->next;
                ret = ret->next;
            }
        }
        if(l1) 
        {
            ret->next = l1;
        }
        if(l2)
        {
            ret->next = l2;
        }
        return dummy.next;
        
        
    }
};