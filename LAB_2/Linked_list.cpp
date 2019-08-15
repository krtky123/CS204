#include <iostream>
#include <cstdlib>
#define ll long long
using namespace std;

struct Node
{
    ll int x;
    ll int y;
    Node *next;
};

struct Node*head = NULL;

void AddFirst(ll int x, ll int y)
{
struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
new_node->x=x;
new_node->y=y;
new_node->next=head;
head=new_node;
}

void DelFirst()
{
if(head==NULL)
{
cout<<"-1"<<endl;
return;
}
Node*temp=head;
head=head->next;
free(temp);
return ;
}

void Del(ll int x,ll int y)
{
	struct Node* temp=head;
	struct Node* temp2=head;
	struct Node* temp1=NULL;

    if(temp==NULL)
    {
        cout<<"-1"<<endl;
    }
	while(temp!=NULL)
	{
		if(temp->x==x && temp->y==y)
		{
			if(temp==head)
			{
				head=head->next;
				free(temp);
			}
		}
	temp=temp->next;
	}

	while(temp2->next!=NULL)
	{
		if(temp2->next->x==x && temp2->next->y==y)
		{
			temp1=temp2->next;
			temp2->next=temp2->next->next;
			free(temp1);
            return;
		}
	temp2=temp2->next;
	}
	cout<<"-1"<<endl;
    return;
}
void Search(long double d)
{
   ll int count=0;
    struct Node* temp = head;
    while (temp!= NULL) {
        if((temp->x)*(temp->x)+(temp->y)*(temp->y)<=d*d)
        {
           // cout<<"("<<(temp->x)<<","<<(temp->y)<<")";
           count++;
           cout<<count;

        }
        temp=temp->next;
    }
    if(count==0)
    {
        cout<<"-1"<<endl;
    }

}

    string Search(ll int x,ll int y)
 {
    struct Node* temp = head;
    while (temp!= NULL)
        {
        if((temp->x)==x&&(temp->y)==y)
        {
            return "True";
        }
        temp=temp->next;
        }
    return "False";
}
    int Length()
{
    struct Node* temp = head;
    ll int count=0;
    while (temp!= NULL) {
        count++;
        temp=temp->next;
    }
    return count;
    }

    int main()
    {
        ll t;
        cin>>t;
        for(ll int i=0; i<t; i++)
        {
            int a;
            cin>>a;
            switch(a)
            {
            case 1:
                {
                    ll int x,y;
                    cin>>x>>y;
                    AddFirst(x,y);
                }break;
            case 2:
                {
                    DelFirst();
                }break;
            case 3:
                {
                    ll int x,y;
                    cin>>x>>y;
                    Del(x,y);
                }break;
            case 4:
                {
                   long double d;
                   cin>>d;
                   Search(d);
                   cout<<endl;
                }break;
            case 5:
                {
                    ll int x,y;
                    cin>>x>>y;
                    cout<<Search(x,y)<<endl;
                }break;
            case 6:
                {
                 cout<<Length()<<endl;
                }break;

            }
        }
        return 0;
    }






