#include<bits/stdc++.h> 
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
       	 return 1; 
    	 return 0; 
} 
et* newNode(string v) 
{ 
    et *temp = new et; 
    temp->left = temp->right = NULL; 
    temp->value = v; 
    return temp; 
}

int precedance(string c) 
{ 
    if(c == "^") 
    return 3; 
    else if(c == "*" || c == "/") 
    return 2; 
    else if(c == "+" || c == "-") 
    return 1; 
    else
    return -1; 
} 

vector <string> infixToPostfix(vector <string> str)
{
    stack <string> man;
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
	
            while(man.top() != "END" && precedance(str[i]) <= precedance(man.top()))
            {
		    if(precedance(str[i])==3 && precedance(man.top())==3)break;
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

 int integer=stoi(s);
      
    return integer;  
}  

et* constructTree(vector <string> postfix) 
{ 
    stack<et *> st; 
    et *t, *t1, *t2; 
  
    

    for (int i=0; i<postfix.size(); i++) 
    { 
        
 
        if (isOperator(postfix[i])==0) 
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
    if(root->value=="/")
	    return l_val/r_val;
	if(root->value=="^")
		return pow(l_val,r_val);
	return -1;
}  

int main(){
   long long int t;
   cin>>t;
    while(t--){
    	long long int n;
    	cin>>n;
    	while(n--){
        int check=1;
    string s;
    cin>>s;
    vector <string> v;
    int c=0;
    int close=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('||s[i]==')'||s[i]=='*'||s[i]=='^'||s[i]=='-'||s[i]=='+'||s[i]=='/'){
           
            string res;
            res+=s[i];
            if(i==0&&s[i]=='-'){
                close++;
                v.push_back("(");
                v.push_back("0");
               
            }
           
            if(i!=0&&(s[i]=='-'&&c==1)){
                close++;
                v.push_back("(");
                v.push_back("0");
            }
           
            if(s[i]!=')')c=1;
            v.push_back(res);
        }
        else if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
            string res;
            while((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')&&i<s.length()){
               
                res+=s[i];
                i++;
            }
            i--;
            v.push_back(res);
        }
        else{
            c=0;
            string res;
            while(s[i]>='0'&&s[i]<='9'&&i<s.length()){
               
                res+=s[i];
                i++;
            }
            i--;
            v.push_back(res);
            while(close!=0){
                v.push_back(")");
                close--;
            }
        }
       
    }
    while(close!=0){
                v.push_back(")");
                close--;
            }
   
    if(check){
    vector <string> abc=infixToPostfix(v);
    et*t = constructTree(abc);

	
	cout<<eval(t)<<endl;
}
else{
	cout<<"NOT VALID"<<endl;
}
}

	
	return 0;
	
}
}
