#include <iostream>
#include<cstdlib>
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

int Del(int x,int y)
{
	struct Node* temp=head;
	struct Node* temp2=head;
	struct Node* temp1=NULL;


	while(temp!=NULL)
	{
		if(temp->x==x && temp->y==y)
		{
			if(temp==head)
			{
				head=head->next;
				free(temp);
                return 1;
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
            return 1;
		}
	temp2=temp2->next;
	}
	cout<<"Node Not Found";
    return 0;
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
}

    string Search(int x,int y)
 {
    struct Node* temp = head;
    while (temp!= NULL)
        {
        if((temp->x)==x&&(temp->y)==y)
        {
            return "true";
        }
        temp=temp->next;
        }
    return "false";
}
    int Length()
{
    struct Node* temp = head;
    int count=0;
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
        for(int i=0; i<t; i++)
        {
            int a;
            cin>>a;
            switch(a)
            {
            case 1:
                {
                    int x,y;
                    cin>>x>>y;
                    AddFirst(x,y);
                }break;
            case 2:
                {
                    DelFirst();
                }break;
            case 3:
                {
                    int x,y;
                    cin>>x>>y;
                    Del(x,y);
                }break;
            case 4:
                {
                   float d;
                   cin>>d;
                   Search(d);
                   cout<<endl;
                }break;
            case 5:
                {
                    int x,y;
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





