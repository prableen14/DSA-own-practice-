/*
1. You are given a graph, a src vertex and a destination vertex.
2. You are required to find if a path exists between src and dest. If it does, print true 
     otherwise print false.
Input Format
Input has been managed for you
Output Format
true if path exists, false otherwise
Constraints
None
Sample Input
7
8
0 1 10
1 2 10
2 3 10
0 3 10
3 4 10
4 5 10
5 6 10
4 6 10
0
6
Sample Output
true
*/
#include<bits/stdc++.h>
using namespace std;
class Edge {
public:
  int src;
  int nbr;
  int wt;

  Edge(int src, int nbr, int wt) {
    this->src = src;
    this->nbr = nbr;
    this->wt = wt;
  }
};
bool hasPath(vector<Edge>graph[],int src, int dest,vector<bool> visited){
    if(src==dest) return true;
    visited[src]=true;
    for(Edge edge: graph[src]){
        if(visited[edge.nbr]==false){
            bool hasNbrPath=hasPath(graph, edge.nbr,dest,visited);
            if(hasNbrPath==true) return true;
        }
    }
    return false;
}
int main() {
  int vtces;
  cin >> vtces;
  vector<Edge>graph[vtces];

  int edges;
  cin >> edges;
  for (int i = 0; i < edges; i++) {
    int v1 ;
    int v2 ;
    int wt ;
    cin >> v1 >> v2 >> wt;
    graph[v1].push_back( Edge(v1, v2, wt));
    graph[v2].push_back( Edge(v2, v1, wt));
  }
  int src;
  cin >> src;
  int dest;
  cin >> dest;
  // write your code here
vector<bool> visited(vtces, false);
 if (hasPath(graph, src, dest, visited)) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }
}

//Another way to write the main checking statement
bool hasPath(vector<Edge>graph[], int  src, int dest, vector<bool> vis) {
  if (src == dest)return true;
  vis[src] = true;
  for (Edge ed : graph[src]) {
    if (vis[ed.nbr] == false && hasPath(graph, ed.nbr, dest, vis))
      return true;
  }
  return false;
}
