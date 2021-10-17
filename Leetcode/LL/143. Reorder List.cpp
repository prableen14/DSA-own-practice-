/*
143. Reorder List / Fold of Linked List (Pepcoding)
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

Example 1:
Input: head = [1,2,3,4]
Output: [1,4,2,3]

Example 2:
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]

Constraints:

The number of nodes in the list is in the range [1, 5 * 104].
1 <= Node.val <= 1000
*/

class Solution {
public:
    ListNode* midNode(ListNode* head){
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
            forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL) return ;
        ListNode* mid= midNode(head);
        ListNode* nhead= mid->next;
        mid->next=NULL;
        nhead= reverse(nhead);
        
       ListNode* c1=head;
         ListNode* c2=nhead;
         ListNode* f1=NULL;
         ListNode* f2=NULL;
        while(c2!=NULL){
          
          //backup
            f1=c1->next;
            f2=c2->next;
          
            //links
            c1->next=c2;
            c2->next=f1;
          
            //Move
            c1=f1;
            c2=f2;
            
        }
        
    }
};
