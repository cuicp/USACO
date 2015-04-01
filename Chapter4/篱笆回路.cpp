/*
ID:cuichengpeng
PROG:fence6
LANG:C++
*/ 
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
const int INF=300000;
const int MAXN=105;
int G[MAXN][MAXN],G0[MAXN][MAXN];
bool G1[MAXN][MAXN],G2[MAXN][MAXN];
int N;
int mincircle=INF;
void Floyed()
{
    for(int k=1;k<=N;++k)
    {
        for(int i=1;i<k;++i)
        {
            for(int j=1;j<i;++j)
            {
                if((G1[k][i]==true&&G1[k][j]==true)||(G2[k][i]==true&&G2[k][j]==true))
                    continue;
                else mincircle=min(mincircle,G[i][j]+G0[j][k]+G0[k][i]);
            }
        }
               
            
        for(int i=1;i<=N;++i)
        {
            for(int j=i+1;j<=N;++j)
            {
                if(G[i][k]+G[k][j]<G[i][j])
                {
                    G[i][j]=G[i][k]+G[k][j];
                    G[j][i]=G[i][j];
                }
            }
        }
    }
}
int main()
{
    ifstream fin("fence6.in");
    ofstream fout("fence6.out");
    
    fin>>N;
    
    int a,b,c,d,temp,len[MAXN];
    for(int i=0;i<N;++i)
    {
        fin>>a>>b>>c>>d;
        len[a]=b;

        for(int j=0;j<c;++j)
        {
            fin>>temp;
            G[a][temp]=1;
            G[temp][a]=1;
            G1[a][temp]=1;
        }
        for(int j=0;j<d;++j)
        {
            fin>>temp;
            G[a][temp]=1;
            G[temp][a]=1;
            G2[a][temp]=1;
        }
    }

    
    for(int i=1;i<=N;++i)
    {
        for(int j=i+1;j<=N;++j)
        {
            if(G[i][j]==1)
            {
                G[i][j]=len[i]+len[j];
                G[j][i]=G[i][j];
            }
            else
            {
                G[i][j]=INF;
                G[j][i]=INF;
            }  
        }
    }
    for(int i=1;i<=N;++i)
    {
        for(int j=1;j<=N;++j)
        {
            G0[i][j]=G[i][j];
        }
    }
    
    
    
    Floyed();

    fout<<mincircle/2<<endl;
    
    //system("pause");
    return 0;
}
