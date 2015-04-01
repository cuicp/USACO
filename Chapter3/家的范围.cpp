/*
ID:cuichengpeng
PROG:range
LANG:C++
*/
#include<iostream>
#include<fstream>
using namespace std;
const int M=250;
int main()
{
    ifstream fin("range.in");
    ofstream fout("range.out");
    int N;
    bool map[M][M],dp1[M][M],dp2[M][M];
    
    fin>>N;
    char c;
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
        {
            fin>>c;
            map[i][j]=c-'0';
            dp1[i][j]=map[i][j];
        }
    
    int i,k1,k2,t1,t2;
    for(i=2;i<=N;++i)//枚举正方形的大小 
    {
        int count=0;
        for(k1=i-1;k1<N;++k1)
        {
            for(k2=i-1;k2<N;++k2)
            {
                dp2[k1][k2]=false;
                if(dp1[k1-1][k2-1]&&dp1[k1][k2-1]&&dp1[k1-1][k2]&&dp1[k1][k2])
                {
                    dp2[k1][k2]=true;
                    count++;
                }
            }
        }
        
        if(count==0)break;
        fout<<i<<' '<<count<<endl;
        
        for(k1=i-1;k1<N;++k1)
            for(k2=i-1;k2<N;++k2)
                dp1[k1][k2]=dp2[k1][k2]; 
    }

    //system("pause");
    return 0;
}
