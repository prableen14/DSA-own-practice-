/*Generic Tree - Traversals (pre-order, Post-order)
1. You are given a partially written GenericTree class.
2. You are required to complete the body of traversals function. The function is expected to visit every node. While traversing the function must print following content in different situations.
   2.1. When the control reaches the node for the first time -> "Node Pre" node.data.
   2.2. Before the control leaves for a child node from a node -> "Edge Pre" 
   node.data--child.data.
   2.3. After the control comes back to a node from a child -> "Edge Post" node.data- 
   -child.data.
    2.4. When the control is about to leave node, after the children have been visited 
    -> "Node Post" node.data.
3. Input is managed for you.
Input Format
Input is managed for you
Output Format
As suggested in Sample Output
Constraints
None
Sample Input
12
10 20 -1 30 50 -1 60 -1 -1 40 -1 -1
Sample Output
Node Pre 10
Edge Pre 10--20
Node Pre 20
Node Post 20
Edge Post 10--20
Edge Pre 10--30
Node Pre 30
Edge Pre 30--50
Node Pre 50
Node Post 50
Edge Post 30--50
Edge Pre 30--60
Node Pre 60
Node Post 60
Edge Post 30--60
Node Post 30
Edge Post 10--30
Edge Pre 10--40
Node Pre 40
Node Post 40
Edge Post 10--40
Node Post 10
*/
