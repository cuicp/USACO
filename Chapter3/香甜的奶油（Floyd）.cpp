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
vector<int>Locate;
int N,P,C;//分别为奶牛个数，牧场个数，道路条数 
void Floyd()
{
    for(int k=1;k<=P;++k)
    {
        for(int i=1;i<=P;++i)
        {
            for(int j=1;j<=P;++j)
            {
                if(G[i][j]>G[i][k]+G[k][j])
                { 
                    G[i][j]=G[j][i]=G[i][k]+G[k][j];
                } 
            }
        }
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
        for(int j=1;j<=P;++j)
        {
            if(i!=j)  G[i][j]=INF;
            else G[i][j]=0;
        }
    } 
    int A,B,lenth;
    while(fin>>A>>B>>lenth)
    {
        G[A][B]=G[B][A]=lenth;
    }
    
    
    long sum,min=1000000000;
    
    Floyd();
    for(int i=1;i<=P;++i)
    {
        sum=0;
        for(int j=0;j<Locate.size();++j)
        {
            sum+=G[Locate[j]][i];
            if(sum>=min)break;
        }
        if(sum<min)min=sum;
    }
        
    fout<<min<<endl;
    
    //system("pause");
    return 0;
} 
