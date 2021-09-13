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
    public ListNode reverseKGroup(ListNode head, int k) {
       if(head == null || head.next ==null || k==1)
       return head;
    
    ListNode temp_head = head;
    int count = 1;
    while(temp_head != null && count < k)
    {
       temp_head = temp_head.next;
       count++; 
    }
    
    if(temp_head == null && count <= k)
        return head;
    
    ListNode tail = reverseKGroup(temp_head.next,k);
    
    while(head != temp_head)
    {
        ListNode next = head.next;
        head.next = tail;
        tail = head;
        head = next;
    }
    
    temp_head.next = tail;
    
    return temp_head; 
    }
}
