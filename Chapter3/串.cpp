/*
ID:cuichengpeng
PROG:kimbits
LANG:C++
*/ 
#include<iostream>
#include<fstream>
using namespace std;
const int M=32;
int N,L;
long long I;
long long dp[M][M];//dp[i][j]代表长度为i且1的个数不超过j的串的个数 

int main()
{
    ifstream fin("kimbits.in");
    ofstream fout("kimbits.out");
    
    int i,j;
    fin>>N>>L>>I;
    
    
    for(int i=1;i<M;++i)dp[1][i]=2;
    for(int i=1;i<M;++i)dp[i][0]=1;
    
    for(int i=2;i<M;++i)
        for(int j=1;j<M;++j)
            dp[i][j]=dp[i-1][j]+dp[i-1][j-1];

    
    for(int i=N;i>1;--i)
    {
        if(dp[i-1][L]<I)
        {
            fout<<'1';
            I-=dp[i-1][L];
            L--;
        }
        else
        {
            fout<<'0';
        }
        
    }
    fout<<I-1<<endl;
    
    
  //  system("pause");
    return 0;
}
