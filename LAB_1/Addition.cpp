#include<bits/stdc++.h>
using namespace std;
int main()
{
	int no_of_test_cases;
	cin>>no_of_test_cases;
	for(int i=0; i<no_of_test_cases; i++)
        {
		string first_no, second_no;
		cin >> first_no >> second_no;
        string temp = "";
		if (first_no.length() > second_no.length())
	 	       swap(first_no, second_no);

		int l1 = first_no.length(), l2 = second_no.length();
	    	reverse(first_no.begin(), first_no.end());
            reverse(second_no.begin(), second_no.end());
	  	int borrow = 0;
		for (int i=0; i<l1; i++)
		{
		        int sum = ((first_no[i]-'0')+(second_no[i]-'0')+borrow);
		        borrow = sum/10;
		        temp.push_back('0' + sum%10);
		}
		for (int i=l1; i<l2; i++)
		{
			int sum = ((second_no[i]-'0')+borrow);
            borrow = sum/10;
            temp.push_back('0' + sum%10);
		}
		if (borrow !=0)
			temp.push_back(borrow + '0');
		reverse(temp.begin(), temp.end());
		cout << temp << "\n";
	}
}
