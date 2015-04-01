#include<iostream>
#include<fstream>
using namespace std;

int Prim();//返回图MAP最小生成树的长度 
int MinLenth(int dis[],bool vis[]);//返回当前从S集到V-S集的最短路径所依附的V-S集中的顶点序号

const int MAX=1000000;
const int M=100;
int MAP[M][M];
int N;

int main()
{
    ifstream fin("agrinet.txt");
    
    fin>>N;
    
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
        {
                fin>>MAP[i][j];
        }
    
    cout<<Prim()<<endl;
    
    system("pause");
    return 0;
}

int Prim()
{
    bool vis[M];
    int dis[M],n,min_lenth=0;
    
    
    vis[0]=true;
    dis[0]=0;
    for(int i=1;i<N;++i)
    {
         vis[i]=false;
         dis[i]=MAX;
         dis[i]=MAP[0][i];   
    }
    
    for(int i=1;i<N;++i)
    {
         n=MinLenth(dis,vis);//返回当前从S集到V-S集的最短路径所依附的V-S集中的顶点序号 
         
         min_lenth+=dis[n];
         vis[n]=true;//将n顶点加入到 S集中
         
         for(int j=0;j<N;++j)//更新dis 
         {
             if(!vis[j])
             {
                 if(MAP[n][j]<dis[j])dis[j]=MAP[n][j];
             }
         }                             
    }
    
    return min_lenth;
} 
int MinLenth(int dis[],bool vis[])
{
    int min=MAX,n;
    for(int i=0;i<N;++i)
    {
        if(!vis[i])
        {
             if(dis[i]<min)
             {
                 min=dis[i];
                 n=i;          
             }      
        }
     
    }
    
    return n;
}

