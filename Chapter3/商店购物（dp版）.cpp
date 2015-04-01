/*
ID:cuichengpeng
PROG:shopping
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<vector> 
#include<cstring>
using namespace std;
const int INF=10000000;
const int M=6;
int dp[M][M][M][M][M];

/***************************************** 
判断当前的需求量能不能运用第i如果能返回运
用此种 优惠最少用多少钱若不能返回-1 
*****************************************/ 
int can(int s[],vector<int>yh_i)
{
    int s1[5];
    memset(s1,0,sizeof(s1));
    for(int i=0;i<yh_i.size()-1;i+=2)
    {
        s1[yh_i[i]]=yh_i[i+1];
    }   
    
    for(int i=0;i<5;++i)
    {
        if(s[i]<s1[i])return -1;
    }
    
    return yh_i[yh_i.size()-1]+
        dp[s[0]-s1[0]][s[1]-s1[1]][s[2]-s1[2]][s[3]-s1[3]][s[4]-s1[4]];
}

int min_cost(int s[],vector<vector<int> >&yh,vector<vector<int> >&need)
{ 
    //不用优惠
    int min_cost=0;
    for(int i=0;i<need.size();++i)
        min_cost+=s[i]*need[i][2];
        
    //用优惠 
    for(int i=0;i<yh.size();++i)
    {
        int k=can(s,yh[i]);
        if(k!=-1)//能用第i种个优惠
        {
            min_cost=min(min_cost,k);
        }    
    }
    return min_cost;
}
void change(vector<vector<int> >&need,vector<vector<int> >&yh)
{
    for(int i=0;i<need.size();++i)
    {
        int temp=need[i][0];
        need[i][0]=i;
        for(int j=0;j<yh.size();++j)
        {
            for(int k=0;k<yh[j].size()-1;k+=2)
            {
                if(yh[j][k]==temp)yh[j][k]=i;
            }
        }
    }
}

int main()
{
    ifstream fin("shopping.in");
    ofstream fout("shopping.out");
    vector<vector<int> >yh;//优惠方案
    vector<int>temp; 
    vector<vector<int> >need;
    int i,j,m,b,n,c,k,p;

    fin>>m;
    for(i=0;i<m;++i)
    {
        fin>>n;
        for(j=0;j<2*n+1;++j)
        {
            fin>>c;
            temp.push_back(c);
        }
        yh.push_back(temp);
        temp.clear();
    }
    fin>>b;
    for(i=0;i<b;++i)
    {
        for(j=0;j<3;++j)
        {
            fin>>c;
            temp.push_back(c);
        }
        need.push_back(temp);
        temp.clear(); 
    }
    
    change(need,yh); 
    int s[5]={0},s1[5]={0},t[5]={0};
    for(i=0;i<need.size();++i)t[i]=need[i][1];
    
    for(s[0]=0;s[0]<=t[0];++s[0])
        for(s[1]=0;s[1]<=t[1];++s[1])
            for(s[2]=0;s[2]<=t[2];++s[2])
                for(s[3]=0;s[3]<=t[3];++s[3]) 
                    for(s[4]=0;s[4]<=t[4];++s[4])
                    {
                        dp[s[0]][s[1]][s[2]][s[3]][s[4]]=min_cost(s,yh,need);    
                    }
    fout<<dp[t[0]][t[1]][t[2]][t[3]][t[4]]<<endl;
    //system("pause");
    return 0;
}
