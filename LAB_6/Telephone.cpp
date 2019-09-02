#include<bits/stdc++.h>
#define lli long long int
using namespace std;
int main()
{
	lli no_of_users,q;
	cin>>no_of_users>>q;
	vector <lli> v(no_of_users+1,0);
	lli maximum=-1,maxamount=0;
	while(q--)
	{
		int operation;
		cin>>operation;
		if(operation==1)
		{
			lli userid; cin>>userid;
			if(userid>no_of_users)
				{cout<<"Invalid Input";
				break;}
			lli useramount; cin>>useramount;

			v[userid]+=useramount;
			if(v[userid]>maxamount)
			{
					maxamount=v[userid];
					maximum=userid;
			}
		}
		else if(operation==2)
		{
			if(maximum==-1)
			{
				cout<<"Data Not Available";
			}
			else
				cout<<maximum<<endl;
		}

		else
		{
			cout<<"Invalid Input";
		}	
	}	
return 0;
}
