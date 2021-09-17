/*
1. Assume you have an array of length 'n' initialized with all 0's and are given 'q' queries to update.
2. Each query is represented as a triplet: [startIndex, endIndex, inc] which increments each element of
subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.
3. Return the modified array after all 'q' queries were executed.

Input Format
length = 5,
 updates = 
 {
     {1,  3,  2},
     {2,  4,  3},
     {0,  2, -2}
 }

 Output Format
 return {-2, 0, 3, 5, 3}

Explanation : 
 Initial state:
 { 0, 0, 0, 0, 0 }
 After applying operation [1, 3, 2]:
 { 0, 2, 2, 2, 0 }
 After applying operation [2, 4, 3]:
 { 0, 2, 5, 5, 3 }
After applying operation [0, 2, -2]:
{-2, 0, 3, 5, 3 }

Sample Input
12
4
2 6 4
0 5 3
1 4 -2
6 9 1
Sample Output
3 1 5 5 5 7 5 1 1 1 0 0 

STEP1: Impact on starting index as well as ending index+1
Starting: +val
Ending: -val
STEP2: Prefix sum array

TC
Brute or Naive Approach = O(nq)
Optimised= O(n)
*/
public class RangeAdditions {
    public static int[] getModifiedArray(int length, int[][] queries) {
        // write your code here
        int[]arr=new int[length];
        
        for(int[] query : queries){
            int startIdx= query[0];
            int endIdx= query[1];
            int changeInVal= query[2];
            
            arr[startIdx]+=changeInVal;
            if(endIdx+1<arr.length)
                arr[endIdx+1]-=changeInVal;
        }
        
        prefixSum(arr);
        return arr;
        
    }
    
    public static void prefixSum(int[]arr){
        for(int i=1;i<arr.length;i++)
            arr[i]+=arr[i-1];
    }

}
