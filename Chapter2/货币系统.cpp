/*
ID:cuichengpeng
PROG:money
LANG:C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int V,N,w[30];
long long dp[10005];
int main()
{
    int i,j;
    ifstream  fin("money.in");
    ofstream  fout("money.out");
    
    fin>>V>>N;
    
    
    for(i=1;i<=V;++i)
        fin>>w[i];
    
    for(i=1;i<=V;++i)
        for(j=1;j<=N;++j)
        {
            if(j==w[i])dp[j]+=1; 
            if(j>w[i])
            {
                dp[j]=dp[j]+dp[j-w[i]];
            }
        }
    
    fout<<dp[N]<<endl;
    
    return 0;
} 
