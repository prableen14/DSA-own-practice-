/*
1. You are give two single linkedlist of digits. 
2. The most significant digit comes first and each of their nodes contain a single digit. Subtract the two numbers and return it as a linked list.
3. You may assume the two numbers do not contain any leading zero, except the number 0 itself.
4. any list can be larger in term of number.
Input Format
1->2->3->4->5->6->7->null
7->8->9->null
Output Format
1->2->3->3->7->7->8->null
*/

#include <iostream>
using namespace std;

class ListNode
{
public:
  int val = 0;
  ListNode* next = nullptr;

  ListNode(int val)
  {
    this->val = val;
  }
};

ListNode* midNode(ListNode* head)
{
  if (head == nullptr || head->next == nullptr)
    return head;

  ListNode* slow = head;
  ListNode* fast = head;
  while (fast->next != nullptr && fast->next->next != nullptr)
  {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}
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
ListNode* subtractTwoNumbers(ListNode* l1, ListNode* l2)
{
 if(l2==NULL) return l1;
 if(l1==NULL) {
     l2->val= -l2->val;
     return l2;
 }
 l1= reverse(l1);
 l2=reverse(l2);
 
 ListNode* dummy= new ListNode(-1);
 ListNode* itr= dummy;
 ListNode* c1= l1;
 ListNode* c2=l2;
 int borrow=0;
 while(c1!=NULL){
     int diff= borrow+ c1->val -(c2!=NULL? c2->val : 0);
     if(diff<0){
         borrow=-1;
         diff+=10;
     }
     else borrow=0;
     
     itr->next= new ListNode(diff);
     itr=itr->next;
     c1=c1->next;
     if(c2!=NULL) c2=c2->next;
     
 }
 return reverse(dummy->next);
}

// Input_code===================================================

ListNode* makeList(int n)
{
  ListNode* dummy = new ListNode(-1);
  ListNode* prev = dummy;
  while (n-- > 0)
  {
    int val;
    cin >> val;
    prev->next = new ListNode(val);
    prev = prev->next;
  }
  return dummy->next;
}

void printList(ListNode* node)
{
  ListNode* curr = node;
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
  ListNode* head1 = makeList(n);

  int m;
  cin >> m;
  ListNode* head2 = makeList(m);

  ListNode* head = subtractTwoNumbers(head1, head2);
  printList(head);

  return 0;
}
