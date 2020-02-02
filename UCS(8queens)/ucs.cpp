#include<iostream>
#include <cstdlib>
using namespace std;
struct node{
	int arr[8][8];
	int row;
	int column;
	struct node *next;
};

void print(struct node *a)
{
	int i=0;
	while(i<8)
	{
		int j=0;
		while(j<8)
		{
			cout<<a->arr[i][j]<<" ";
			j++;
		}
		cout<<"\n";
		i++;
	}
	cout<<"\n";
}

bool valid(struct node *a){
	int i=0,j;
	while(i<(a->row))
	{
		if(a->arr[i][a->column]==1)
		{
			return false;
		}
		i++;
	}
	i=a->row-1;
	j=a->column-1;
	while(i>=0&&j>=0)
	{
		if(a->arr[i][j]==1)
		{
			return false;
		}
		i--;
		j--;

	}
	i=a->row-1;
	j=a->column+1;
	while(i>=0&&j>=0)
	{
		if(a->arr[i][j]==1)
		{
			return false;
		}
		j++;
		i--;
	}
	return true;
}

void Queen8(struct node *a){
	struct node *last;
	last=(struct node *)malloc(sizeof(struct node));
	int t=1,i,j;
	while(a->row<8)
	{
		i=0;
		while(i<8)
		{
			struct node *b;
			b=(struct node *)malloc(sizeof(struct node));
			j=0;
			while(j<8)
			{
				int k=0;
				while(k<8)
				{
					b->arr[j][k]=a->arr[j][k];
					k++;
				}
				j++;
			}
			b->row=a->row+1;
			b->column=i;
			b->arr[b->row][i]=1;
			if(t==1&&valid(b)){
				a->next=b;
				last=b;
				last->next=NULL;
				t=0;
			}else if(valid(b)){
				last->next=b;
				last=b;
				last->next=NULL;
			}
			i++;
		}
		if(a->next!=NULL)
			a=a->next;
	
		if(a->row==7){
			print(a);
			return;
		}
	}
}

int main()
{
	struct node *a;
	a=(struct node *)malloc(sizeof(struct node));
	int i=0;
	int j=0;
	while(i<8)
	{
		while(j<8)
		{
			a->arr[i][j]=0;
			j++;
		}
		i++;
	}
	a->row=-1;
	a->next=NULL;
	Queen8(a);
	return 0;
}
