/*
ID:cuichengpeng
PROG:ditch
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<cstring> 
using namespace std;
const int MAXM=205;
const int MAXN=205;
const int INF=100000000;
int flow[MAXM][MAXM],N,M;
vector<vector<int> >edge(MAXM);//边集 
int deep[MAXN];//各节点的层次 
bool bfs();//对图进行分层，返回false时表示流不肯能再增大
int dinic(int s,int maxf);//s为发点，maxf为s能够提供
                      //的最大流量，返回可以到达汇点的流量 

int main()
{
    ifstream fin("ditch.in");
    ofstream fout("ditch.out");
    
    int v1,v2,f;
    fin>>N>>M;
    for(int i=0;i<N;++i)
    {
        fin>>v1>>v2>>f;
        flow[v1][v2]+=f;
        edge[v1].push_back(v2);
        edge[v2].push_back(v1);
    }
 
    int max_flow=0;
    while(bfs())
    {
        max_flow+=dinic(1,INF);
    }
    fout<<max_flow<<endl;

    //system("pause");
    return 0;
}
bool bfs()//对图进行分层，返回false时表示流不肯能再增大
{
     memset(deep,-1,sizeof(deep));
     queue<int>Q;
     deep[1]=0;//源点深度为0 
     Q.push(1);//源点加入队列 
     
     while(!Q.empty())
     {
         int k=Q.front();
         Q.pop();
         for(int i=0;i<edge[k].size();++i)
         {
             if(deep[edge[k][i]]<0&&flow[k][edge[k][i]]>0)
             {
                 deep[edge[k][i]]=deep[k]+1;
                 Q.push(edge[k][i]);
             }
         }
     } 
     
     if(deep[M]<0)return false;//找到最大流，算法结束 
     return true;
} 

//s为发点，maxf为s能够提供的最大流量，返回可以到达汇点的流量 
int dinic(int s,int maxf)
{
    if(s==M)return maxf;
    
    int maxfff=maxf;//从s到汇点可以增加的流 
    for(int i=0;i<edge[s].size();++i)
    {
        if(deep[edge[s][i]]==deep[s]+1&&flow[s][edge[s][i]]>0)
        {
            int a=dinic(edge[s][i],min(maxf,flow[s][edge[s][i]]));
            maxf-=a;
            flow[s][edge[s][i]]-=a;
            flow[edge[s][i]][s]+=a; 
        }
    } 
    
    return maxfff-maxf;
} 
                      
