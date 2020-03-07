//206. Reverse Linked List
//https://leetcode.com/problems/reverse-linked-list/
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
    ListNode* reverseList(ListNode* head) {
        if(head ==NULL ||head->next==NULL ){
            return head;
        }
        ListNode * prev = NULL;
        ListNode * cur = head;
        ListNode * next = NULL;
        while(cur){
            ListNode * node = cur->next;
            cur->next = prev;
            prev = cur;
            cur = node;
        }
        return prev;
        
    }
};