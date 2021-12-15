/*Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.

The steps of the insertion sort algorithm:
Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
It repeats until no input elements remain.
The following is a graphical example of the insertion sort algorithm. 
The partially sorted list (black) initially contains only the first element in the list.
One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration. 
Example 1:
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
*/
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* start=new ListNode(); //dummy node
        start->next=head;
        ListNode* prev=start;
        ListNode* curr=head;
        while(curr){
            if(curr->next!=NULL && curr->next->val<curr->val){
            //INSERTION
                while(prev->next&& prev->next->val<curr->next->val){
                    prev=prev->next;
                }
                //SWAP
                ListNode* temp=prev->next;
                prev->next=curr->next;
                curr->next=curr->next->next;
                prev->next->next=temp; //prev->next is now the node we inserted and its next should now be to temp(whichever prev->next was there in starting)
                prev=start;
            }
            else curr=curr->next;
        }
        return start->next;
    }
};
//ANOTHER APPROACH
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
            ListNode* dummy=new ListNode(INT_MIN);
    dummy->next=head;
    auto prev=dummy; //OR  ListNode* prev=dummy;
    auto current=head;//OR  ListNode* current=head;
    while(current!=NULL)
    {
        if(current->val>=prev->val)
        {
            prev=current;
            current=current->next;
            
            continue;
        }
        else
        {
            auto start=dummy;
            while(start->next->val<current->val)
            {
                start=start->next;
            }
            auto temp1=start->next;
            ListNode* temp=new ListNode(current->val);
            start->next=temp;
            temp->next=temp1;
            prev->next=current->next;
            current=current->next;
            
            
        }
    }
    return dummy->next;
    }
};
