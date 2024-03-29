#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e3+10, mod = 1e9+7;

int adj[N][N];

void bfs(int source, int n){
    bool visited[n+1];
    memset(visited,0,sizeof visited);

    queue<int> q;
    q.push(source);
    visited[source]=true;

    while(!q.empty()){
        int vertex = q.front();
        q.pop();

        cout<<"Visiting "<<vertex << "\n";

        for (int child = 1; child <= n; child++)
        {
            if(adj[vertex][child]!=0 && !visited[child]){
                q.push(child);
                visited[child]=true;
            }
        }
    }
}

void dfsTrav(int source, bool visited[],int n){
    visited[source]=true;
    cout<<"Visited "<<source<<'\n';

    for (int child = 1; child <= n; child++)
    {
        if(adj[source][child]!=0 && !visited[child]){
            dfsTrav(child,visited,n);
        }
    }
    
}

void dfs(int source, int n){
    bool visited[n+1];
    memset(visited,0,sizeof visited);

    dfsTrav(source,visited,n);
}

int main(void){

    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int u,v;    cin>>u>>v;
        adj[u][v]=adj[v][u]=1;
    }

    // 1 2 
    // 5 4
    // 3 2
    // 1 7
    // 7 5
    // 8 9
    
    bfs(1,n);
    dfs(1,n);
    return 0;
}
