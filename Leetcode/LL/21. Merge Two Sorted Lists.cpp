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
        
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* myHead;
        ListNode* current;
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if(l2->val < l1->val){
            
           myHead = temp2;
           current =  temp2; 
           temp2 = temp2->next;
            
        }else{
            myHead = temp1;
            current = temp1;
            temp1 = temp1->next;
        }
        
        while(temp1 != NULL && temp2!=NULL){
            
            if(temp2->val >= temp1->val ){
                current->next = temp1;
                current = current->next;
                temp1 = temp1->next;
                
            }else{
                
                current->next = temp2;
                current = current->next;
                temp2 = temp2->next;   
            }    
        }
        if(temp1 == NULL){
            
            while(temp2!=NULL){
                
                current->next = temp2;
                current = current->next; 
                temp2 = temp2->next;
            }
        }
        if(temp2 == NULL){
            
            while(temp1!=NULL){
                 current->next = temp1;
                 current = current->next;     
                 temp1 = temp1->next;
            }    
        }
        return myHead;
    }
};
