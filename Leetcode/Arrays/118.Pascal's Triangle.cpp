/* Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:
Input: numRows = 1
Output: [[1]]
 
Constraints:
1 <= numRows <= 30
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==1){
            return {{1}};
        }
        vector<vector<int>>vec={{1},{1,1}};
        
        
        for(int i=2;i<numRows;i++){
            vector<int>temp(i+1,-1);
             temp[0]=vec[i-1][0];
             temp[i]=vec[i-1][i-1];
            for(int j=1;j<i;j++){
               temp[j]=vec[i-1][j-1]+vec[i-1][j];
            }
            vec.push_back(temp);
        }
        return vec;
    }
};
