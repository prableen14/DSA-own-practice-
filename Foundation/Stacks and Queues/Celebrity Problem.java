/*
1. You are given a number n, representing the number of people in a party.
2. You are given n strings of n length containing 0's and 1's
3. If there is a '1' in ith row, jth spot, then person i knows about person j.
4. A celebrity is defined as somebody who knows no other person than himself but everybody else knows him.
5. If there is a celebrity print it's index otherwise print "none".

Note -> There can be only one celebrity. Think why?
                         
Input Format
Input is managed for you  
Output Format
Index of celebrity or none
Constraints
1 <= n <= 10^4
e1, e2, .. n * n elements belongs to the set (0, 1)
Sample Input
4
0000
1011
1101
1110
Sample Output
0
*/
//Without using extra space of stack
//SC: O(1)
import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        // write your code here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] arr = new int[n][n];

        for (int j = 0; j < n; j++) {
            String line = br.readLine();
            for (int k = 0; k < n; k++) {
                arr[j][k] = line.charAt(k) - '0';
            }
        }

        findCelebrity(arr);

    }
    public static void findCelebrity(int[][] arr) {
        // if a celebrity is there print it's index (not position), if there is not then
        // print "none"
        
  int celebrity = 0;
    for(int i=0;i<arr.length;i++) {
     if(arr[celebrity][i]==1)
         celebrity = i;
 }
  for(int i=0;i<arr.length;i++) {
    	    if(i!=celebrity) {
    	        if(arr[i][celebrity]==0 || arr[celebrity][i]==1) {
    	            System.out.println("none");
                    return;
                }
    	    }
 }
 System.out.println(celebrity);
    }

}
