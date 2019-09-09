#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main()
{
    lli test_cases,l;
  vector <string> arr;
  string a;

  cin>>test_cases;

  for(lli i=0;i<test_cases;i++)
  {
    cin>>l;

    for(lli j=0;j<l;j++)
    {
      cin>>a;
      arr.push_back(a);
    }

    sort(arr.begin(), arr.end(), [](string &a, string &b)
      {
        string tmp1 = a+b;
        string tmp2 = b+a;
        return tmp1>tmp2;
      });

    for(lli k=0;k<arr.size();k++) 
    {
      cout<<arr[k];
    }

    cout<<endl;
    arr.clear();
  }

  return 0;
}
