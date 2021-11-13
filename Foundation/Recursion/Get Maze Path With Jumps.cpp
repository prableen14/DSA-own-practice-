/*
1. You are given a number n and a number m representing number of rows and columns in a maze.
2. You are standing in the top-left corner and have to reach the bottom-right corner. 
3. In a single move you are allowed to jump 1 or more steps horizontally (as h1, h2, .. ), or 1 or more steps vertically (as v1, v2, ..) or 1 or more steps diagonally (as d1, d2, ..). 
4. Complete the body of getMazePath function - without changing signature - to get the list of all paths that can be used to move from top-left to bottom-right.
Use sample input and output to take idea about output.

Note -> The online judge can't force you to write the function recursively but that is what the spirit of question is. Write recursive and not iterative logic. The purpose of the question is to aid learning recursion and not test you.
Input Format
A number n
A number m
Output Format
Contents of the arraylist containing paths as shown in sample output
Constraints
0 <= n <= 10
0 <= m <= 10
Sample Input
2
2
Sample Output
[h1v1, v1h1, d1]

*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

//sr=source row
//sc=source column
//dr=destination row
//dc=destination column

vector<string> get_maze_paths(int sr, int sc, int dr, int dc) {
  //Write your code here
  if(sr==dr && sc==dc) 
{vector<string> bres;
    bres.push_back("");
    return bres;}
    vector<string> paths;
    
    //horizontal moves
    for(int ms=1;ms<=dc-sc; ms++){
      vector<string>  hpaths= get_maze_paths(sr,sc+ms, dr,dc);
    for(string hpath: hpaths)
    paths.push_back("h"+ ms+ hpath);
    }
    //Vertical moves
        for(int ms=1;ms<=dr-sr; ms++){
      vector<string>  vpaths= get_maze_paths(sr+ms,sc, dr,dc);
    for(string vpath: vpaths)
    paths.push_back("v"+ ms+ vpath);
    }
     for(int ms=1;ms<=dr-sr && ms<=dc-sc; ms++){
      vector<string>  dpaths= get_maze_paths(sr+ms,sc+ms, dr,dc);
    for(string dpath: dpaths)
    paths.push_back("d"+ ms+ dpath);
    }
    return paths;
}

void display(vector<string>& arr) {
  cout << "[";
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i];
    if (i < arr.size() - 1) cout << ", ";
  }

  cout << "]" << endl;
}


int main() {
  int n, m;
  cin >> n >> m;
  vector<string> ans = get_maze_paths(0, 0, n - 1, m - 1);
  display(ans);

  return 0;
}
