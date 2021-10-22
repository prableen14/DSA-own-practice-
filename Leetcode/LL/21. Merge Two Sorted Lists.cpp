/* Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.

Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: l1 = [], l2 = []
Output: []
Example 3:

Input: l1 = [], l2 = [0]
Output: [0]

 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL || l2==NULL) return l1!=NULL ? l1 : l2;
        
        ListNode* c1=l1;
        ListNode* c2=l2;
        ListNode* dummy= new ListNode(-1);
        ListNode* prev=dummy;
        
        while(c1!=NULL && c2!=NULL){
            if(c1->val < c2->val){
                prev->next=c1;
                c1=c1->next;
            }
            else {prev->next=c2;
            c2=c2->next;}
            prev=prev->next;
        }
        prev->next= c1!=NULL ?c1 : c2;
        return dummy->next;
    }
};
