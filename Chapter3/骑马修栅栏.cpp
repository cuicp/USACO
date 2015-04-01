#include<iostream>
#include<fstream>
#include<vector>
#include<stack>
using namespace std;
const int M=501;
void DFS(int n,int depth);//n为顶点个数 ,depth为搜索深度 
void Output();
int F;
vector<vector<int> >G(M);
stack<int>S;
bool vis[M][M],flag=false;
int main()
{
    int count[M];
    ifstream fin("fence.txt");
    
    fin>>F;
    
    
    memset(count,0,sizeof(count));
    int a,b,max_v=0;//max_v记录顶点个数 
    for(int i=0;i<F;++i)
    {
            fin>>a>>b;
            count[a]++;//count[i]用来记录第i个顶点的度数 
            count[b]++;
            
            if(max_v<(a>b?a:b))max_v=a>b?a:b;
            
            G[a].push_back(b);
            G[b].push_back(a);
    }
    for(int i=1;i<=max_v;++i)sort(G[i].begin(),G[i].end());
    
    for(int i=1;i<=max_v;++i)
        for(int j=1;j<=max_v;++j)
        {
                vis[i][j]=false;
        }
        
    
    int start=1,count_1=0;
    for(int i=1;i<=max_v;++i) 
    {
        if(count[i]%2==1)
        {
             count_1++;//度为奇数的顶点的个数
             if(count_1<=1) start=i;  
        }
    }
    
    
    if(count_1==1||count_1==0)DFS(1,0);
    else DFS(start,0);
    
    
    system("pause");
    return 0;
}
void Output()
{
     stack<int>S1;
     while(!S.empty())
     {
         S1.push(S.top());
         S.pop();
     }
     while(!S1.empty())
     {
         cout<<S1.top()<<endl;
         S1.pop();
     }
}

void DFS(int n,int depth)
{
    S.push(n);
    
    if(depth==F)
    {
       flag=true;
       Output();
       return ;
    }

    int t=G[n].size();
    for(int i=0;i<t;++i)
    {
        if(flag) return;
        if(!vis[n][G[n][i]])
        {
              vis[n][G[n][i]]=true;
              vis[G[n][i]][n]=true;
              DFS(G[n][i],depth+1);   
              vis[n][G[n][i]]=false;
              vis[G[n][i]][n]=false;    
        }
    }
} 


