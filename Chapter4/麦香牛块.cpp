/*
ID:cuichengpeng
PROG:nuggets
LANG:C++
*/ 
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
const int M=256*256;
int main()
{
    ifstream fin("nuggets.in");
    ofstream fout("nuggets.out");
    
    bool dp[M+1];
    int a[10];
    int i,j,N;
    bool flag=true;
    
    fin>>N;
    for(i=0;i<N;++i)fin>>a[i];
    
    
    //判断有没有解
    for(i=0;i<N;++i)
    {
        if(a[i]==1)
        {
            flag=false;
            break;
        }
    }
    for(i=2;i<256;++i)
    {
        for(j=0;j<N;++j)
        {
            if(a[j]%i!=0)break;
        }
        if(j>=N)
        {
            flag=false;
            break;
        }
    } 
    
    
    if(flag)//有解 
    {
        memset(dp,false,sizeof(dp));
        dp[0]=true;
        for(i=1;i<=M;++i)
        {
            for(j=0;j<N;++j)
            {
                if(i-a[j]>=0&&dp[i-a[j]]==true)
                {
                    dp[i]=true;
                    break;
                }
            }
        }

        for(int i=M;i>=1;--i)
        {
            if(dp[i]==false)
            {
                fout<<i<<endl;
                break; 
            }
        }        
    }
    else//无解 
    {
        fout<<0<<endl;
    }
    
    
    //system("pause");
    return 0;
}
