/*You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:
Input: prices = [7,6,4,3,1]
Output: 0

Explanation: In this case, no transactions are done and the max profit = 0.
To get the maximum profit we should buy at minimum price and sell at the maximum price and buy date is before the selling date.
I decalre least value so far "lsf" which will be our buy date.
Then, intialise profit if sell today "pist", which will help us to count and store the last profit before the dip ("Decrement").
Finally intialise overall profit, which will help us to compare b/w last sell profit and today calculated profit.
Starting the loop from 0 th index to last, in that checking if the new prices is less then the last lsf. if yes, then lsf will be prices[i].
And calculate profit if sold today "pist".
Finally we will check if pist is greater then overall profit "op". Then our op will be pist as it is the max sell profit so far.
Return op;*/

class Solution {
    public int maxProfit(int[] prices) {
             int lsf = Integer.MAX_VALUE;
        int op = 0;
        int pist = 0;
        
        for(int i = 0; i < prices.length; i++){
            if(prices[i] < lsf){
                lsf = prices[i];
            }
            pist = prices[i] - lsf;
            if(pist > op){
                op = pist;
            }
        }
        return op;   
    }
}
