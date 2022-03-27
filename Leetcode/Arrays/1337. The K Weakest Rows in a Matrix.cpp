/*
You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). 
The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.
A row i is weaker than a row j if one of the following is true:
The number of soldiers in row i is less than the number of soldiers in row j.
Both rows have the same number of soldiers and i < j.
Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.

Example 1:
Input: mat = 
[[1,1,0,0,0],
 [1,1,1,1,0],
 [1,0,0,0,0],
 [1,1,0,0,0],
 [1,1,1,1,1]], 
k = 3
Output: [2,0,3]
Explanation: 
The number of soldiers in each row is: 
- Row 0: 2 
- Row 1: 4 
- Row 2: 1 
- Row 3: 2 
- Row 4: 5 
The rows ordered from weakest to strongest are [2,0,3,1,4].

Example 2:
Input: mat = 
[[1,0,0,0],
 [1,1,1,1],
 [1,0,0,0],
 [1,0,0,0]], 
k = 2
Output: [0,2]
Explanation: 
The number of soldiers in each row is: 
- Row 0: 1 
- Row 1: 4 
- Row 2: 1 
- Row 3: 1 
The rows ordered from weakest to strongest are [0,2,3,1].
 
Constraints:

m == mat.length
n == mat[i].length
2 <= n, m <= 100
1 <= k <= m
matrix[i][j] is either 0 or 1.
*/

//BRUTE FORCE METHOD
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
          /*
        Steps ->
        
        1. We'll store no of soldies and rowIndex in a pair
        2. Sort the pair 
        3. then, we'll push first k elements (the second 
        of the pair) into the ans vector
        
        */
        vector<int> ans;
        vector<pair<int, int>> vect;
        
        int m = mat.size(), n = mat[0].size();
        for(int i=0; i<m; i++)
        {
            int j=0, cntSol = 0;
            while(j<n && mat[i][j++] == 1)
                cntSol++;
            
            vect.push_back({cntSol, i});
        }
        
        sort(vect.begin(), vect.end());
        
        for(int i=0; i<k; i++)
        {
            int ele = vect[i].second;
            ans.push_back(ele);
        }
        return ans;
    }
};
