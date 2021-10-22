/*

Given a singly linkedlist : l0 -> ln -> l1 -> ln-1 -> l2 -> ln-2 -> l3 -> ln-3 -> ..... 
reorder it :  l0 -> l1 -> l2 -> l3 -> l4 -> l5 -> l6 ..... -> ln-1 -> ln

Input Format
1->7->2->6->3->5->4->null
Output Format
1->2->3->4->5->6->7->null

 Constraints
0 <= N <= 10^6

*/
#include <iostream>
using namespace std;

class ListNode
{
public:
    int val = 0;
    ListNode *next = nullptr;

    ListNode(int val)
    {
        this->val = val;
    }
};
ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* forw=NULL;
        while(curr!=NULL){
            forw=curr->next;  //backup
            curr->next=prev;   //links attach
            prev=curr;        //move foward
            curr=forw;        //move foward
        }
        return prev;     //will be at new head
    }
void unfold(ListNode *head)
{
    if(head==NULL || head->next==NULL) return;
    ListNode* fh= head;  //first head
    ListNode* fp=fh;   //first previous
    ListNode* sh= head->next;  //second head
    ListNode* sp=sh;  //second previous
    
    while(sp!=NULL && sp->next!=NULL){
        //backup
        ListNode* forw=sp->next;
        
        //Links
        fp->next=forw;
        sp->next=forw->next;
        
        //move
        fp=fp->next;
        sp=sp->next;
    }
    fp->next=NULL;
    sh=reverse(sh);
    fp->next=sh;
}

void printList(ListNode *node)
{
    ListNode *curr = node;
    while (curr != nullptr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    while (n-- > 0)
    {
        int val;
        cin >> val;
        prev->next = new ListNode(val);
        prev = prev->next;
    }

    ListNode *head = dummy->next;
    unfold(head);
    printList(head);

    return 0;
}
