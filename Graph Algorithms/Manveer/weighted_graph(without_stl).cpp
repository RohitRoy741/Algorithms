#include<iostream>
using namespace std;
struct Node{
int val,cost;
Node* next;
};
struct Edge{
int src,dest,weight;
};
class Graph{
    //function to allocate new node to adjacency list
    Node* getAdjacencyList(int value,int weight,Node *head){
     Node *newNode=new Node;
     newNode->val=value;
     newNode->cost=weight;
     //point new node to current head
     newNode->next=head;
     return newNode;
    }
    int N; //no. of nodes in graph
public:
    Node **head;
    Graph(Edge edges[],int n, int N){
      this->N=N;
      //allocate memory
      head = new Node*[N]();
      //initialize head pointer for all vertices
      for(int i=0;i<N;i++)
        head[i]=NULL;
      //add edges to directed graph
      for(unsigned i=0;i<n;i++){
       int src=edges[i].src;
       int dest=edges[i].dest;
       int weight=edges[i].weight;
       //insert at the beginning
       Node *newNode=getAdjacencyList(dest,weight,head[src]);
       head[src]=newNode;
       //uncomment below lines for undirected graph
       //newNode=getAdjacencyList(src,weight,head[dest]);
       //head[dest]=newNode;
      }
    }
    ~Graph(){
     for(int i=0;i<N;i++){
       delete[] head[i];
      delete[] head;
     }
    }
};
//print all neighboring vertices of given vertex
void printList(Node *ptr,int i){
 while(ptr!=NULL){
    cout<<"("<<i<<","<<ptr->val<<","<<ptr->cost<<") ";
    ptr=ptr->next;
    }
    cout<<endl;
}
int main(){
 Edge edges[]={
  {0,1,6},{1,2,7},{2,0,5},{2,1,4},
  {3,2,10},{4,5,1},{5,4,3}
 };
 int N=6;
 int n=sizeof(edges)/sizeof(edges[0]);
 Graph graph(edges,n,N);
 for(int i=0;i<N;i++){
  printList(graph.head[i],i);
 }
 return 0;
}
