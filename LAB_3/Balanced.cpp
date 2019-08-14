#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#define lli long long int

using namespace std;

bool isMatching(string str)
{
lli count =0;
stack <char> s;

char x;
for(lli  i=0; i<str.length(); i++)
{
	
	if(str[i]=='(' || str[i]=='{' || str[i]=='[' || str[i]=='<')
		{
			s.push(str[i]);
			count++;
			continue;
		}
	
	else if(str[i]=='|')
	{
		if(s.empty()){
		s.push(str[i]);
		count++;
		//cout<<1<<endl;
                  }
		
		else if(s.top()!='|'){
		s.push(str[i]); 
		count++;}

		else
		s.pop();
		 //continue;

	}
	
	else 
	{
		if(str[i]==')') {
		if(s.empty())return false;
		 x = s.top(); 
		
                s.pop(); 
                if (x=='{' || x=='[' || x=='<' || x=='|') 
                return false; 
                 }
                
                else if(str[i]=='}'){
              
                if(s.empty())return false;
                
                x = s.top(); 
                s.pop(); 
                if (x=='(' || x=='[' || x=='<' || x=='|') 
                return false; 
                }
                
                else if(str[i]==']'){
                if(s.empty())return false;
                x = s.top(); 
                s.pop(); 
                if (x =='(' || x == '{' || x=='<' || x=='|') 
                return false; 
                }
                
		else if(str[i]=='>'){
		if(s.empty())return false;
                x = s.top(); 
                s.pop(); 
                if (x =='(' || x == '{' || x=='[' || x=='|') 
                return false; 
                
                }
		else return false;
}
		 
   
}

if(count==0) cout<<"NO";
return (s.empty()); 

}
int main()
{
lli n;
cin>>n;
for(lli i=0; i<n; i++)
{
	string str;
	cin>>str;
	bool k=isMatching(str);
	if(!k)
	cout<<"NO"<<endl;
	if(k)
	cout<<"YES"<<endl;
}
return 0;
}
