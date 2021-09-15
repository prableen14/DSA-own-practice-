/* Given the head of a singly linked list, return true if it is a palindrome.
Example 1:

Input: head = [1,2,2,1]
Output: true

Example 2:

Input: head = [1,2]
Output: false
*/

class Solution {
public:
    bool isPalindrome(ListNode* head) {
                ListNode *curr=head;
        ListNode* prev=NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        
        
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
             ListNode *n=curr->next;
            curr->next=prev;
            prev=curr;
            curr=n;
            
        }
        if(fast==NULL){
            ListNode* p=prev;
            
        }else{
            ListNode* p=prev;
            slow=slow->next;      
        }
        
         while(prev!=NULL){
                if(prev->val!=slow->val){
                    return false;
                }
                prev=prev->next;
                slow=slow->next;
            }
            return true;
        
    }
};
