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
        if(head==NULL || head->next==NULL) return head;
        ListNode* dummy= new ListNode(-1);
        ListNode* itr=dummy;
        itr->next= head;  //potential unique element
        ListNode* curr= head->next;
        while(curr!=NULL){
            bool isLoopRun= false;
            while(curr!=NULL && itr->next->val== curr->val){
                isLoopRun=true;
                curr=curr->next;
            }
            if (isLoopRun) itr->next=curr; //current element will be potential unique element
            else itr=itr->next;
            
            if(curr!=NULL) curr=curr->next;
        }
        return dummy->next;
    }
};
