/*BRUTE FORCE
In this approach, we will visit all the nodes in pre-order fashion( we can visit nodes in post-order or in-order fashion too) of the BST and 
find the absolute difference between target ‘K’ and node value. At last, we will return the maximum absolute difference. */
#include <math.h>

void helper(BinaryTreeNode<int>* node, int k, int &minDiff, int &closest){

    if (node == NULL){
        return;
    }

    // To store the current difference.
    int currDiff = abs(node -> data - k);

    if (currDiff < minDiff){

        minDiff = currDiff;
        closest = node -> data;
    }

    else if (currDiff == minDiff){

        closest = min(closest, node -> data);
    }

    // Recursively visiting left and right sub-trees.
    helper(node -> left, k, minDiff, closest);
    helper(node -> right, k, minDiff, closest);
}


int findClosestElement(BinaryTreeNode<int>* node, int k){

    int minDiff = INT_MAX, closest;

    helper(node, k, minDiff, closest);

    return closest;
}
/* Using BST property
In this approach, we will take the benefit of properties of BST.
If the target value ‘K’ is present in the given BST, its node value will be CLOSEST to ‘K’.
If the current node value is greater than ‘K,’ then we will move to the left node.
If the current node value is less than ‘K,’ then we will move to the right node.
*/
/*

    Time Complexity : O(H)
    Space Complexity : O(N).
    
    Where 'H' denotes the height of binary search tree
    and N denotes number of nodes in it.

*/

#include <math.h>


int helper(int val1, int val2, int k){

    if(abs(k - val1) < abs(k - val2)){

        return val1;
    }

    else if(abs(k - val1) > abs(k - val2)){

        return val2;
    }

    else{
        return min(val1, val2);
    }
}

int findClosestElement(BinaryTreeNode<int>* node, int k){

    int currClosest = node -> data;
    int closest;

    if((k < currClosest) && (node -> left != NULL)){

        // Searching for the closest node in left sub-tree.
        int leftClosest = findClosestElement(node -> left, k);

        // Finding the closest node bewteen two as answer.
        closest = helper(leftClosest, currClosest, k);
    }

    else if((k > currClosest) && (node -> right != NULL)){

        // Searching for the closest node in right sub-tree.
        int rightClosest = findClosestElement(node -> right, k);

        // Finding the closest node bewteen two as answer.
        closest = helper(rightClosest, currClosest, k);
    }

    else{

        closest = currClosest;
    }

    return closest;
}
