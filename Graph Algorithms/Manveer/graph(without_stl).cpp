#include<iostream>
using namespace std;
//data structure to store adjacency list
struct node{
int val;
node* next;
};
//data structure for edges
struct edge{
int src,dest;
};
class graph{
 //function to initialize adjacency list
 node* get_Adj_list(int dest,node* head){
            node* newNode=new node;
            newNode->val=dest;

            //point new node to curr
            newNode->next=head;
            return newNode;
 }
 int N;  //number of nodes in graph
 public:
     //array of pointers to adjacency list
     node **head;
     //constructor
     graph(edge edges[],int n,int N){
     //allocate memory
     head=new node*[N]();
     this->N=N;
     //initialize head pointer for all vertices
     for(int i=0;i<N;i++)
        head[i]=NULL;
     //add edges to the directed graph
     for(unsigned i=0;i<n;i++)
      {int src=edges[i].src;
       int dest=edges[i].dest;
       //insert at the beginning
       node*newNode=get_Adj_list(dest,head[src]);
       //point head pointer to new node
       head[src]=newNode;
       //uncomment below lines for undirected graph
       /*
       newNode=get_Adj_list(src,head[dest]);
       //change head pointer to poin to new node
       head[dest]=newNode;
       */
      }
     }
     //graph deconstructor
     ~graph(){
      for(int i=0;i<N;i++)
       delete[] head[i];
      delete[] head;
     }
};
void printlist(node* ptr){
 while(ptr!=NULL){
    cout<<" -> "<<ptr->val<<" ";
    ptr=ptr->next;
 }
 cout<<endl;
}
int main(){
 edge edges[]={
  //pair (x,y) represents vertices forming edge from c to y
    {0,1},{1,2},{2,0},{2,1},{3,2},{4,5},{5,4}
  };
  //Number of vertices
  int N=6;
  //calculate the number of edges
  int n=sizeof(edges)/sizeof(edges[0]);
  graph G(edges,n,N);
  //print adjacency list representation of graph
  for(int i=0;i<N;i++){
    cout<<i<<"--";
    //print all its neighbours
    printlist(G.head[i]);
  }
  return 0;
 }
