
#include <iostream>
using namespace std;
//so basically the logic is , if we found an element whose next node is visited and not equal to 
//parent then it contains cycle 

bool cycle=false;
void DFS_CYCLE(int node,int parent,vector<int> adj[] , int edges,vector<int> &visited)
{
visited[node]=1;
for(auto it :adj[node]){
    if(!visited[it])
    {
        DFS_CYCLE(it,node,adj,edges,visited);
    }
    else
    {
        if(parent!=it)
        {
            cycle=true;
            cout<<"THERE IS A CYCLE";
            return;
       }
    }
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
DFS_cycle(i,-1,adj,edges,v);
}
return 0;
 }
