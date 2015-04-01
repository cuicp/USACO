#include<iostream>
#include<fstream>
#include<queue>
#include<vector>
using namespace std;
typedef struct{
        int v;//顶点序号 
        int e;//该顶点到其邻接顶点的距离 
        }Node;
const int M=801;
const long INF=1000000000;

vector<vector<Node> >path(M);
int dist[M];
bool SPFA(int n);
int N,P,C;
int main()
{
    int cow[M];//cow[i]为第i个牧场中牛的数目 
    Node temp;
    ifstream fin("butter.txt");
    
    fin>>N>>P>>C;

    memset(cow,0,sizeof(cow));
    
    int t;
    for(int i=0;i<N;++i)
    {
            fin>>t;
            cow[t]++;
    }

    int a,b,c;
    for(int i=0;i<C;++i)
    {
            fin>>a>>b>>c;
            temp.v=b;
            temp.e=c;
            path[a].push_back(temp);

            temp.v=a;
            path[b].push_back(temp);
            
    }  
    
    long min=INF,sum,tem;
    for(int i=1;i<=P;++i)
    {
            SPFA(i);//以第i个顶点为源点，计算最短路径 
            
            sum=0;
            for(int j=1;j<=P;++j)
            {
                    sum+=cow[j]*dist[j];
            }
            
            if(sum<min)min=sum;
            
    }
    
    
    cout<<min<<endl;
     

    system("pause");
    return 0;
}


bool SPFA(int n)
{
     int i,j,k,now,l;
     Node next;
     bool vis[M];
     queue<int>Q;
     memset(dist,-1,sizeof(dist));
     memset(vis,0,sizeof(vis));
     Q.push(n);
     vis[n]=true;
     dist[n]=0;

     for(i=0;i<20000;++i)
     {
           l=Q.size();
           if(l==0)break;
           while(l--)
           {
                 now=Q.front();
                 Q.pop();
                 vis[now]=false;
                 
                 for(j=path[now].size()-1;j>=0;j--)
                 {
                       next=path[now][j];

                       if((dist[next.v]==-1)||dist[next.v]>dist[now]+next.e)
                       {
                             dist[next.v]=dist[now]+next.e;                                               
                             if(!vis[next.v])
                             {
                                 Q.push(next.v);
                                 vis[next.v]=true;
                             }//if
                       }//if                            
                 }//for
           }//while           
     }//for

     return Q.empty();
     
}
