/*Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. 
Return the linked list sorted as well.

Example 1:
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

Example 2:
Input: head = [1,1,1,2,3]
Output: [2,3]
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
         ListNode *p = nullptr, *q = head;
        while(q)
        {
            if(q->next && q->next->val == q->val)
            {
                int dup = q->val;
                while(q && q->val == dup)
                    q = q->next;
                if(!p) 
                    head = q;
                else
                    p->next = q;
            }
            else
                p = q, q = q->next;
        }
        return head;
    
    }
};
