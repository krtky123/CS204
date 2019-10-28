#include<bits/stdc++.h>
#define lli long long int
#include<vector>

using namespace std;

int main()
{
	lli n,m,a,b;
	cin>>n>>m;
	vector <lli> v[n+5];
	lli tmp[n+5]={0};
	for(lli i=0;i<m;i++)
	{
		cin>>a>>b;
		v[b].push_back(a);
		v[a].push_back(b);

	}
	queue<lli> q;
	lli colour_is_best=1;
	tmp[1]=1;
	q.push(1);

	while(!q.empty())
	{
		lli k=q.front();
		q.pop();
		if(tmp[k]==1)
		{
			colour_is_best=2;
		}
		else
		{
			colour_is_best=1;
		}
		for(lli j=0;j<v[k].size(); j++)
		{
			if(tmp[v[k][j]]==0)
			{
				q.push(v[k][j]);
			}
			if(tmp[v[k][j]]==0 || tmp[v[k][j]]==colour_is_best)
			{
				tmp[v[k][j]]=colour_is_best;
			}
			else
			{
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	cout<<"YES"<<endl;
	return 0;
}
