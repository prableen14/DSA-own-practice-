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

//ANOTHER APPROACH (pepcoding)
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
     ListNode* mergeKLists(vector<ListNode*>& lists, int si, int ei) {
         if(si>ei) return NULL;
         if(si==ei) return lists[si];
         int mid=(si+ei)/2;
         ListNode* l1= mergeKLists(lists,si,mid);
           ListNode* l2= mergeKLists(lists,mid+1,ei);
         return mergeTwoLists(l1,l2);
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        return mergeKLists(lists,0,lists.size()-1);
    }
};
