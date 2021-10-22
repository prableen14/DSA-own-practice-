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
        ListNode* middleNode(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *fast= head;
        ListNode *slow = head;
        
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
     ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* forw=NULL;
        while(curr!=NULL){
            forw=curr->next;  //backup
            curr->next=prev;   //links attach
            prev=curr;        //move foward
            curr=forw;        //move foward
        }
        return prev;     //will be at new head
    }
    
    bool isPalindrome(ListNode* head) {
          if(head==NULL || head->next==NULL) return true;
        ListNode* mid= middleNode(head);
        ListNode* nHead= mid->next;
        mid->next=NULL;
        nHead= reverse(nHead);
        ListNode* c1= head;
        ListNode* c2= nHead;
        
        bool res=true;
        while(c2!=NULL){
            if(c1->val!= c2->val){
                res= false;
                 break;
            }
            c1=c1->next;
            c2=c2->next;
        }
        nHead= reverse(nHead);
        mid->next= nHead;
        return res;
    }
};
