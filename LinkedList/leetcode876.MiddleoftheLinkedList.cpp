//876. Middle of the Linked List
//https://leetcode.com/problems/middle-of-the-linked-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// solution : two pointer,slow pointer ,fast pointer ,slow pointer mover one step, 
//fast pointer move two step;
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode * slow  = head
        ListNode *fast = head;
        while(fast!=NULL and fast->next !=NULL){
            slow = slow -> next;
            fast = fast ->next->next;
        }
        return slow;
    }
};
