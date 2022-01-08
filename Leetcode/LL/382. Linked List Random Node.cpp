/*
Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.
Implement the Solution class:
Solution(ListNode head) Initializes the object with the integer array nums.
int getRandom() Chooses a node randomly from the list and returns its value. All the nodes of the list should be equally likely to be choosen.

Example 1:
Input
["Solution", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom"]
[[[1, 2, 3]], [], [], [], [], []]
Output
[null, 1, 3, 2, 2, 3]
Explanation
Solution solution = new Solution([1, 2, 3]);
solution.getRandom(); // return 1
solution.getRandom(); // return 3
solution.getRandom(); // return 2
solution.getRandom(); // return 2
solution.getRandom(); // return 3
// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
 
Constraints:
The number of nodes in the linked list will be in the range [1, 104].
-104 <= Node.val <= 104
At most 104 calls will be made to getRandom.
*/
class Solution {
    int len=0;
    ListNode* headNode;
public: 
    Solution(ListNode* head) {
        headNode=head;
        ListNode*temp=headNode;
        while(temp){
            len++;        //first calculating length of linked list
            temp=temp->next;
        }
    }
    int getRandom() {
       int rand_index= rand()%len;    //finding random index(using modulus we brought random value in range of linked list size)
        ListNode* temp=headNode;
        for(int i=0;i<rand_index;i++){  //traversing till that generated random index and then returning its value
            temp=temp->next;
        }
        return temp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
