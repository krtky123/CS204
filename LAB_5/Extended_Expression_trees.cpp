#include<bits/stdc++.h>
using namespace std;

struct node
{
  string value;
  node *l_val = NULL; 
  node *r_val = NULL;
};

int is_Operator(string c)
{
  if (c == "^" || c == "/" || c == "*" || c == "+" || c == "-"||c=="(")
    return 1;
  
  return 0;
}

int precedance1(string c)
{
  if (c == "^")
    return 5;
  
  if (c == "*" || c == "/")
    return 4;
  
  if (c == "+" || c == "-")
    return 2;
  
  return 1;
}



vector<string> string_par(string s)
{
  vector<string> v;
  
  for (int i=0; i<s.length(); i++)
  {
    string temp = "\0";
      
    if ((s[i] >= '0' && s[i] <= '9'))
    {     
      while (s[i] >= '0' && s[i] <= '9')
      {
        temp += s[i];
        i++;
      }
          
      i--;
    }
      
    else
      temp += s[i];
      
    if (temp == "-" && (v.empty() || is_Operator(v.back())))
      v.push_back("0");
      
    v.push_back(temp);
  }
    
  return v;
}

int precedance2(string c)
{
  if (c == "^")
    return 6;
  
  if (c == "*" || c == "/")
    return 3;
  
  if (c == "+" || c == "-")
    return 1;

  return -1;
}



struct node *construct_tree(vector<string> v)
{
  struct node *root = NULL;
  stack<struct node *> construct_tree;
  int i = 0;
    
  while (i != v.size())
  {
    if (is_Operator(v[i]))
    {
      if (construct_tree.size()< 2)
        return NULL;
            
      struct node *t1 = construct_tree.top();
      construct_tree.pop();
        
      struct node *t2 = construct_tree.top();
      construct_tree.pop();
        
      struct node *temp = new struct node;
      temp->value = v[i];
      temp->l_val = t2;
      temp->r_val = t1;
      construct_tree.push(temp);
    }

    else
    {
      struct node *temp = new struct node;
      temp->value = v[i];
      
      for(int j=0; j<v[i].length(); j++)
      {
        if (v[i][j] < '0' || v[i][j] > '9')
          return NULL;
      }
      
      construct_tree.push(temp);
    }
        
    i++;
  }
    
  if (construct_tree.size() != 1)
    return NULL;
    
  return construct_tree.top();
}
vector<string> infix_to_postfix(vector<string> v)
{
  stack<string> A;
  vector<string> post;
  
  for (int i=0; i<v.size(); i++)
  {
    if ((v[i][0] >= '0' && v[i][0] <= '9'))
      post.push_back(v[i]);
      
    else if (v[i] == "(")
      A.push("(");
      
    else if (v[i] == ")")
    {
      while (!A.empty() && A.top() != "(")
      {
        post.push_back(A.top());
        A.pop();
      }
          
      if (A.top() == "(")
        A.pop();
    }
      
    else
    {
      while (!A.empty() && precedance2(v[i]) < precedance1(A.top()))
      {
        post.push_back(A.top());
        A.pop();
      }
          
      A.push(v[i]);
    }
  }
  
  while (!A.empty())
  {
    post.push_back(A.top());
    A.pop();
  }

  return post;
}

int evaluate_construct_tree(struct node *root)
{
  string s = root->value;
  int val = 0;

  if (!is_Operator(s))
    return stoi(s);
    
  else
  {
    int lval = evaluate_construct_tree(root->l_val);
    int rval = evaluate_construct_tree(root->r_val);
        
    if (s == "+")
      val = lval + rval;
        
    else if (s == "-")
      val = lval - rval;
    
    else if (s == "*")
      val = lval * rval;
    
    else if (s == "/")
      val = lval / rval;
    
    else
      val = pow(lval, rval);
  }
    
  return val;
}


int main()
{
  int n1;
  cin >> n1;
    
  while(n1--)
  {
    int n2;
    cin >> n2;
    vector <char> v1;
    vector <int> v2;
    
    while(n2--)
    {
      string s;
      cin >> s;
      
      if(s.length() == 1)
      {
        if(s[0] >= '0' && s[0] <= '9')
          cout << s << endl;

        else
        {
          int pos = -1;

          for(int k=0; k<v1.size(); k++)
          {
            if(v1.at(k) == s[0])
              pos = k;
          }

          if(pos == -1)
            cout << "CANT BE EVALUATED\n";

          else
            cout << v2.at(pos) << endl;
        }
      }

      else
      {
        int len = s.length();
       
        if(s[1] == '=')
        {
          int pos = 1;
          v1.push_back(s[0]);
          string temp = "\0";

          for(int l=2; l<len; l++)
          {
            if((s[l] >= 'a' && s[l] <= 'z') || (s[l] >= 'A' && s[l] <= 'Z'))
            {
              int pos = 0;
              for(int m=0; m<v1.size(); m++)
              {
                if(v1.at(m) == s[l])
                  pos = m;
              }       

              ostringstream str1; 
              str1 << v2.at(pos); 
              string geek = str1.str(); 
              temp += geek; 
            }

            else
              temp += s[l];
          }

          vector<string> str = string_par(temp);
          str = infix_to_postfix(str);
          struct node *root = construct_tree(str);
          v2.push_back(evaluate_construct_tree(root));
        }

        else
        {
          string temp = "\0";
          for(int x=0; x<len; x++)
          {
            if((s[x] >= 'a' && s[x] <= 'z') || (s[x] >= 'A' && s[x] <= 'Z'))
            {
              int pos = 0;
              for(int y=0; y<v1.size(); y++)
              {
                if(v1.at(y) == s[x])
                  pos = y;
              }
              
              ostringstream str1; 
              str1 << v2.at(pos); 
              string geek = str1.str(); 
              temp += geek;
            }

            else
              temp += s[x];
          }

          vector<string> str = string_par(temp);
          str = infix_to_postfix(str);
          struct node *root = construct_tree(str);
          cout << evaluate_construct_tree(root) << endl;
        }
      }
    }
  }
  
  return 0;
}
