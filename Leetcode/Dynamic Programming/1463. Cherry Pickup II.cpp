/*
You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.
You have two robots that can collect cherries for you:
Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of cherries collection using both robots by following the rules below:
From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.
 
Example 1:
Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
Output: 24
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12.
Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.
Total of cherries: 12 + 12 = 24.

Example 2:
Input: grid = [[1,0,0,0,0,0,1],[2,0,0,0,0,3,0],[2,0,9,0,0,0,0],[0,3,0,5,4,0,0],[1,0,2,3,0,0,6]]
Output: 28
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (1 + 9 + 5 + 2) = 17.
Cherries taken by Robot #2, (1 + 3 + 4 + 3) = 11.
Total of cherries: 17 + 11 = 28.

Constraints:
rows == grid.length
cols == grid[i].length
2 <= rows, cols <= 70
0 <= grid[i][j] <= 100
*/
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(col, -1)));
        dfs(0,0,col-1,dp,grid);
        return dp[0][0][col-1];
        
    }
    int dfs(int r,int c1,int c2, vector<vector<vector<int>>> &dp,vector<vector<int>>& grid)
    {
        if(r>=grid.size() || c1<0 || c1>=grid[0].size() || c2<0 || c2>=grid[0].size() )
            return 0;
        
        if(dp[r][c1][c2]!=-1)  // if already calculated
            return dp[r][c1][c2];
        
        int result=0;
        if(r<grid.size())
        {
        // c1 and c2 are the current possition
        // if c1=c2 then we can count only the grid once , otherwise count the robots r1 r2 points at c1 and c2
            result+=grid[r][c1];
            if(c1!=c2) 
                result+=grid[r][c2];
            
            int maximumAns=0;
            for(int i=c1-1;i<=c1+1;i++) //for c1-1, c1, c1+1
            {
                for(int j=c2-1;j<=c2+1;j++) //for c2-1, c2, c2+1
                {
                    maximumAns=max(maximumAns,dfs(r+1,i,j,dp,grid)); // out of 9 possible get the max value combination 
                }
            }
            result+=maximumAns;
            dp[r][c1][c2]=result;
        }
        return result;
    }
};
