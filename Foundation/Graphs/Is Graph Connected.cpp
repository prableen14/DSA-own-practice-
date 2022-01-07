/*
1. You are given a graph.
2. You are required to find and print if the graph is connected (there is a path from 
     every vertex to every other).
Input Format
Input has been managed for you
Output Format
true if the graph is connected, false otherwise
Constraints
None
Sample Input
7
5
0 1 10
2 3 10
4 5 10
5 6 10
4 6 10
Sample Output
false
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

void dfs(vector<Edge>graph[], int src, vector<bool>& visited) {
  visited[src] = true;

  for (Edge ed : graph[src]) {
    if (visited[ed.nbr] == false)
    dfs(graph, ed.nbr, visited);
  }
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
  vector<bool> vis(vtces, false);
  dfs(graph, 0, vis);
  for (int i = 0 ; i < vtces ; i++) {
    if (!vis[i]) {
      cout << "false";
      return 0;
    }
  }
  cout << "true";
}
//Java Solution
import java.io.*;
import java.util.*;

public class Main {
   static class Edge {
      int src;
      int nbr;
      int wt;

      Edge(int src, int nbr, int wt) {
         this.src = src;
         this.nbr = nbr;
         this.wt = wt;
      }
   }

   public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

      int vtces = Integer.parseInt(br.readLine());
      ArrayList<Edge>[] graph = new ArrayList[vtces];
      for (int i = 0; i < vtces; i++) {
         graph[i] = new ArrayList<>();
      }

      int edges = Integer.parseInt(br.readLine());
      for (int i = 0; i < edges; i++) {
         String[] parts = br.readLine().split(" ");
         int v1 = Integer.parseInt(parts[0]);
         int v2 = Integer.parseInt(parts[1]);
         int wt = Integer.parseInt(parts[2]);
         graph[v1].add(new Edge(v1, v2, wt));
         graph[v2].add(new Edge(v2, v1, wt));
      }
      boolean[] visited = new boolean[vtces];
      ArrayList<ArrayList<Integer>> comps = new ArrayList<>();
      for(int v = 0; v < vtces; v++){
         if(visited[v] == false){
            ArrayList<Integer> comp = new ArrayList<>();
            gcc(graph, v, visited, comp);
            comps.add(comp);
         }
      }
      System.out.println(comps.size() == 1);
   }

   public static void gcc(ArrayList<Edge>[] graph, int src, boolean[] visited, ArrayList<Integer> comp) {
      comp.add(src);
      visited[src] = true;
      for (Edge e : graph[src]) {
         if (!visited[e.nbr]) {
            gcc(graph, e.nbr, visited, comp);
         }
      }
   }

}
