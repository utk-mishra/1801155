#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define city 11

long long int hofn(lli node,lli closed[],lli open[][city]);
void traversal(lli node,lli cost,lli closed[],lli open[][city]);

lli start;
priority_queue< pair<lli,pair<lli,pair<lli,pair<lli,lli*>>>>, vector<pair<lli,pair<lli,pair<lli,pair<lli,lli*>>>>>, greater<pair<lli,pair<lli,pair<lli,pair<lli,lli*>>>>> > p1;
long long int hofn(lli node,lli closed[],lli open[][city])
{
   closed[node]=1;
   lli mm1=100000,mm2=100000,i=1,z=0,h1=0;
   while(i<=city)
   {
      if(closed[i]==0)
    {    
      if(open[node-1][i-1]<mm1)
      mm1=open[node-1][i-1];
      if(open[i-1][start-1]<mm2)
      mm2=open[i-1][start-1];
      z=z+1;    
    }
     i++;  
   }    
   if(z>=1)  
   h1+=mm1+mm2;
   return h1;
}

void traversal(lli node,lli cost,lli closed[],lli open[][city])
{
   lli mx=-1,i=1;
    while(i<=city)
   { 
    if(closed[i]>=mx)
      mx=closed[i];
      i++;
   }
   closed[node]=mx+1;
   lli z=0;
   i=1;  
   lli closed1[city+1][city+1]={0};
   lli closed2[city+1][city+1]={0};
   vector<lli>path1[city+1];
   
   while(i<=city)
   {
      if(closed[i]==0)
    {
         lli j=1;
      while(j<=city)
      {
          closed1[i][j]=closed[j];
       
          if(closed[j]>=1)
          closed2[i][j]=1;
          else
          closed2[i][j]=0;
          j++;
      }
         
      lli heur=hofn(i,closed2[i],open);
      lli obj=heur+open[node-1][i-1]+cost;  
      p1.push({obj,{i,{node,{cost,closed1[i]}}}});          
      z=z+1;
    }
     i++;
   }
   if(z>=1)
   {pair<lli,pair<lli,pair<lli,pair<lli,lli*>>>> p2=p1.top();
    p1.pop();
    cost=p2.second.second.second.first + open[p2.second.second.first-1][p2.second.first-1];
    traversal(p2.second.first,cost,p2.second.second.second.second,open);
   }
   else
   {
     vector<pair<lli,lli>>finalpath;  
     for(lli i=1;i<=city;i++)
     finalpath.push_back({closed[i],i});
     sort(finalpath.begin(),finalpath.end());
     i=0;

     while(i<finalpath.size())
     {
      cout<<finalpath[i].second<<" ";
      i++;
    }

     cout<<"1 ";  
     cout<<"\n";
     cout<<"optimal Cost: "<<cost+open[node-1][start-1];
     return;
   }
}    

int main()
{
  start=1;
  lli closed[city+1]={0};
  lli open[][city] =
  {
        {0 , 8 ,50 ,31 ,12 ,48 ,36 , 2 , 5 ,39 ,10,},
        {8 , 0 ,38 , 9 ,33 ,37 ,22 , 6 , 4 ,14 ,32,},
        {50, 38,  0, 11, 55,  1, 23, 46, 41, 17, 52 ,},
        {31,  9, 11,  0, 44, 13, 16, 19, 25, 18, 42 ,},
        {12, 33, 55, 44,  0, 54, 53, 30, 28, 45,  7 ,},
        {48, 37,  1, 13, 54,  0, 26, 47, 40, 24, 51 ,},
        {36, 22, 23, 16, 53, 26,  0, 29, 35, 34, 49 ,},
        {2 , 6 ,46 ,19 ,30 ,47 ,29 , 0 , 3 ,27 ,15 ,},
        {5 , 4 ,41 ,25 ,28 ,40 ,35 , 3 , 0 ,20 ,21 ,},
        {39, 14, 17, 18, 45, 24, 34, 27, 20,  0, 43 ,},
        {10, 32, 52, 42,  7, 51, 49, 15, 21, 43,  0 ,}
  };
   traversal(start,0,closed,open);
  return 0;    
}
