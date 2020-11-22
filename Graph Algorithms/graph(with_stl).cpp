#include<iostream>
#include<vector>
using namespace std;
struct edge{
int src,dest;
};
class graph{
public: //construct a vector of vectors to represent adjacency list
        vector<vector<int> > adjList;
        graph(vector<edge> const &edges,int N){
         //resize the vector to N elements of type vector<int>
         adjList.resize(N);
         for(auto &edge: edges){
            //insert edges to the directed graph
            adjList[edge.src].push_back(edge.dest);
            //uncomment below line for undirected graph
            //adjList[edge.dest].push_back(edge.src)
         }
        }
};
//print adjacency list representation of graph
void printlist(graph const &graph,int N){
 for(int i=0;i<N;i++){
  //current vertex no.
  cout<<i<<" -->";
  for(int v:graph.adjList[i])
    cout<<v<<" ";
  cout<<endl;
 }
}
int main(){
 //intializing edges
 vector<edge> edges={
   {0,1},{1,2},{2,0},{2,1},{3,2},{4,5},{5,4}
  };
  //Number of nodes in graph
  int N=6;
 graph G(edges,N);
 printlist(G,N);
 return 0;
}
