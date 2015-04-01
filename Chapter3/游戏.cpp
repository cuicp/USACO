#include<iostream>
#include<fstream>
using namespace std;
const int M=100;
int a[M];//记录初始数列 
int m[M][M];//m[i][j]表示以a[i]到a[j]的数列为初始条件开始游戏，玩家1可以获得的最大分数 
int sum[M][M];//sum[i][j]=a[i]+a[i+1]+~~~~~+a[j] 

int Max(int x,int y)
{
    if(m[x][y]>0)
        return m[x][y];
    
    if(x==y)
    {
         m[x][y]=a[x];
         return m[x][y];
    }
    else if(y-x==1)
    {
         m[x][y]=a[x]>a[y]?a[x]:a[y];
         return m[x][y];
    }
    else
    {
        m[x][y]=(sum[x][y-1]-Max(x,y-1)+a[y])>(sum[x+1][y]-Max(x+1,y)+a[x])?
                  (sum[x][y-1]-Max(x,y-1)+a[y]):(sum[x+1][y]-Max(x+1,y)+a[x]);
        
        return m[x][y];
        
    }
}


int main()
{
    
    ifstream fin("game1.txt");
    int N;
    
    fin>>N;
    
    for(int i=0;i<N;++i)
        fin>>a[i];
    
    for(int i=0;i<N;++i)
    {
        sum[i][i]=a[i];
        for(int j=i+1;j<N;++j)
        {
            sum[i][j]=sum[i][j-1]+a[j];
        }
    }
        
        
    int temp=Max(0,N-1);
    
    cout<<temp<<' '<<sum[0][N-1]-temp<<endl;


    system("pause");
    return 0;
}
