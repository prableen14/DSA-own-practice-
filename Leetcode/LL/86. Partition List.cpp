/*
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.
Example 1:
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]

Example 2:
Input: head = [2,1], x = 2
Output: [1,2]

Solution:
1)Keep a marker to the last found smaller value.
2)Iterate the list, and keep pushing all smaller values to marker, while updating the marker.

*/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head!=NULL && head->next!=NULL)
        {
            ListNode *curr=head,*prev=NULL,*marker=NULL,*temp;
            while(curr!=NULL)
            {
                temp=curr->next;
                if(curr->val>=x)
                    prev=curr;
                else//move to marker
                {
                    if(marker==prev)//no need to shift to marker, just update prev and marker
                    {
                        marker=curr;
                        prev=curr;
                    }
                    else
                    {
                        prev->next=temp;
                        if(marker==NULL)
                        {
                            curr->next=head;
                            head=curr;
                            marker=head;
                        }
                        else
                        {
                            curr->next=marker->next;
                            marker->next=curr;
                            marker=marker->next;
                        }
                    }
                }
                curr=temp;
            }
        }
        return head;
    }
};
