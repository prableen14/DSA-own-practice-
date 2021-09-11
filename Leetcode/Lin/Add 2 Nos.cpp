/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // initialising carry as no 2 digit number to be entered
    int carry = 0;
    
    // linked list that will be our answer
    ListNode* head = new ListNode();
    ListNode* temp = head; // to traverse
    
    // will run while both of the linked lists are not traversed
    while (l1 != NULL and l2 != NULL)
    {
        // extract number from both lists input
        int number = l1->val + l2->val;
        
        // add this number into our new list
        temp->next = new ListNode ((number + carry) % 10); //only req last digit
        
        if (number + carry >= 10) // check if num was 2 digited
        {
            carry = 1; // if 2 digit
        }
        else
        {
            carry = 0; // if 1 digit
        }
        
        // move all pointers to next locations
        l1 = l1->next;
        l2 = l2->next;
        temp = temp->next;
    }

    // in case l1 is longer than l2
    while (l1 != NULL)
    {
        int number = l1->val;
        temp->next = new ListNode ((number + carry) % 10);
        if (number + carry >= 10)
        {
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        l1 = l1->next;
        temp = temp->next;
    }
    
    // in case l2 is longer than l1
    while (l2 != NULL)
    {
        int number = l2->val;
        temp->next = new ListNode ((number + carry) % 10);
        if (number + carry >= 10)
        {
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        l2 = l2->next;
        temp = temp->next;
    }
    
    // in case carry is still req (both arrays over but last num was 2 digited)
    if (carry != 0)
    {
        temp->next = new ListNode (1);
    }
    
    // 1st node was empty, return from the next one
    return head->next;

        
    }
};
