#include<iostream>
#include<vector>
using namespace std;
struct Edge{
int src,dest,weight;
};
typedef pair<int,int> Pair;
class Graph{
public:
    vector<vector<Pair>> adjList;
    Graph(vector<Edge> const &edges,int N){
        //resize to no. of nodes
        adjList.resize(N);
        //add edges to the directed graph
        for(auto &edge:edges){
           int src=edge.src;
           int dest=edge.dest;
           int weight=edge.weight;
           //insert at the end
           adjList[src].push_back(make_pair(dest,weight));
           //uncomment below lines for undirected graph
           //adjList[dest].push_back(make_pair(src,weight));

        }
    }
};
void printList(Graph const &graph,int N){
    for(int i=0;i<N;i++){
        for(Pair v:graph.adjList[i]){
            cout<<"("<<i<<","<<v.first<<","<<v.second<<")";
        }
        cout<<endl;
    }
}
int main(){
 vector<Edge>edges={
{0,1,6},{1,2,7},{2,0,5},{2,1,4},
  {3,2,10},{4,5,1},{5,4,3}
 };
 int N=6;
 int n=sizeof(edges)/sizeof(edges[0]);
 Graph graph(edges,N);
 printList(graph,N);
return 0;
}
