#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define population 8

vector<vector<int>> form_population;
vector<int> stu_marks;
set<int> gr_leader;
vector<vector<int>> groups;
void printgroups();
void random(int k,int n,int i)
{
        int e,m;
        mt19937 mt_rand (time(0));
        while(gr_leader.size()!=k)
        {
                e=rand()%n;
                gr_leader.insert(stu_marks[e]);
        }
        m=0;
        vector<int> temp;
        for(auto j=gr_leader.begin();j!=gr_leader.end();j++)
        {
         //       cout<<*j<<" ";
                temp.pb(*j);
                //groups[i].pb(*j);
                //cout<<groups[i][m]<<" ";
                m++;
        }
        groups.pb(temp);
        for(auto j=groups[i].begin();j!=groups[i].end();j++)
        {
              //  cout<<*j<<" ";
        }
}

int fitness(int k,int n,int i)
{
    int dis[k],fitne=0,in,e;
    int j=0;
    //cout<<"ad";
    for(in=0;in<n;in++)
    {
        //cout<<"sdf";
        auto gr=groups[i].begin();
      //  cout<<stu_marks[in]<<" ";
        for(j=0;j<k;j++)
        {
            dis[j]=stu_marks[in]-(*gr);
            //cout<<dis[j];
            //cout<<"dis="<<dis[j]<<" ";
            dis[j]=dis[j]*dis[j];
            //i++;
            //cout<<dis[j]<<" ";
            gr++;
        }
        e=1000020;
        for(j=0;j<k;j++)
        {
            if(dis[j]<e)
            {
                e=dis[j];
            }
        }
        //cout<<"e="<<e<<" "<<endl;
        fitne=fitne+e;
    }
//    cout<<"fitness="<<fitne;
    return fitne;
}

