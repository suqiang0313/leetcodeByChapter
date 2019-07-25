"""
Describe: You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

Url: https://leetcode.com/problems/add-two-numbers/

"""


//Solution : we should calculate like we sum two numbers in a piece of paper.

// not use new ,if we can not delete it .
// use carray 

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode dummy = ListNode (0);
    	ListNode* head = &dummy;
    	ListNode* tail = &dummy;
    	int val = 0;
    	int carry = 0;
    	while(l1||l2) {
    		int val1 = 0;
    		if(l1) {
    			val1 = l1->val;
    			l1 = l1->next;
    		}
    		int val2 = 0;
    		if(l2) {
    			val2 = l2->val;
    			l2 = l2->next;

    		}
    		val = val1 + val2 + carry;
    		carry = val/10;
    		val = val%10;
    		tail->next = new ListNode(val);
            tail = tail ->next;
    	}
    	if(carry ==1) {
    		tail->next = new ListNode(1);
    	}
    	return head->next;
        
    }
};