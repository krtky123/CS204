#include<bits/stdc++.h>
#include<vector>

using namespace std;

void make_edge(vector <int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

bool isBipartite(vector<int> adj[], int v, vector<bool>& visited, vector<int>& color)
{
	for( int u : adj[v])
	{
		if(visited[u]==false)
		{
			visited[u]=true;
			color[u]=!color[v];
			if(!isBipartite(adj,u,visited,color))
				return false;
		}
		else if(color[u]==color[v])
			return false;
	}
	return true;
}

int main()
{
	int n;
	cin>>n;
	int m;
	cin>>m;
	vector<int>adj[n+1];
	vector<bool> visited(n+1);
	vector<int> color(n+1);

	for(int i=0; i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		make_edge(adj,a,b);
		visited[1]=true;
		color[1]=0;
	}
		if(isBipartite(adj,1,visited,color))
		{
			cout<<"YES"<<endl;

		}
		else
		{
			cout<<"NO"<<endl;
		}


	return 0;
}
