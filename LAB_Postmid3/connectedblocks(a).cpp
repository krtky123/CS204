#include<bits/stdc++.h>

using namespace std;

#define lli long long

vector<short> v;
vector<pair<lli,lli>> V;
lli S;

lli check(lli i,lli j)
{
    lli l=0,r=V.size()-1;
    lli p=-1;
    pair<lli,lli> q={i,j};
    while (l <= r) { 
        int m = l + (r - l) / 2; 
        if (V[m] == q) 
            {
                p=m;
                break;
            } 
        if (V[m] < q) 
            l = m + 1; 
        else
            r = m - 1; 
    } 
    if(p>=0)
    {
        if(v[p])
        return p;
        else return -1;
    }
    return p;
}

lli count(lli i,lli j,lli n,lli m,lli k)
{
    v[k]=0;
    S++;
    lli p;
    //cout<<S<<'u';
    if(i>0)
    {
        p=check(i-1,j);
        if(p>=0)
        count(i-1,j,n,m,p);
    }
    if(j>0)
    {
        p=check(i,j-1);
        if(p>=0)
        count(i,j-1,n,m,p);
    }
    if(i<n-1)
    {
        p=check(i+1,j);
        if(p>=0)
        count(i+1,j,n,m,p);
    }
    if(j<m-1)
    {
        p=check(i,j+1);
        if(p>=0)
        count(i,j+1,n,m,p);
    }
    return S;
}

int main()
{
    lli n,m;
    cin>>n>>m;
    lli k;
    cin>>k;
  
    lli x,y;
    lli M=0;
  
    for(int i=0;i<k;i++)
    {
        cin>>x>>y;
        x--;
        y--;
        V.push_back({x,y});
        v.push_back(1);
    }
    sort(V.begin(),V.end());
    for(int i=0;i<k;i++)
    {
        
        if(v[i])
        {
            S=0;
            lli C=count(V[i].first,V[i].second,n,m,i);
            M=max(M,C);
        }
    }
    cout<<M<<endl;
}
