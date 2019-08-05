#include <iostream> 
#define ll long long
using namespace std;

struct Node  
{  
    int y; 
    int x;  
    Node *next;  
}; 

struct Node*head = NULL;

void AddFirst(int x, int y)
{
struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
new_node->x=x;
new_node->y=y;
new_node->next=head;
head=new_node;
}

int DelFirst()
{
if(head==NULL)
{
cout<<"List is Empty";
return -1;
}
Node*temp=head;
head=head->next;
free(temp);
return 0;
}

int Del(int x, int y)
{
}
int Search(float d)
{
    struct Node* temp = head; 
    while (temp!= NULL) { 
        if((temp->x)*(temp->x)+(temp->y)*(temp->y)<=d*d)
        {
            cout<<"("<<(temp->x)<<","<<(temp->y)<<")";
            
        }
        temp=temp->next;
    } 
    
    bool Search(int x,int y) 
{ 
    struct Node* temp = head; 
    while (temp!= NULL) { 
        if((temp->x)==x&&(temp->y)==y)
        {
            return true;
        }
        temp=temp->next;
    } 
    return false;
}
    int Length() 
{ 
    struct Node* temp = head; 
    int l=0;
    while (temp!= NULL) { 
        l++;
        temp=temp->next;
    } 
    return l;
    }




