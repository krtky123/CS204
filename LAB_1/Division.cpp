#include<bits/stdc++.h>
using namespace std;

string subtract(string str1 ,string str2)
    {
	string res;
	bool c=0;

	if(str1.length()<str2.length())
        {
		swap(str1,str2);
		c=1;
        }
	if(str1.length()==str2.length()){
		for(int i=0;i<str1.length();i++){
			if(str1[i]!=str2[i]){
				if(str1[i]<str2[i])
                    {
					swap(str1,str2);
                    }
				break;
			}
		}
		c=1;
	}

	int borrow=0;
	int size_str1= str1.length(),size_str2=str2.length();
	int j=size_str2-1,i=size_str1-1;
	while(j>=0){
		int s= str1[i]-str2[j]-borrow;
		if(s<0){
			res+=str1[i]-str2[j]+'0'+10-borrow;
			borrow=1;

		}
		else{
			res+=str1[i]-str2[j]+'0'-borrow;
			borrow=0;
		}
		i--;j--;
	}

	while(i>=0){
		int s=str1[i]-borrow;
		if(s<0){
			res+=(str1[i]+10-borrow);
			borrow=1;
		}
		else{
			res+=(str1[i]-borrow);
			borrow=0;
		}
		i--;
	}
	int start=res.size()-1;
	while(start>=0&&res[start]=='0'){
		start--;
	}

	string result;
	for(int i=start;i>=0;i--)result+=res[i];
    return result;



}
int string_compare(string str1,string str2){
	int size_str1=str1.length(),size_str2=str2.length();

	if(size_str1<size_str2) return 1;
	if(size_str1>size_str2) return -1;
	for(int i=0;i<size_str1;i++){
		if(str1[i]<str2[i]) {
			return 1;}
		else if(str1[i]>str2[i]) { return -1;}
	}
	return 0;
}

void divide(string str1 ,string str2){

	int size_str2= str2.length(),size_str1=str1.length();
	if(string_compare(str1,str2)==1){

		cout<<0<<endl<<str1<<endl;
		return;
	}
	else if(string_compare(str1,str2)==0){

		cout<<1<<endl<<0<<endl;
		return;
	}
	else{

		int k=str2.size();
		vector<int> quotient;
		string remainder=str1.substr(0,size_str2);
		int i=0;
		k--;
		while(k<str1.size()){
			int count=0;
			while(string_compare(str2,remainder)==0||string_compare(str2,remainder)==1){
				remainder=subtract(remainder,str2);
				count++;
			}
			quotient.push_back(count);
			if(k==str1.size()-1)
				break;
			remainder+=str1[++k];
			i++;
		}
		int s=0;
		while(quotient[s]==0&&s<quotient.size())s++;

		for(int i=s;i<quotient.size();i++){
			cout<<quotient[i];

		}
		if(remainder.length()==0){
			remainder+="0";
		}
		cout<<endl<<remainder<<endl;

	}


}

int main(){
	int t;cin>>t;
	while(t--){
	string a,b;
	cin>>a>>b;
	divide(a,b);
	cout<<endl;

}

}
