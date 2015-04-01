/*
ID:cuichengpeng
PROG:shopping
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
const int INF=10000000;
const int M=5;
int cost[M][M][M][M][M];
bool can(vector<vector<int> >&need,vector<vector<int> >&yh,int k);
bool can(vector<vector<int> >&need,vector<vector<int> >&yh);
void mul(vector<vector<int> >&need,vector<vector<int> >&yh,int k);
void add(vector<vector<int> >&need,vector<vector<int> >&yh,int k);
void change(vector<vector<int> >&need,vector<vector<int> >&yh);//对商品编号进行转换 
int dfs(vector<vector<int> >need,vector<vector<int> >yh)
{   
    if(!can(need,yh))//不能够进行优惠 
    {    
        int sum=0;
        for(int i=0;i<need.size();++i)
            sum+=need[i][1]*need[i][2];
        return sum;
    }
    
    int t[5]={0};
    for(int i=0;i<need.size();++i)t[i]=need[i][1];
    if(cost[t[0]][t[1]][t[2]][t[3]][t[4]]!=0)
        return cost[t[0]][t[1]][t[2]][t[3]][t[4]];
    
    //枚举每种优惠
    int min=INF; 
    for(int i=0;i<yh.size();++i)
    {
        if(can(need,yh,i))//能用第i种方式进行优惠
        {
            mul(need,yh,i);//减少需求量 
            int min_cost=yh[i][yh[i].size()-1]+dfs(need,yh);
            if(min_cost<min)min=min_cost;
            add(need,yh,i);//恢复需求量 
        } 
    } 
    cost[t[0]][t[1]][t[2]][t[3]][t[4]]=min;
    return min;
}

int main()
{
    ifstream fin("shopping.txt");
    ofstream fout("shopping.out");
    vector<vector<int> >yh;//优惠方案
    vector<int>temp; 
    vector<vector<int> >need;
    int i,j,s,b,n,c,k,p;

    fin>>s;
    for(i=0;i<s;++i)
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
/*    
    for(int i=0;i<yh.size();++i)
    {
        for(int j=0;j<yh[i].size();++j)cout<<yh[i][j]<<' ';
        cout<<endl;
    }
    system("pause");
 */  

    cout<<dfs(need,yh)<<endl;
    system("pause");
    return 0;
}
bool can(vector<vector<int> >&need,vector<vector<int> >&yh,int k)
{
    int i;
    for(i=0;i<yh[k].size()-1;i+=2)
    {
        if(yh[k][i+1]>need[yh[k][i]][1])break;
    }
    if(i<yh[k].size()-1)return false;
    return true;
}
bool can(vector<vector<int> >&need,vector<vector<int> >&yh)
{
    for(int i=0;i<yh.size();++i)
        if(can(need,yh,i))return true;
    return false;
}
void mul(vector<vector<int> >&need,vector<vector<int> >&yh,int k)
{
    for(int i=0;i<yh[k].size()-1;i+=2)
        need[yh[k][i]][1]-=yh[k][i+1];
}
void add(vector<vector<int> >&need,vector<vector<int> >&yh,int k)
{
    for(int i=0;i<yh[k].size()-1;i+=2)
        need[yh[k][i]][1]+=yh[k][i+1];
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
