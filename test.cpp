#include<bits/stdc++.h>
using namespace std;

int n = 10000;
bool hascycle = false;

vector<vector<int>> adj(n);
vector<int> visited(n+1,0);
stack<int> s;

void dfs(int v)
{
	if(visited[v]!=0) return;
	visited[v] = 1;
	for(int u: adj[v])
	{
		if(visited[u]==1){
			hascycle = true;
			return;
		} 
		if(visited[u]==0) dfs(u);
	}
	visited[v] = 2;
	s.push(v);
}

void topoplogicaL_sort(int k)
{
	for(int i=1; i<=k; i++)
	{
		if(visited[i]==0) dfs(i);
	}
}

int main(void)
{
	int m;
	cin >> n >> m;
	for(int i=0; i<m; i++)
	{
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);		
	}
	
	topoplogicaL_sort(n);
	while(!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}
	
	
	return 0;
}