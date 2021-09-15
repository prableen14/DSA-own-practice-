/* Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:

Input: head = []
Output: []
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        
        ListNode* PREV=NULL, *NEXT;
        while(head->next){
            NEXT = head->next;
            head->next = PREV;
            PREV = head;
            head = NEXT;
        }
        head->next = PREV;
        return head;
    }
};
