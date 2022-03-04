
#include <iostream>
using namespace std;

void DFS(int node,vector<int> adj[] , int edges,vector<int> &visited)
{
visited[node]=1;
cout<<node<<" ";
for(auto it:adj[node]){
 if(!visited[it])
  dfs(it,adj,edges,visited);
}
}
int main()
 {
int vertex,edges;
cin>>vertex>>edges;

// We are taking an array which is storing the vector 
vector<int> adj[vertex+1];

for(int i =1;i<edges+1;i++)
{
	int vertex1,vertex2;
cin>>vertex1>>vertex2;
adj[vertex1].push_back(vertex2);
adj[vertex2].push_back(vertex1);

}
vector<int> v(vertex+1,0);
for(int i =0;i<vertex;i++){
DFS(i,adj,edges,v);
}
return 0;
 }
