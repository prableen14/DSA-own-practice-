/* 1. You are given a number n, representing the number of rows.
2. You are given a number m, representing the number of columns.
3. You are given n*m numbers, representing elements of 2d array a. The numbers can be 1 or 0 only.
4. You are standing in the top-left corner and have to reach the bottom-right corner. 
Only four moves are allowed 't' (1-step up), 'l' (1-step left), 'd' (1-step down) 'r' (1-step right). You can only move to cells which have 0 value in them. You can't move out of the boundaries or in the cells which have value 1 in them (1 means obstacle)
5. Complete the body of floodfill function - without changing signature - to print all paths that can be used to move from top-left to bottom-right.

Note1 -> Please check the sample input and output for details
Note2 -> If all four moves are available make moves in the order 't', 'l', 'd' and 'r'
Input Format
A number n
A number m
e11
e12..
e21
e22..
.. n * m number of elements
Output Format
trrrdlt
tlldrt
.. and so on

Constraints
1 <= n <= 10
1 <= m <= 10
e1, e2, .. n * m elements belongs to set (0, 1)
Sample Input
3 3
0 0 0
1 0 1
0 0 0
Sample Output
rddr
*/
#include<iostream>

#include<vector>

using namespace std;
// asf -> answer so far
void floodfill(vector<vector<int>> maze, int sr, int sc, string asf, boolean[][] visited) {
//write your code here
if(sr<0 || sc<0 || sr==maze.size() || sc==maze[0].size() || maze[sr][sc]==1 || visited[sr][sc]==true)
return;
if(sr==maze.size()-1 || sc==maze[0].size()-1){
    cout<<asf<<"\n";
    return;
}
visited[sr][sc]=true;
floodfill(maze,sr-1,sc,asf+"t", visited); //top
floodfill(maze,sr,sc-1,asf+"l", visited); //left
floodfill(maze,sr+1,sc,asf+"d", visited); //down
floodfill(maze,sr,sc+1,asf+"r", visited); //right
visited[sr][sc]=false; //to explore and print more paths, we have to mark visited as false now
}

int main() {
  int n, m;
  cin >> n >> m;
  vector < vector < int >> arr(n, vector < int > (m));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> arr[i][j];

  floodfill(arr, 0, 0, "");
}
