#include<bits/stdc++.h>
using namespace std;
string multiply(string str1,int c)
{
 string s;
reverse(str1.begin(),str1.end());
int r;
r=0;
int m=str1.length();
for(int i=0;i<m;i++)
{
	int prod=(str1[i]-'0')*c + r;
	s.push_back(prod%10+'0');
	r=prod/10;
}
if(r!=0){
s.push_back(r+'0');
}
reverse(s.begin(),s.end());
return s;
}

string add(string str1,string str2)
{
string str;
if(str1.length()<str2.length()){swap(str1,str2);}
reverse(str1.begin(),str1.end());
reverse(str2.begin(),str2.end());
int n1=str1.length();
int n2=str2.length();
int r=0;
int sum;
for(int i=0;i<n2;i++)
{
	sum=(str1[i]-'0')+(str2[i]-'0')+r;
	r=sum/10;
	str.push_back(sum%10+'0');
}
for(int j=n2;j<n1;j++)
{
	sum=(str1[j]-'0')+r;
	r=sum/10;
	str.push_back(sum%10+'0');

}
if(r!=0){str.push_back(r+'0');}
reverse(str.begin(),str.end());
return str;


}



int main()
{
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
       string s1,s2,s3;
cin>>s1>>s2;
s3='0';
int n1=s1.length();
int n2=s2.length();
reverse(s2.begin(),s2.end());
for(int i=0;i<n2;i++)
{
string s=multiply(s1,(s2[i]-'0'));
for(int j=0;j<i;j++)
{
s.push_back('0');
}

s3=add(s3,s);
}
cout<<s3<<endl<<endl;
    }

return 0;
}
