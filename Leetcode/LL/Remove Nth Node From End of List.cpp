/* Given the head of a linked list, remove the nth node from the end of the list and return its head.
Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1] */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode * p = dummy, *c = head, *temp=NULL;
        int m= n;
        while(c && m!=1){
            c=c->next;
            m--;
        }
        temp = head;
        
        //Now temp stands on node which is to be deleted
        while(c->next){
            c=c->next;
            temp=temp->next;
            p=p->next;
        }
        
        ListNode * nex = NULL;
        
        if(temp->next) nex= temp -> next;
        else nex = NULL;
        
        p->next = nex;
        return dummy->next;
    
    }
};
