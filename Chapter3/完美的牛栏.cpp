/*
ID:cuichengpeng
PROG:stall4
LANG:C++
*/ 
#include<iostream>
#include<fstream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
const int MAXN=410;
const int INF=10000000;
short flow[MAXN][MAXN];
int N,M;
vector<vector<int> >edge(410);

int deep[MAXN];//���ڵ�Ĳ�� 
bool bfs();//��ͼ���зֲ㣬����falseʱ��ʾ��������������
int dinic(int s,int maxf);//sΪ���㣬maxfΪs�ܹ��ṩ
                      //��������������ؿ��Ե���������� 
int main()
{
    ifstream fin("stall4.in");
    ofstream fout("stall4.out");
    
    fin>>N>>M;
    int a,b;
  
    //����Դ��ĳ�ʼ�� 
    for(int i=1;i<=N;++i)
    {
        edge[1]. push_back(i+1);
        edge[i+1].push_back(1);
        flow[1][i+1]=1;
    }
    //�������ĳ�ʼ��
    for(int i=1;i<=M;++i)
    {
        edge[2+M+N].push_back(1+N+i);
        edge[1+N+i].push_back(2+M+N);
        flow[1+N+i][2+M+N]=1;
    }
     
    //�м��ĳ�ʼ�� 
    for(int i=0;i<N;++i)
    {
        fin>>a;
        for(int j=0;j<a;++j)
        {
            fin>>b;
            edge[i+2].push_back(1+N+b);
            edge[1+N+b].push_back(i+2);
            flow[i+2][1+N+b]=1;
        }
    }
    
    
    int maxflow=0;
    
    while(bfs())
    {
        maxflow+=dinic(1,INF);
    }
    fout<<maxflow<<endl;
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
     
     if(deep[M+N+2]<0)return false;//�ҵ���������㷨���� 
     return true;
} 

//sΪ���㣬maxfΪs�ܹ��ṩ��������������ؿ��Ե���������� 
int dinic(int s,int maxf)
{
    if(s==M+N+2)return maxf;
    
    int maxfff=maxf;//��s�����������ӵ��� 
    for(int i=0;i<edge[s].size();++i)
    {
        if(deep[edge[s][i]]==deep[s]+1&&flow[s][edge[s][i]]>0)
        {
            int mf=(maxf<flow[s][edge[s][i]])?maxf:flow[s][edge[s][i]];
            int a=dinic(edge[s][i],mf);
            maxf-=a;
            flow[s][edge[s][i]]-=a;
            flow[edge[s][i]][s]+=a; 
        }
    } 
    
    return maxfff-maxf;
} 
        
