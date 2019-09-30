#include <iostream> 
#include <stack> 
#include <stdlib.h> 
#define lli long long int
using namespace std; 
  
struct Dot 
{ 
    lli x, y; 
}; 
  

Dot p0; 
  

Dot nextToTop(stack<Dot> &S) 
{ 
    Dot p = S.top(); 
    S.pop(); 
    Dot res = S.top(); 
    S.push(p); 
    return res; 
} 
  

int swap(Dot &p1, Dot &p2) 
{ 
    Dot temp = p1; 
    p1 = p2; 
    p2 = temp; 
} 

lli distSq(Dot p1, Dot p2) 
{ 
    return (p1.x - p2.x)*(p1.x - p2.x) + 
          (p1.y - p2.y)*(p1.y - p2.y); 
} 

int config(Dot p, Dot q, Dot r) 
{ 
    lli val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
  
    if (val == 0) return 0;   
    return (val > 0)? 1: 2; 
} 
 
int compare(const void *vp1, const void *vp2) 
{ 
   Dot *p1 = (Dot *)vp1; 
   Dot *p2 = (Dot *)vp2; 
  
   int o = config(p0, *p1, *p2); 
   if (o == 0) 
     return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1; 
  
   return (o == 2)? -1: 1; 
} 
 
void convexHull(Dot Dots[], int n) 
{ 

   lli ymin = Dots[0].y, min = 0; 
   for (lli i = 1; i < n; i++) 
   { 
     lli y = Dots[i].y; 
     if ((y < ymin) || (ymin == y && 
         Dots[i].x < Dots[min].x)) 
        ymin = Dots[i].y, min = i; 
   } 
   swap(Dots[0], Dots[min]); 
 
   p0 = Dots[0]; 
   qsort(&Dots[1], n-1, sizeof(Dot), compare); 
 
   lli m = 1;
   for (lli i=1; i<n; i++) 
   {  
       while (i < n-1 && config(p0, Dots[i], 
                                    Dots[i+1]) == 0) 
          i++; 
  
  
       Dots[m] = Dots[i]; 
       m++; 
   } 
  
   
   if (m < 3) return; 
  
   stack<Dot> S; 
   S.push(Dots[0]); 
   S.push(Dots[1]); 
   S.push(Dots[2]); 
  
   for (lli i = 3; i < m; i++) 
   { 
    
      while (config(nextToTop(S), S.top(), Dots[i]) != 2) 
         S.pop(); 
      S.push(Dots[i]); 
   } 
 
   while (!S.empty()) 
   { 
       Dot p = S.top(); 
       cout << "(" << p.x << ", " << p.y <<")" << endl; 
       S.pop(); 
   } 
} 
 
int main() 
{ 
    long long int t;
    cin>>t;
    Dot Dots[t];
    for(long long int i=0; i<t; i++)
    {
      cin>>Dots[i].x>>Dots[i].y;
    }

    int n = sizeof(Dots)/sizeof(Dots[0]); 
    convexHull(Dots, n); 
    return 0; 
} 
