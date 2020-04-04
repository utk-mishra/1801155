#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<pair<int,char>> tree;

int hash1[100000];
int index_of_parent(int index);
int human_turn(int left);
int ai_turn(int left);
int index_of_child(int index);
int insert_in_tree(int n,int index,int heur);
int index_of_main_parent(int index,int initial_index)
{
	int index1;
	while(index!=initial_index)
	{
		index1=index;
		index=index_of_parent(index);
	}
	return index1;
}

int ai_turn(int left,int index)
{
	int heur;
	tree.pb(make_pair(index,'a'));
	hash1[index]=left;
	for(int i=13;i>=-1;i--)
	{

		heur=5+(4*i);
		//cout<<heur<<" ";
		if(heur<left)

			break;
	}
	index=0;
	index=insert_in_tree(left,index,heur);
	//cout<<endl<<"computer picks "<<left-hash1[index]<<" sticks"<<endl<<endl;
	left=hash1[index];
	memset(hash1,'\0',sizeof(hash1));
	tree.clear();
	return left;
}

int human_turn(int left)
{
	int pick;
//	left=human_turn(left);
	cout<<"sticks left:"<<left<<endl;
	cout<<"how many stick you want to pick up-";
	cin>>pick;
	if(pick>3 || pick==0)
	{
		cout<<"error!!you must have to chose atleast one stick and not more than 3"<<endl<<endl;
		left=human_turn(left);
	}
	else
	{
		left=left-pick;
	}
	return left;
}

int index_of_parent(int index)
{
	int a=index%3;
	int p_index=index/3;
	if(a==0)
	{
		p_index--;
	}
	return p_index;
}

int index_of_child(int index)
{
	return ((3*index)+1);
}

int insert_in_tree(int n,int index,int heur)
{
	int initial_index=index;
	int e=n,k,chance;
	int j=index;
	int ind=0;
	k=1;
	int pe=pow(3,k);
	while(1)
	{
		for(int i=1;i<=3;i++)
		{
			ind++;
			index++;
			e=n-i;
			if(e>=heur)
			{
				if(k%2!=0)
				{
					tree.pb(make_pair(index,'b'));
					hash1[index]=e;
					if(e==heur)
						return index_of_main_parent(index,initial_index);
				}
				else if(k%2==0)
				{
					tree.pb(make_pair(index,'a'));
					hash1[index]=e;
				}
			}
		}
		j++;
		n=hash1[j];
		if(ind==pe)
		{
			ind=0;
			k++;
			pe=pow(3,k);
		}
	}
}

void print_state()
{
	auto it=tree.begin();
	int i=0;
	while(it!=tree.end())
	{
		cout<<tree[i].first<<" "<<tree[i].second<<endl;
		it++;
		i++;
	}
}
int main()
{
	int a,b,flag=0,left_old;
	int player;
	int n=13,pick;
	char chance;
	cout<<"press 1 for AI vs AI"<<endl<<"press 2 for AI vs HUMAN"<<endl;
	cin>>player;
	if(player==2)
	{
		cout<<"how many stick you want to play with---";
		cin>>n;
		int heur;
		int initial_index=1,index=0,index1,e=0,left=n;
		cout<<"game starts"<<endl<<"press 1 for HEADS"<<endl<<"press 2 for TAIL"<<endl;
		srand(time(0));
		cin>>a;
		b=rand()%10;
		b=b%2;
		if(a==b)                                                            //human won the toss
		{
			flag=1;
			cout<<"you won the toss!   your chance first"<<endl;
		}
		else if(a!=b)
		{
			flag=0;
			cout<<"you loose the toss!   computer chance first"<<endl;
		}
		while(1)
		{
			if(left==1)
			{
				cout<<"you loose!"<<endl;
				break;
			}
			if(flag==1)
			{
				flag=0;
				left=human_turn(left);
				if(left==1)
				{
					cout<<"congrats!!you win"<<endl;
					break;
				}
				index=0;
			}
			if(flag==0)
			{
				left_old=left;
				left=ai_turn(left,index);
				cout<<"Computer picks "<<left_old-left<<" sticks"<<endl<<endl;
				flag=1;
			}

		}
	}
	if(player==1)
	{
		cout<<"how many stick you want to play with---";
		cin>>n;
		int heur;
		int initial_index=1,index=0,index1,e=0,left=n;
		cout<<"enter for toss"<<endl<<endl;
		cin>>chance;
		srand(time(0));
		a=rand()%10;
		a=a%2;
		b=rand()%10;
		b=b%2;
	//	cout<<a<<" "<<b;
		if(a==b)                                                            //human won the toss
		{
			flag=1;
			cout<<"AI-1 won the toss!AI-1 chance first  press enter"<<endl;
		}
		else if(a!=b)
		{
			flag=0;
			cout<<"AI-2 won the toss!AI-2 chance first press enter"<<endl;
		}
		while(1)
		{
			if(left==1)
			{
				cout<<"AI-2 win"<<endl;
				break;
			}
			if(flag==1)
			{
				left_old=left;
				flag=0;
//				cout<<"sticks left:"<<left<<endl;
				left=ai_turn(left,index);
				cout<<"AI-1 picks "<<left_old-left<<" sticks"<<endl; 
				cout<<"sticks left:"<<left<<endl;

				if(left==1)
				{
					cout<<"AI-1 win"<<endl;
					break;
				}
				cin>>chance;
				index=0;
			}
			if(flag==0)
			{
				left_old=left;
//				cout<<"sticks left:"<<left<<endl;
				left=ai_turn(left,index);
				cout<<"AI-2 picks "<<left_old-left<<" sticks"<<endl;
				cout<<"sticks left:"<<left<<endl;

				flag=1;
				cin>>chance;
			}

		}
	}
}
