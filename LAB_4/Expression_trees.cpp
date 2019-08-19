#include<iostream>
#include<bits/stdc++.h> 
#include <string>
#include<stack>
#include<vector>
#define lli long long int

using namespace std; 

struct et 
{ 
    string value; 
    et* left, *right; 
}; 

bool isOperator(string c) 
{ 
   	 if (c == "+" || c == "-" || 
            c == "*" || c == "/" || 
            c == "^") 
       	 return true; 
    	 return false; 
} 
et* newNode(string v) 
{ 
    et *temp = new et; 
    temp->left = temp->right = NULL; 
    temp->value = v; 
    return temp; 
}; 
int precedance(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 

vector <string> infixToPostfix(vector<string> str)
{
    stack<string> man;
    man.push("END");
    vector <string> operation;
    for(int i = 0; i < str.size(); i++)
    {
        
        if(str[i]!="("&&str[i]!=")"&&str[i]!="*"&&str[i]!="^"&&str[i]!="-"&&str[i]!="+"&&str[i]!="/")
        operation.push_back(str[i]);
 
        
        else if(str[i] == "(")
         
        man.push("(");
         

        else if(str[i] == ")")
        {
            while(man.top() != "END"&& man.top() != "(")
            {
                string s = man.top();
                man.pop();
               operation.push_back(s);
            }
            if(man.top() == "(")
            {
                string s = man.top();
                man.pop();  
            }
        }
         
        
        else{
		string extra= man.top();string extra2= str[i];
            while(man.top() != "END" && precedance(extra2[0]) <= precedance(extra[0]))
            {
                string s = man.top();
                man.pop();
                operation.push_back(s);
            }
            man.push(str[i]);
        }
 
    }
    
    while(man.top() != "END")
    {
        string s = man.top();
        man.pop();
        operation.push_back(s);
    }
     
    return operation;
}
int toInt(string s)  
{  
    int integer = 0;  
      
    integer=stoi(s);
      
    return integer;  
}  

et* constructTree(vector <string> postfix) 
{ 
    stack<et *> st; 
    et *t, *t1, *t2; 
  
    

    for (int i=0; i<postfix.size(); i++) 
    { 
        
 
        if (!isOperator(postfix[i])) 
        { 
            t = newNode(postfix[i]); 
            st.push(t); 
        } 
        else 

        { 
            t = newNode(postfix[i]); 
  
           

 
            t1 = st.top(); 

            st.pop();     
 
            t2 = st.top(); 
            st.pop(); 
  
            
            t->right = t1; 
            t->left = t2; 
  
            
            st.push(t); 
        } 
    } 
  
     
    t = st.top(); 
    st.pop(); 
  
    return t; 
} 

int eval(et* root)  
{  
      
    if (!root)  
        return 0;  
  
     
    if (!root->left && !root->right)  
        return toInt(root->value);  
  
     
    int l_val = eval(root->left);  
  
      
    int r_val = eval(root->right);  
  
     
    if (root->value=="+")  
        return l_val+r_val;  
  
    if (root->value=="-")  
        return l_val-r_val;  
  
    if (root->value=="*")  
        return l_val*r_val;  
    if(root->value=="^"){
    	return pow(l_val,r_val);
    }
  
    return l_val/r_val;  
}  

int main()
{
lli t;
cin>>t;
for(lli i=0; i<t; i++)
{
lli n;
cin>>n;
for(lli i=0; i<n;i++)
{
string str;
cin>>str;
vector <string> s;
for(int i=0;i<str.length();i++){
	if(str[i]=='('||str[i]==')'||str[i]=='*'||str[i]=='^'||str[i]=='-'||str[i]=='+'||str[i]=='/')
	{
		string result;
		result+=str[i];
		s.push_back(result);
	}
	else
	{
		string result;
		while(str[i]!='(' && str[i]!=')' && str[i]!='*' && str[i]!='^' && str[i]!='-' && str[i]!='+' && str[i]!='/' && i<str.length())
	{
		result+=str[i];
		i++;
	}
		i--;
		s.push_back(result);
	}
	}

vector <string> test_case=infixToPostfix(s);

et* abc = constructTree(test_case);
cout<<eval(abc)<<endl;
}
}
return 0;

}
