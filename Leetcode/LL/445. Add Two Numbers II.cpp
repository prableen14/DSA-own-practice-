/*

You are given two non-empty linked lists representing two non-negative integers.
The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:

Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]

Example 2:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]

Example 3:
Input: l1 = [0], l2 = [0]
Output: [0]
 

Constraints:
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/

class Solution {
public:
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL || l2==NULL) return l1!=NULL ? l1 : l2;
         
        ListNode* c1= reverse(l1);
        ListNode* c2= reverse(l2);
        ListNode* dummy= new ListNode(-1);
        ListNode* itr= dummy;
        int carry=0;
        
        while(c1!=NULL || c2!=NULL || carry!=NULL){
            int sum= carry+ (c1!=NULL ? c1->val: 0)+(c2!=NULL ? c2->val: 0);
            
            int ld= sum%10; //last digit of sum
            carry= sum/10;
            
            itr->next= new ListNode(ld);
            itr=itr->next;
            
            if(c1!=NULL) c1=c1->next;
            if(c2!=NULL) c2=c2->next;
        }
        return reverse(dummy->next);
    }
};
