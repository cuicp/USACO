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
vector<vector<int> >edge(MAXM);//�߼� 
int deep[MAXN];//���ڵ�Ĳ�� 
bool bfs();//��ͼ���зֲ㣬����falseʱ��ʾ��������������
int dinic(int s,int maxf);//sΪ���㣬maxfΪs�ܹ��ṩ
                      //��������������ؿ��Ե���������� 

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
bool bfs()//��ͼ���зֲ㣬����falseʱ��ʾ��������������
{
     memset(deep,-1,sizeof(deep));
     queue<int>Q;
     deep[1]=0;//Դ�����Ϊ0 
     Q.push(1);//Դ�������� 
     
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
     
     if(deep[M]<0)return false;//�ҵ���������㷨���� 
     return true;
} 

//sΪ���㣬maxfΪs�ܹ��ṩ��������������ؿ��Ե���������� 
int dinic(int s,int maxf)
{
    if(s==M)return maxf;
    
    int maxfff=maxf;//��s�����������ӵ��� 
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
                      
