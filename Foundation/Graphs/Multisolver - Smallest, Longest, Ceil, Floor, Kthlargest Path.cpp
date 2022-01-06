/*
1. You are given a graph, a src vertex and a destination vertex.
2. You are give a number named "criteria" and a number "k".
3. You are required to find and print the values of 
3.1 Smallest path and it's weight separated by an "@"
3.2 Largest path and it's weight separated by an "@"
3.3 Just Larger path (than criteria in terms of weight) and it's weight separated by an "@"
3.4 Just smaller path (than criteria in terms of weight) and it's weight separated by an "@"
3.5 Kth largest path and it's weight separated by an "@"
Input Format
Input has been managed for you
Output Format
Check sample output
Constraints
None
Sample Input
7
9
0 1 10
1 2 10
2 3 10
0 3 40
3 4 2
4 5 3
5 6 3
4 6 8
2 5 5
0
6
30
4
Sample Output
Smallest Path = 01256@28
Largest Path = 032546@66
Just Larger Path than 30 = 012546@36
Just Smaller Path than 30 = 01256@28
4th largest path = 03456@48
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


struct myComp {
  bool operator()(
    pair<int, string>& a,
    pair<int, string>& b)
  {
    return a.first > b.first;
  }
};
string spath;
int spathwt = INT_MAX;
string lpath;
int lpathwt = INT_MIN;
string cpath;
int cpathwt = INT_MAX;
string fpath;
int fpathwt = INT_MIN;

priority_queue<pair<int, string>, vector<pair<int, string>>, myComp> pq;

void multisolver(vector<Edge> graph[], int src, int dest, vector<bool> visited, int criteria, int k, string psf, int wsf) {
  if (src == dest) {
    if (wsf < spathwt) {
      spathwt = wsf;
      spath = psf;
    }

    if (wsf > lpathwt) {
      lpathwt = wsf;
      lpath = psf;
    }
    if (wsf < criteria) {
      if (wsf > fpathwt) {
        fpathwt = wsf;
        fpath = psf;
      }
    }
    if (wsf > criteria) {
      if (wsf < cpathwt) {
        cpathwt = wsf;
        cpath = psf;
      }
    }
    pair<int, string> p;
    p.first = wsf;
    p.second = psf;
    if (pq.size()< k) pq.push(p);
     else{
         if(wsf>pq.top().first){
          pq.pop();
          pq.push(p);
         }
     }
     return;
  }
  visited[src] = true;

  for (Edge e : graph[src]) {
    if (!visited[e.nbr]) {
      multisolver(graph, e.nbr, dest, visited, criteria, k, psf + to_string(e.nbr), wsf + e.wt);
    }
  }

  visited[src] = false;

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

  int criteria;
  cin >> criteria;
  int k;
  cin >> k;

  vector<bool> visited(vtces, false);
  multisolver(graph, src, dest, visited, criteria, k, src + "0", 0);

  cout << "Smallest Path = " << spath << "@" << spathwt << endl;
  cout << "Largest Path = " << lpath << "@" << lpathwt<<endl;
  cout << "Just Larger Path than " << criteria << " = " << cpath << "@" << cpathwt << endl;
  cout << "Just Smaller Path than " << criteria << " = " << fpath << "@" << fpathwt << endl;
  cout << k << "th largest path = " << pq.top().second << "@" << pq.top().first << endl;

  return 0;
}
