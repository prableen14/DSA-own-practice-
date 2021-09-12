/* Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
Example 1:
Input: head = [1,1,2]
Output: [1,2]

Example 2:
Input: head = [1,1,2,3,3]
Output: [1,2,3] */

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
                ListNode * ptr=head;
        while(ptr!=NULL && ptr->next!=NULL)
        {
            while(ptr!=NULL && ptr->next!=NULL && ptr->val==ptr->next->val)
            {
                ptr->next=ptr->next->next;
              
                
            }
            if(ptr!=NULL)
            ptr=ptr->next;
        }
        return head;
        
    }
};
