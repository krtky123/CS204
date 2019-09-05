#include <bits/stdc++.h>

using namespace std;

long long int binary_search(long long int a[], long long int n, long long int k){
    
    long long int m = k;
    long long int l = 0;
 
    
    while(m>=l){
        if(a[(m+l)/2] > n){
            
            m = (m+l)/2 - 1;
            
        } else if(a[(m+l)/2] == n){
            
            return (m+l)/2;
            
        }  else {
            
            l = (m+l)/2 + 1;
            
        }
        
        
    }
    
    return -1;
    
    
}

int main(){

    int n,q;
    cin>>n>>q;
    long long int x[q],y[q],z[q],w[q];
    

    long long int k=0;
    for(long long int i=0; i<q; i++){
        cin>>x[i];
        if(x[i]==1){
            cin>>y[i]>>z[i];
            w[k]=y[i];
            k++;
        }else
        {
            y[i]=-1;
            z[i]=-1;
        }
    }
    sort(w,w+k);
    long long int customers[k];
   

    customers[0]=w[0];
    long long int g=1;
    for(long long int i=1; i<k; i++){
        if(w[i]==w[i-1])continue;
        else
        {
            customers[g]=w[i];
            g++;
        }
    }

    long long int value[g]={0};

    long long int max_amount=-1,maximum=-1;
    for(long long int i=0; i<q; i++){
        if(x[i]==1){
            long long int tmp=binary_search(customers,y[i],g);
            value[tmp]+=z[i];
            if(value[tmp]>max_amount){
                max_amount=value[tmp];
                maximum=tmp;
            }
        } else
        {
            if(maximum==-1)cout<<"No Data Available."<<endl;
            else cout<<customers[maximum]<<endl;
        }
    }

}
