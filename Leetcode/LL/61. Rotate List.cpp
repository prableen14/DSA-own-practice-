/* Given the head of a linked list, rotate the list to the right by k places.
Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]
*/


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
{
return head;
}
ListNode *p=head,*q=NULL;
int count=1;
while(p->next!=NULL)
{
q=p;
p=p->next;
count++;
}
k>=count?k=k%count:k=k;
for(int i =0;i<k;i++)
{
p->next=head;
head=p;
q->next=NULL;
while(p->next!=NULL)
{
q=p;
p=p->next;
}
}
return head;
    }
};
