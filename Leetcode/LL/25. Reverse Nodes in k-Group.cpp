/* Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.
Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Example 2:
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

Example 3:
Input: head = [1,2,3,4,5], k = 1
Output: [1,2,3,4,5]

Example 4:
Input: head = [1], k = 1
Output: [1]
*/

class Solution {
public:
       ListNode* th=NULL;  //temporary head
        ListNode* tt=NULL;  //temporary tail
     void addFirstNode(ListNode* node) {
        if(th==NULL){
            th= node;
            tt= node;
        }
         else {node->next=th;
         th=node;}
          
    }
     int length(ListNode* node) {
        ListNode* curr=node;
         int len=0;
         while(curr!=NULL){
             curr=curr->next;
             len++;
         }
         return len;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* oh=NULL;  //original head;
        ListNode* ot=NULL;  //original tail;
        int len=length(head);
        ListNode* curr=head;
            
            while(len>=k){
                int tempk=k;
                while(tempk-->0){
                    ListNode* forw= curr->next;
                    curr->next=NULL;
                    addFirstNode(curr);
                    curr=forw;
                }
                if(oh==NULL){
                    oh=th;
                ot=tt;
                }
                else{
                    ot->next=th;
                    ot=tt;
                }
                th=NULL;
                tt=NULL;
                len-=k;
        }
        ot->next=curr;
        return oh;
    }
};
