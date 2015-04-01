/*
ID:cuichengpeng
PROG:cowtour
LANG:C++
*/ 
#include<iostream>
#include<fstream>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring> 
using namespace std;
const int MAX=150;
const double INF=1000000000;
char map[MAX][MAX];//记录牧区的联通性 
double  G[MAX][MAX];//记录牧区间的最短距离 
int point[MAX][2];//牧区坐标 
int N;
vector<int> BFS(bool vis[MAX],int n);

void Folyd();
double max(double a,double b,double c){return max(c,max(a,b));};
//计算连通分量v中的距离v[n]结点的最大距离 
double max(vector<int> v,int n)
{
    int i;
    double max_lenth=0;
    for(i=0;i<v.size();++i)
    {
        if(i!=n&&G[v[i]][v[n]]>max_lenth)
            max_lenth=G[v[i]][v[n]]; 
    }
    return max_lenth;
}
//计算连通分量v的直径 
double max(vector<int> v)
{
    int i,j;
    double max_lenth=0;
    for(i=0;i<v.size();++i)
        for(j=i+1;j<v.size();++j)
            if(G[v[i]][v[j]]>max_lenth)
                max_lenth=G[v[i]][v[j]];
                
    return max_lenth;
}
int main()
{
    int i,j,m,n;
    ifstream fin("cowtour.in");
   // ofstream fout("cowtour.out");
    FILE* fp=fopen("cowtour.out","w");

    fin>>N;
    for(i=0;i<N;++i)  fin>>point[i][0]>>point[i][1];

    double d,d1,d2,d3;
    for(i=0;i<N;++i)
        for(j=0;j<N;++j)
        { 
            fin>>map[i][j];
            if(map[i][j]=='1')
            {
                d1=point[i][0]-point[j][0];
                d2=point[i][1]-point[j][1];
                G[i][j]=sqrt(d1*d1+d2*d2);
            }
            else G[i][j]=INF;
        } 
    
    //求出所有连通分量 
    bool vis[MAX];
    vector<vector<int> >V;
    vector<int>tempv;
    memset(vis,false,sizeof(vis));
    for(i=0;i<N;++i)
    {
        if(!vis[i])
        {
            tempv=BFS(vis,i);
            V.push_back(tempv);
        }
        tempv.clear();
    }
    
    
    Folyd(); 
    //计算最小直径 
    double min_d=1000000000;
    for(i=0;i<V.size();++i)
        for(j=i+1;j<V.size();++j)
        {
            for(m=0;m<V[i].size();++m)
                for(n=0;n<V[j].size();++n)
                {
                    d1=point[V[i][m]][0]-point[V[j][n]][0];
                    d2=point[V[i][m]][1]-point[V[j][n]][1];
                    d3=sqrt(d1*d1+d2*d2);
                    
                    d=max(d3+max(V[i],m)+max(V[j],n),max(V[i]),max(V[j]));
                    if(d<min_d)min_d=d;
                } 
        }

    fprintf(fp,"%.6f\n",min_d);
    
  //  system("pause");
    return 0;
}
vector<int> BFS(bool vis[MAX],int n)
{
     queue<int>Q;
     vector<int>tempv;
     Q.push(n);
     vis[n]=true;
     
     int v;
     while(!Q.empty())
     {
         v=Q.front();
         tempv.push_back(v);
         Q.pop();
         for(int i=0;i<N;++i)
         {
             if(!vis[i]&&map[v][i]=='1')
             {
                 Q.push(i);
                 vis[i]=true;
             }
         }
     }
     return tempv;

}
void Folyd()
{
     for(int k=0;k<N;++k)
         for(int i=0;i<N;++i)
             for(int j=0;j<N;++j)
             {
                 if((G[i][k]==INF)||(G[k][j]==INF))continue;
                 if((G[i][j]==INF)||(G[i][j])>G[i][k]+G[k][j])
                 {
                       G[i][j]=G[i][k]+G[k][j];                                       
                 }
             }
     
}
