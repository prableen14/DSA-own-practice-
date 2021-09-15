/*Given a linked list, swap every two adjacent nodes and return its head. 
You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.) */

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next=head;
         ListNode * runner = dummy;
        
        while(runner->next!=NULL && runner->next->next!=NULL){
            ListNode* r1= runner->next;
             ListNode* r2= runner->next->next;
            
            runner->next=r2;
            r1->next=r2->next;
            r2->next=r1;
            
            //Move to the next pair
            runner= runner->next->next;
            }
        return dummy->next;
        }
    
};

//JAVA SOLUTION

class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode dummy= new ListNode(0);
        dummy.next=head;
        ListNode runner = dummy;
        // Check to make sure that there is a pair at our current position
        while(runner.next!=null && runner.next.next!=null){
            //Set up two reference pointers to help with the reference swapping
            ListNode r1= runner.next;
            ListNode r2= runner.next.next;
            
            //Do the three swaps to reverse the pair
            runner.next=r2;    // this will happen after the 2 below swaps
            r1.next=r2.next;
            r2.next=r1;
            
            //Move to the next pair
            runner= runner.next.next;
        }
        return dummy.next;
    }
}
