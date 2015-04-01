/*
ID:cuichengpeng
PROG:comehome
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<cstring> 
using namespace std;
const int MAX=52;
const int INF=100000000;
int map[MAX][MAX];
int dis[MAX];
bool vis[MAX];

void Dijkstra(int x);

int main()
{
    int i,j,k;
    ifstream fin("comehome.in");
    ofstream fout("comehome.out");
    
    for(i=0;i<MAX;++i)
        for(j=0;j<MAX;++j)
        {
            if(i==j)map[i][j]=0;
            else map[i][j]=INF;
        }

    int P;
    char tempa,tempb;
    int V1,V2,tempc;
    fin>>P;
    for(i=0;i<P;++i)
    {
        fin>>tempa>>tempb>>tempc;
        
        if(tempa>='a'&&tempa<='z')V1=tempa-'a';
        else V1=tempa-'A'+26;
        if(tempb>='a'&&tempb<='z')V2=tempb-'a'; 
        else V2=tempb-'A'+26; 
        
        map[V1][V2]=min(tempc,map[V1][V2]);
        map[V2][V1]=min(tempc,map[V1][V2]);
    }

    
    Dijkstra(51);

    int min=INF;
    char temp;
    for(i=26;i<MAX-1;++i)
    {
        if(dis[i]<min)
        {
            min=dis[i];
            temp='A'+i-26;
        }
    }

    fout<<temp<<' '<<min<<endl;
 
    return 0;
}
int Min(int dis[MAX],bool vis[MAX])
{
    int i,k,min=INF;
    for(i=0;i<MAX;++i)
        if(!vis[i]&&dis[i]<min)
        {
            k=i;
            min=dis[i];
        }
    return k;
}
void Dijkstra(int x)
{
     memset(vis,false,sizeof(vis));
     vis[x]=true;
     int i,j,k;
     
     for(i=0;i<MAX;++i)dis[i]=map[i][x];
     for(i=1;i<MAX;++i)
     {
         k=Min(dis,vis);
         vis[k]=true;
         for(j=0;j<MAX;++j)
         {
             if(!vis[j]&&(dis[j]>dis[k]+map[k][j]))
             {
                 dis[j]=dis[k]+map[k][j];
             }
         }
     }
}
