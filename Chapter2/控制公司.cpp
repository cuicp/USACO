/*
ID:cuichengpeng
PROG:concom
LANG:C++
*/
#include<iostream>
#include<fstream>
using namespace std;
const int MAX=105;
bool con[MAX][MAX];
int N,com[MAX][MAX];
int main()
{
    int i,j,k;
    ifstream fin("concom.in");
    ofstream fout("concom.out");
    
    fin>>N;
    int max_com=0,tempa,tempb,tempc;//max_com代表公司的最大编号 
    for(i=0;i<N;++i)
    {
        fin>>tempa>>tempb>>tempc;
        com[tempa][tempb]=tempc;
        max_com=max(max_com,max(tempa,tempb));           
    } 
    
    for(i=1;i<=max_com;++i)con[i][i]=true; 
    bool flag=true;
    while(flag)
    {
   
        flag=false;
        for(i=1;i<=max_com;++i)
        {
            for(j=1;j<=max_com;++j)
            {
              
                if(!con[i][j])
                {
                    if(com[i][j]>50)
                        con[i][j]=true;
                    else
                    {
                        int sum=0;
                        for(k=1;k<=max_com;++k)
                            if(con[i][k])sum+=com[k][j];
                        if(sum>50)con[i][j]=true;
                    }
                    if(con[i][j]==true) flag=true;
                }//if
            }//for
        }//for
    }//while
    
    for(i=1;i<=max_com;++i)
        for(j=1;j<=max_com;++j)
            if((i!=j)&&con[i][j])
                fout<<i<<' '<<j<<endl;

    return 0;
} 
