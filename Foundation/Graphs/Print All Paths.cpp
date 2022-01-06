/*
1. You are given a graph, a source vertex and a destination vertex.
2. You are required to find and print all paths between source and destination. Print them in lexicographical order.
    E.g. Check the following paths
             012546
             01256
             032546
             03256

    The lexicographically smaller path is printed first.
Input Format
Input has been managed for you
Output Format
Check sample output
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
0123456
012346
03456
0346
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

void printAllPaths(vector<Edge>graph[],int src, int dest,vector<bool> visited,string psf){
if (src==dest){
    cout<<psf<<endl;
    return;
}
visited[src]= true;
for(Edge edge: graph[src]){
        if(visited[edge.nbr]==false){
            printAllPaths(graph, edge.nbr,dest,visited,psf+to_string(edge.nbr));
        }
}
visited[src]= false;
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
  // write your code her
  vector<bool> visited(vtces, false);
  printAllPaths(graph,src,dest,visited,to_string(src));

}
