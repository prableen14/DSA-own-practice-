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
        vector<vector<int>> v;
        vector<int> u;
        v.push_back({1});
        for(int i = 1; i < numRows; i++) {
            u.push_back(1);
            for(int j  = 1; j < i; j++) {
                u.push_back(v[i-1][j]+v[i-1][j-1]);
            }
            u.push_back(1);
            v.push_back(u);
            u.clear();
        }
        return v;}
};

//Java Solution to understand more functionality of ArrayList
class Solution {
    public List<List<Integer>> generate(int numRows) {
        if(numRows==0) return new ArrayList();
 List<List<Integer>> result = new ArrayList();
        for(int i=1;i<=numRows;i++){
              List<Integer> row = new ArrayList();
            for(int j=0;j<i;j++){
                if(j==0 || j==i-1){
                    row.add(1);
                }else{
                    row.add(result.get(i-2).get(j)+result.get(i-2).get(j-1));
                }
            }
              result.add(row);     
        }
        return result;
    }
    }
