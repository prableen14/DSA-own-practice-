/* You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Example 2:
Input: lists = []
Output: []

Example 3:
Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length won't exceed 10^4.
*/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
              vector<int> a;
        for(int i=0;i<lists.size();i++)
        {
            ListNode* temp=lists[i];
            while(temp!=NULL)
            {
                a.push_back(temp->val); //pushing all lists elements data in array
                temp=temp->next;
            }
        }
        sort(a.begin(),a.end());
        ListNode* head=NULL;
        ListNode* temp=NULL;
        for(int i=0;i<a.size();i++)
        {
            if(head==NULL)
            {
                head=new ListNode(a[i]);
                temp=head;
            }
            else
            {
                temp->next=new ListNode(a[i]);
                temp=temp->next;                
            }
        }
        return head;
    }
};
