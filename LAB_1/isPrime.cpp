#include<bits/stdc++.h>
using namespace std;

string add(string a, string b){
    int carry=0;
    string ans = "";
    if(a.size() < b.size()){
        swap(a,b);
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for(int i = 0; i< b.size(); i++){
        int sum = a[i]-'0'+b[i]-'0'+carry;
        ans+=sum%10+'0';
        carry=sum/10;
    }

    for(int i = b.size(); i<a.size(); i++){
        int sum = a[i]-'0'+carry;
        ans+=sum%10+'0';
        carry = sum/10;
    }
    if(carry){ans+= (carry+'0');}
    reverse(ans.begin(), ans.end());
    return ans;
}

string subract(string a ,string b){
	string ans;
	bool neg=0;

	if(a.length()<b.length()){
		swap(a,b);
		neg=1;
	}
	if(a.length()==b.length()){
		for(int i=0;i<a.length();i++){
			if(a[i]!=b[i]){
				if(a[i]<b[i]){
					swap(a,b);
				}
				break;
			}
		}
		neg=1;
	}

	int carry=0;
	int nb= b.length(),na=a.length();
	int j=nb-1,i=na-1;
	while(j>=0){
		int s= a[i]-b[j]-carry;
		if(s<0){
			ans+=a[i]-b[j]+'0'+10-carry;
			carry=1;

		}
		else{
			ans+=a[i]-b[j]+'0'-carry;
			carry=0;
		}
		i--;j--;
	}

	while(i>=0){
		int s=a[i]-carry;
		if(s<0){
			ans+=(a[i]+10-carry);
			carry=1;
		}
		else{
			ans+=(a[i]-carry);
			carry=0;
		}
		i--;
	}
	int start=ans.size()-1;
	while(start>=0&&ans[start]=='0'){
		start--;
	}

	string res;
	for(int i=start;i>=0;i--)res+=ans[i];
    return res;



}
int Comparing2strings(string a,string b){
	int na=a.length(),nb=b.length();

	if(na<nb) return 1;
	if(na>nb) return -1;
	for(int i=0;i<na;i++){
		if(a[i]<b[i]) {
			return 1;}
		else if(a[i]>b[i]) { return -1;}
	}
	return 0;
}
int Comparing2strings_Part2(string a,string b){
	int na=a.length(),nb=b.length();
	if(na>nb) return 1;
	for(int i=0;i<na;i++){
		if(a[i]<b[i]) {
			return 0;}
		else if(a[i]>b[i]) { return 1;}
	}
	return 0;
}

string divide(string a ,string b){

	int nb= b.length(),na=a.length();
	if(Comparing2strings(a,b)==1){

		return a;
	}
	else if(Comparing2strings(a,b)==0){


		return "0";
	}
	else{

		int k=b.size();
		vector<int> quotient;
		string remainder=a.substr(0,nb);
		int i=0;
		k--;
		while(k<a.size()){
			int count=0;

			while(Comparing2strings(b,remainder)==0||Comparing2strings(b,remainder)==1){

				remainder=subract(remainder,b);
				count++;
			}
			quotient.push_back(count);
			if(k==a.size()-1)
				break;
			remainder+=a[++k];
			i++;

		}

		return remainder;

	}


}
void prime(string a){
    string init = "2";
    if(a == "2"){cout<<"Prime"<<endl; return;}
    if(a == "3"){cout<<"Prime"<<endl; return;}
    while(Comparing2strings_Part2(a, init)&&init.length()<=(a.length()/2)+1){
        if(divide(a, init).length()==0){
            cout<<"Not a Prime"<<endl;
            return;
        }
        init = add(init, "1");

       }

    cout<<"Prime"<<endl;
}
int main(){
    long long t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        prime(s);
    }
}
