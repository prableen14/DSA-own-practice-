/*
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
The first node is considered odd, and the second node is even, and so on.
Note that the relative order inside both the even and odd groups should remain as it was in the input.
You must solve the problem in O(1) extra space complexity and O(n) time complexity.

Example 1:
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

Example 2:
Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
 

Constraints:
n == number of nodes in the linked list
0 <= n <= 104
-106 <= Node.val <= 106
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* dummyEven= new ListNode(-1);
        ListNode* dummyOdd= new ListNode(-1);
         ListNode* evenTail= dummyEven;
        ListNode* oddTail= dummyOdd;
        ListNode* curr=head;
        while(curr!=NULL){
           if (curr->val%2!=0){
               oddTail->next=curr;
               oddTail=oddTail->next;
           }
            else{
                evenTail->next=curr;
                evenTail=evenTail->next;
            }
            curr=curr->next;
        }
        oddTail->next=dummyEven->next;
        evenTail->next=NULL;
        return dummyOdd->next;
    }
};
