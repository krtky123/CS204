#include<bits/stdc++.h>

using namespace std;

#define lli long long

short c[1000][1000],v[1000][1000];
lli S;
lli count(lli i,lli j,lli n,lli m,lli k)
{
    v[i][j]=0;
    S++;
    if(i>0)
    {
        if(c[i-1][j]==k&&v[i-1][j])
        count(i-1,j,n,m,k);
    }
    if(j>0)
    {
        if(c[i][j-1]==k&&v[i][j-1])
        count(i,j-1,n,m,k);
    }
    if(i<n-1)
    {
        if(c[i+1][j]==k&&v[i+1][j])
        count(i+1,j,n,m,k);
    }
    if(j<m-1)
    {
        if(c[i][j+1]==k&&v[i][j+1])
        count(i,j+1,n,m,k);
    }
    return S;
}

int main()
{
    lli n,m;
    cin>>n>>m;
    lli k;
    cin>>k;
    vector<pair<lli,lli>> V;
    lli x,y;
    lli res=0;
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    {
        cin>>x;
        v[i][j]=1;
        c[i][j]=x;
    }

    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    {
        
        if(v[i][j])
        {
            S=0;
            lli C=count(i,j,n,m,c[i][j]);
            res=max(res,C);
        }
    }
    cout<<res<<endl;
}
