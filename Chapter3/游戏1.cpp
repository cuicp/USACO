/*
ID:cuichengpeng
PROG:game1
LANG:C++
*/
#include<iostream>
#include<fstream>
using namespace std;
const int M=100;
enum Player{me,other};
int N,a[M];

int main()
{
    ifstream fin("game1.in");
    ofstream fout("game1.out");

    fin>>N;
    for(int i=0;i<N;++i)
        fin>>a[i];

    int dp[N][N],sum[N][N];
    for(int i=0;i<N;++i)
    {
        for(int j=i;j<N;++j)
        {
            sum[i][j]=0;
            for(int k=i;k<=j;++k)
                sum[i][j]+=a[k];
        }
    }
    
    for(int i=0;i<N;++i)dp[i][i]=a[i];
    for(int i=1;i<N;++i)
    {
        for(int j=0;j<N-i;++j)
        {
            dp[j][j+i]=max(a[j]+sum[j+1][j+i]-dp[j+1][j+i],a[j+i]+sum[j][j+i-1]-dp[j][j+i-1]);
        }
    }

    fout<<dp[0][N-1]<<' '<<sum[0][N-1]-dp[0][N-1]<<endl;
    //system("pause");
    return 0;
}