int assign(int k,int n)
{
	int si=groups.size();
	int cons=1000011;
	int assigned;
	int fina_assign[k][n];
	int index[k];

	auto mnmn=stu_marks.begin();
	for(int i=0;i<k;i++)
	{
//		fina_assign[i].pb(k);
		index[i]=0;
	}
	int dist[k];
	for(int i=0;i<n;i++)
	{
		cons=383893;
		int mark_st=*mnmn;
		for(int j=0;j<k;j++)
		{
			dist[j]=groups[si-1][j]-mark_st;
			dist[j]=dist[j]*dist[j];
			if(dist[j]<cons)
			{
				cons=dist[j];
				assigned=j;
			}
		}
		fina_assign[assigned][index[assigned]]=mark_st;
		index[assigned]++;
		mnmn++;
	}
	cout<<endl<<endl;
	for(int i=0;i<k;i++)
	{
	//	cout<<"groups\n";
		cout<<groups[si-1][i]<<"->";
	        int j=0;
		for(j=0;j<index[i];j++)
		{
			cout<<fina_assign[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

int crossover(int e_1,int e_2,int k,int g1)
{
    gr_leader.clear();
    //mt19937 mt_rand(time(NULL));
    int in=k-1,i;
    //int g1=rand()%in;
    //gr_leader.clear();
    /*for(i=0;i<k;i++)
    {
        cout<<form_population[e_1][i]<<" ";
    }
    cout<<endl;
    for(i=0;i<k;i++)
    {
        cout<<form_population[e_2][i]<<" ";
    }
    cout<<endl;
    
    */
    for(i=0;i<=g1;i++)
    {
        gr_leader.insert(form_population[e_1][i]);
    }
    /*cout<<"groups1"<<endl;
    printgroups();*/
    for(int j=i;j<k;j++)
    {
        gr_leader.insert(form_population[e_2][j]);
    }
    /*for(auto it1=gr_leader.begin();it1!=gr_leader.end();it1++)
    {
        // cout<<"groups:"<<*it1<<" ";
        cout<<*it1<<" ";
    }*/
    /*cout<<"groups2"<<endl;
    printgroups();*/
    //cout<<endl;
    if(gr_leader.size()!=k)
    {
      //  cout<<"sd"<<endl;
        return 0;
    }
    else if(gr_leader.size()==k)
    {
    //cout<<"g1:"<<g1<<endl;
    vector<int> temp1;
    /*cout<<"groups3"<<endl;
    printgroups();*/
    for(auto it1=gr_leader.begin();it1!=gr_leader.end();it1++)
    {
         temp1.pb(*it1);
    }
       //.. for(
    groups.pb(temp1);
    /*cout<<"groups"<<endl;
    printgroups();
    cout<<endl;*/
    //groups.pb(temp1);
    return 1;
}
}

void printgroups(int k,int n)
{
	int si=groups.size();
	cout<<endl<<"groups leaders-";
        for(int j=0;j<groups[si-1].size();j++)
        {
            cout<<groups[si-1][j]<<" ";
        }
	assign(k,n);
}

int main()
{
        int n,k,e;
        cout<<"enter value of n:";
        cin>>n;
        cout<<"how many groups:";
        cin>>k;
        cout<<"enter marks:";
        for(int i=0;i<n;i++)
        {
                cin>>e;
                stu_marks.pb(e);
        }
 //       cout<<endl;
        vector<pair<int,int>> f;
        for(int i=0;i<population;i++)
        {
                mt19937 mt_rand ( time (NULL));
                random(k,n,i);
   //             cout<<endl;
                //int z=fitness(k,n,i);
                //f.pb(make_pair(z,i));
                gr_leader.clear();
        }
       // printgroups();
    for(int count1=0;count1<50;count1++)
    {
        for(int i=0;i<population;i++)
        {
            int z=fitness(k,n,i);
            f.pb(make_pair(z,i));
        }
        sort(f.rbegin(),f.rend());
        int i=0;
     /*   while(i!=population)
        {
            cout<<f[i].first<<" "<<f[i].second<<endl;
            i++;
        }*/
        mt19937 mt_rand (time(0));
        for(i=0;i<population;i++)
        {
            e=rand()%360;
           // cout<<e<<" ";
            if(e>=0 && e<=10)
            {
                int indexno=f[0].second;
                form_population.pb(groups[indexno]);
            }
            else if(e>=11 && e<=30)
            {
                int indexno=f[1].second;
                form_population.pb(groups[indexno]);
            }
            else if(e>=31 && e<=60)
            {
                int indexno=f[2].second;
                form_population.pb(groups[indexno]);
            }
            else if(e>=61 && e<=100)
            {
                int indexno=f[3].second;
                form_population.pb(groups[indexno]);
            }
            else if(e>=101 && e<=150)
            {
                int indexno=f[2].second;
                form_population.pb(groups[indexno]);
            }
            else if(e>=151 && e<=210)
            {
                int indexno=f[2].second;
                form_population.pb(groups[indexno]);
            }
            else if(e>=211 && e<=280)
            {
                int indexno=f[2].second;
                form_population.pb(groups[indexno]);
            }
            else if(e>=281 && e<=360)
            {
                int indexno=f[2].second;
                form_population.pb(groups[indexno]);
            }
        }
        auto it=form_population.begin();
      /*  cout<<endl<<"population"<<endl;
            for(i=0;i<4;i++)
            {
                for(int j=0;j<3;j++)
                {
                    cout<<form_population[i][j]<<" ";
                }
                cout<<endl;
            }*/
                //crossover starts here
            int cur_pop=0;
            for(i=0;i<4;i++)
            {
                groups[i].clear();
            }
            groups.clear();
            ///cout<<endl<<"group initial"<<endl;
            //printgroups();
            //cout<<endl;
            int indexno1=0,indexno2=1;
            while(cur_pop<population)
            {
                mt19937 mt_rand(time(NULL));
                int e_1=rand()%4;
                int e_2=rand()%4;
                int indexno=k-1;
                indexno=rand()%indexno;
         //       cout<<"e_1:"<<e_1<<" "<<"e_2:"<<e_2<<" g1:"<<indexno<<endl;
                int tell1=crossover(e_1,e_2,k,indexno);
                int tell2=crossover(e_2,e_1,k,indexno);
           //     cout<<tell1<<" "<<tell2<<endl;
                if(tell1==0 || tell2==0)
                {
                    groups.erase(groups.begin()+indexno1);
                    //groups.erase(groups.begin()+indexno2);
               //     cout<<"tell"<<endl;
             //       printgroups();
                 //   cout<<indexno1<<" "<<indexno2<<"kjbf"<<endl;
                    continue;
                }
                else if(tell1==1 && tell2==1)
                {
                   //     cout<<"correct   e_1:"<<e_1<<" e_2:"<<e_2<<endl;
                        indexno1=indexno+2;
                        indexno2=3;
                        gr_leader.clear();         
                        cur_pop=cur_pop+2;
                }
            }
            //printgroups();
        }
    printgroups(k,n);
}

