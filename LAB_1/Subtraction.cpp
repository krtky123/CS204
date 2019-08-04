#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int isgreater(string str1, string str2)
{
	if (str1.length() > str2.length())
        return 1;
	else if (str2.length() > str1.length())
        return 2;
	else
	{
		for (int i=0; i<str1.length(); i++)
		{
			if ((str1[i]-'0') > (str2[i]-'0'))
                    return 1;
			else if ((str1[i]-'0') < (str2[i]-'0'))
				return 2;
		}
	}
	return 0;
}

string showdiff(string s1, string s2)
{
    int c=0, flag, i;
    string str3;

    reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());

	int size1=s1.length();
	int size2=s2.length();

	for (i=0; i<size2; i++)
	{
		if ((int)(s1[i]-'0')+c >= (int)(s2[i]-'0'))
		{
			flag = (int)(s1[i]-'0') - (int)(s2[i]-'0') + c;
			str3.push_back(flag+'0');
			c = 0;
		}
		else
		{
			flag = 10 + c + (int)(s1[i]-'0') - (int)(s2[i]-'0');
			str3.push_back(flag+'0');
			c = -1;
		}
	}

	for (; i<size1; i++)
	{
		if ((int)(s1[i]-'0')+c >= 0)
		{
			flag = (int)(s1[i]-'0')+ c;
			str3.push_back(flag+'0');
			c = 0;
		}
		else
		{
			flag = 10 + c + (int)(s1[i]-'0');
			str3.push_back(flag+'0');
			c = -1;
		}
	}

	reverse(str3.begin(), str3.end());
	while (str3[0]=='0')  str3.erase(str3.begin());
	return str3;
}

string showsum(string s1, string s2)
{
    int c=0, flag, i;
    string str3;

    reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());

	int size1=s1.length();
	int size2=s2.length();

	if (size1 > size2)
	{
		for (i=0; i<size2; i++)
		{
			flag = (int)(s1[i]-'0') + (int)(s2[i]-'0') + c;
			str3.push_back(flag%10 + '0');
			c = flag/10;
		}
		for (; i<size1; i++)
		{
			flag = (int)(s1[i]-'0') + c;
			str3.push_back(flag%10 + '0');
			c = flag/10;
		}
		if (c==1)	str3.push_back('1');
	}

	else
	{
		for (i=0; i<size1; i++)
		{
			flag = (int)(s1[i]-'0') + (int)(s2[i]-'0') + c;
			str3.push_back(flag%10 + '0');
			c = flag/10;
		}
		for (; i<size2; i++)
		{
			flag = (int)(s2[i]-'0') + c;
			str3.push_back(flag%10 + '0');
			c = flag/10;
		}
		if (c==1)	str3.push_back('1');
	}

	reverse(str3.begin(), str3.end());
	return str3;
}

void subtractor(string s1, string s2)
{
	char char1, char2;
	int res;

	char1 = s1[0];
	char2 = s2[0];

	if (char1=='-' && char2=='-')
	{
	    s1.erase(s1.begin());
	    s2.erase(s2.begin());
	    res = isgreater(s1, s2);

	    if (!res)         cout<<"0";
	    else if (res==2)  cout<<showdiff(s2,s1);
	    else                  cout<<"-"<<showdiff(s1,s2);
	}

	else if (char1=='-')
	{
	    s1.erase(s1.begin());
	    cout<<"-"<<showsum(s1,s2);
	}

    else if (char2=='-')
    {
        s2.erase(s2.begin());
        cout<<showsum(s1,s2);
    }

	else
	{
	    res = isgreater(s1, s2);
        if (!res)           cout<<"0";
        else if (res == 1)  cout<<showdiff(s1,s2);
        else                    cout<<"-"<<showdiff(s2,s1);
	}
}


int main()
{
    int t;
    cin>>t;
    string str;
    getline(cin, str);

    while(t--)
    {
        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);
        subtractor(s1, s2);
        cout<<"\n";
    }
	return 0;
}
