#include<iostream>
#include<fstream>
using namespace std;
const int M=5;
const int N=100;  
const int INF=1000000;
int Min(int a1,int a2,int a3,int a4,int a5);
int way[N][M*2+1];//way[i]为第i中优惠方式的具体优惠方案 
int cost[N];//N[i]为第i种优惠方式所需的钱 
int P[N][M];//P[i][j]表示第i种 优惠方式所需要第j种商品的数量
int dp[M][M][M][M][M];//dp[a1][a2][a3][a4][a5]表示买a1件1，a2件2，~~~a5件5最少用多少钱 
int main()
{
    int s,n;
    ifstream fin("shopping.txt");
    fin>>s;
    for(int i=0;i<s;++i)
    {
         fin>>way[i][0];
         for(int j=1;j<=2*way[i][0];j+=2)
             fin>>way[i][j]>>way[i][j+1];
         fin>>cost[i];
    } 
    
    int b;
    int a[M][3];//a[i][0],为第i种商品的编号，a[i][1]为该种商品的需求量,
               //a[i][2]为该种商品的原价 
    for(int i=0;i<M;++i)memset(a[i],0,sizeof(a[i]));
    fin>>b;
    for(int i=0;i<b;++i)
    {
        fin>>a[i][0]>>a[i][1]>>a[i][2];
    }
    
    for(int i=0;i<b;++i)//枚举每一种所需的商品的编号 
    {
         for(int j=0;j<M;++j)//枚举全部优惠方案
         {
             for(int k=1;k<=2*way[j][0];k+=2)//处理每种优惠方案信息 
             {
                   if(a[i][0]==way[j][k])
                       P[j][i]=way[j][k+1];
             } 
         } 
    }
    
    
    int K1=a[0][1],K2=a[1][1],K3=a[2][1],K4=a[3][1],K5=a[4][1];
    int b1,b2,b3,b4,b5,min;
    for(int a1=0;a1<=K1;++a1)
        for(int a2=0;a2<=K2;++a2)
            for(int a3=0;a3<=K3;++a3)
                for(int a4=0;a4<=K4;++a4)
                    for(int a5=0;a5<=K5;++a5)
                    {
                        min=a1*a[0][2]+a2*a[1][2]+a3*a[2][2]+a4*a[3][2]+a5*a[4][2];
                        for(int i=0;i<s;++i)
                        {
                            b1=a1-P[i][0];
                            b2=a2-P[i][1];
                            b3=a3-P[i][2];
                            b4=a4-P[i][3];
                            b5=a5-P[i][4];
                            
                            if(b1>=0&&b2>=0&&b3>=0&&b4>=0&&b5>=0)
                            {
                                if(dp[b1][b2][b3][b4][b5]+cost[i]<min)
                                    min=dp[b1][b2][b3][b4][b5]+cost[i];                             
                            }
                        }
                        dp[a1][a2][a3][a4][a5]=min;
                    }
    cout<<dp[K1][K2][K3][K4][K5]<<endl;        
    
    
    system("pause");
    return 0;
}
int Min(int a1,int a2,int a3,int a4,int a5)
{
    int min;
    min=a1<a2?a1:a2;
    if(a3<min)min=a3;
    if(a4<min)min=a4;
    if(a5<min)min=a5;
    
    return min;
}
