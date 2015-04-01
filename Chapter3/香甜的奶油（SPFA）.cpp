/*
ID:cuichengpeng
PROG:butter
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<queue>
#include<vector>
using namespace std;
const long INF=1000000000;
const int M=802;

int G[M][M];
vector<vector<int> >Edge(M); 
vector<int>Locate;
long dis[M];
int N,P,C;//分别为奶牛个数，牧场个数，道路条数 

void SPFA(int s)//以s为源点计算最短路径 
{
    bool vis[P+1];
    for(int i=1;i<=P;++i)
    {
        dis[i]=INF;
        vis[i]=false;
    }
        
    queue<int>Q;
    dis[s]=0;
    vis[s]=true;
    Q.push(s);
    
    while(!Q.empty())
    {
        int temp=Q.front();
        Q.pop();
        for(int i=0;i<Edge[temp].size();++i)
        {
            if(dis[temp]+G[temp][Edge[temp][i]]<dis[Edge[temp][i]])
            {
                dis[Edge[temp][i]]=dis[temp]+G[temp][Edge[temp][i]];
            
                if(!vis[Edge[temp][i]])
                {
                    Q.push(Edge[temp][i]);
                    vis[Edge[temp][i]]=true;
                }
            }
        }
        vis[temp]=false;   
    }
}

int main()
{
    ifstream fin("butter.in");
    ofstream fout("butter.out");
    
    
    fin>>N>>P>>C;
    
    int temp;
    for(int i=0;i<N;++i)
    {
        fin>>temp;
        Locate.push_back(temp);
    }
    
    for(int i=1;i<=P;++i)
    {
        for(int j=1;j<=i;++j)
        {
            if(i!=j) G[i][j]=G[j][i]=INF;
            else G[i][j]=0;
        }
    } 
    
    int A,B,lenth;
    while(fin>>A>>B>>lenth)
    {
        G[A][B]=G[B][A]=lenth;
        Edge[A].push_back(B);
        Edge[B].push_back(A);
    }
    
    
    float sum,min=1000000000;
    
    for(int i=1;i<=P;++i)
    {
        SPFA(i);
        for(int k=1;k<=P;++k)
            G[i][k]=G[k][i]=dis[k];
            
        sum=0;
        for(int j=0;j<Locate.size();++j)
        {
            sum+=dis[Locate[j]];
            if(sum>=min)break;
        }
        if(sum<min)min=sum;
    }
        
    fout<<min<<endl;
    
  //  system("pause");
    return 0;
} 
