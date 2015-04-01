/*
ID:cuichengpeng
PROG:stamps
LANG:C++
*/ 
#include<iostream>
#include<fstream>
#include<algorithm> 
using namespace std;
const int MAX_MONEY=2000000; 
const int MAXN=50;
int K,N,w[MAXN],dp[MAX_MONEY];//dp[i]为构造面值i元所需的最少有票数 

int Min(int n);//返回dp[i]; 
int main()
{
    int i,j;
    ifstream fin("stamps.in");
    ofstream fout("stamps.out");
    
    fin>>K>>N;
    for(i=0;i<N;++i)fin>>w[i];

    sort(w,w+N);
    dp[0]=0;
    for(i=1;;++i)
    {
        dp[i]=Min(i);
        if(dp[i]>K)break;
    }
    
    fout<<i-1<<endl;
    
  //  system("pause");
    return 0;
}

int Min(int n)//返回dp[i]
{
    int i,min=10000000;

    for(int i=0;i<N;++i)
    {
        if((n>=w[i])&&(dp[w[i]]+dp[n-w[i]]<min))
            min=dp[n-w[i]]+1;
    }
    
    return min;
}
