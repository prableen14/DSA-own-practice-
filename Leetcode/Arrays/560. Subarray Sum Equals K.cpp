/*
Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

Example 1:
Input: nums = [1,1,1], k = 2
Output: 2

Example 2:
Input: nums = [1,2,3], k = 3
Output: 2

Constraints:
1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107
*/
//Brute Force Solution

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Brute Force Solution Time O(N^3) & Auxiliary Space O(1)
        // Time Limit Exceed(TLE) 61/89 test cases passed
        int len=nums.size(),count=0;
        // Consider all possible subarrays
        for(int i=0;i<len;i++){ 
            for(int j=i;j<len;j++){ // Consider subarray from nums[i] to nums[j]
                int sum=0;
                for(int s=i;s<=j;s++){ // Calculate sum of elements from nums[i] to nums[j]
                   sum+=nums[s]; 
        }
                if(sum==k) // Check if sum is equal to k
                    count++;
        }
        }
        return count;
    }
};
//Better Solution

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Better Solution Time O(N^2) & Auxiliary Space O(N)
        // Time Limit Exceed(TLE) 84/89 test cases passed
        int len=nums.size(), count=0;
        vector<int> ls; // prefix sum array or left sum array
                        // ls[i] will be sum of elemensts from nums[0] to nums[i]
        ls.push_back(0);
        for(int i=0;i<len;i++)
            ls.push_back(ls.back()+nums[i]); // inserting elements in ls
        for(int i=0;i<ls.size();i++){ 
            for(int j=i+1;j<ls.size();j++){ 
                   // For example: nums[]={2,8,5,-3,1,8}, k=10
                   // ls[]={2,10,15,12,13,21}, k=10
                   // nums[1]+nums[2]+nums[3]=8+5+(-3)=10. 
                   // j runs from 1 to 3. For j=i+1 & j=1, we get i=0.
                   // Therefore i=0 & j=3.
                   // ls[j=3]-ls[i=0]=12-2=10 which is equal to k.
                   if(ls[j]-ls[i]==k) 
                       count++;
            }
        }
        return count;
    }
};
// Optimal Solution Time O(N) & Auxiliary Space O(N)
            /*
            m[0] = 1

     i  |  ls  |     m      |   m[ls-k]    | count
     ---|------|------------|--------------|-------
     0  |  1   |  m[ 1] = 1 | m[ 1-  8 ]=0 |  0
     1  |  8   |  m[ 8] = 1 | m[ 8-  8 ]=1 |  1
     2  |  14  |  m[14] = 1 | m[14 - 8 ]=0 |  1
     3  |  16  |  m[16] = 1 | m[16 - 8 ]=1 |  2
     4  |  19  |  m[19] = 1 | m[19 - 8 ]=0 |  2
     5  |  22  |  m[22] = 1 | m[22 - 8 ]=1 |  3
     6  |  24  |  m[24] = 1 | m[24 - 8 ]=1 |  4
     
   nums[]=[1, 7,  6,  2,  3,  3,  2 ]     
       i = 0, 1,  2,  3,  4,  5,  6 
ls value = 1, 8, 14, 16, 19, 22, 24 
           x=ls-k       k=8	    
        <----------><---------->
		         ls=22
        <---------------------->  
                */

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ls=0; // ls is left sum variable or prefix sum variable 
                  // whose value on nums[] traversal is the sum of nums[i] and  
                  // all the elements that came before it(nums[i-1], nums[i-2]. nums[i-3],.......nums[0])
        int len=nums.size(), count=0; 
        map<int,int> m; // m is a map that maps ls value to its frequency 
                        // of occurence as m[key,value]={ls,frequency}
        m[0]=1;      // If k=0, then subarray with no elements is also a subset of nums and sum of 
		             // empty subarray elements is zero. So, number of subarrays with k(=0) sum has count 
					 // of 1 initially. If k is non zero, then ls-k=0 which means ls is equal to k. 
				     // It means that for a certain index i in nums[i], the sum 
					 // nums[0]+nums[1]+numns[2]......nums[i] is equal to k. 
					 // m[0]=1 is included in count if k=0 or ls-k=0.
        for(int i=0;i<len;i++){
            ls+=nums[i];

            // If x=ls-k=22-8=14 has been the value of ls anytime before, then it means that 
            // ls-x=22-14 is k. Count will increment by number of times of x=ls-k occurence which
            // is stored in m[ls-k]
            count+=m[ls-k];
            m[ls]++; // Store the frequency of ls value in map
        }
        return count; 
    }
};
