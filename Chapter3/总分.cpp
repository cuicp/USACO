#include<iostream>
#include<fstream>
using namespace std;
int Max(int a,int b){return a>b?a:b;}

const int MAX=10001;

int main()
{
    int M,N,value[MAX],time[MAX];//value��time�ֱ�����i��������ķ����ͺ�ʱ 
    
    int dp[2][MAX]; 
    
    ifstream fin("inflate.txt");
    
    fin>>M>>N;
    
    for(int i=1;i<=N;++i)fin>>value[i]>>time[i];
    

    
    for(int i=1;i<=N;++i)//��Ŀ����
        for(int j=1;j<=M;++j)//ʱ�����
        {
             if(j<time[i])continue;
             if(i%2==0)
             {
                  dp[0][j]=Max(dp[1][j],dp[0][j-time[i]]+value[i]);     
             }
             else 
             {
                  dp[1][j]=Max(dp[0][j],dp[1][j-time[i]]+value[i]);
             }
        }
        

    cout<<dp[0][M]<<endl;
    
    system("pause");
    return 0;
}
