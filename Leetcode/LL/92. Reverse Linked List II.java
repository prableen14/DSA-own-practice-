/* 
Given the head of a singly linked list and two integers left and right where left <= right,
reverse the nodes of the list from position left to position right, and return the reversed list.
Example 1:
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Example 2:
Input: head = [5], left = 1, right = 1
Output: [5]*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseBetween(ListNode head, int left, int right) {
            if(head==null || head.next==null){
      return head;
    }

    ListNode dummy = new ListNode(-1);
    dummy.next = head;
    // till the left index
    ListNode it = dummy;
    ListNode prevIt = null;
    for(int i=0;i<left;i++){
      prevIt = it;
      it = it.next;
    }

    //reverse
    ListNode itR = it;
    ListNode prevR = prevIt;

    // reversing a linked list
    for(int i=left;i<=right;i++){
      ListNode forward = itR.next;
      itR.next = prevR;
      prevR = itR;
      itR = forward;
    }

    //connect
    prevIt.next = prevR;
    it.next = itR;

    return dummy.next;

    }
}
