#include<iostream>
#include<fstream>
#include<queue>
using namespace std;
typedef struct{
        int x;
        int y;
        int step;
        }Node;
const int M=40;
const int N=26;
const int S=1000;
const int INF=10000000;
int station[S][2];
int R,C;

inline int Max(int a,int b){return a>b?a:b;}
int dist(int x1,int y1,int x2,int y2);
Node turn(Node T,int n);

int main()
{
    ifstream fin("camelot.txt");
    
    fin>>R>>C;
    
    char temp_a;
    int  temp_b;
    
    fin>>temp_a>>temp_b;
    
    station[0][0]=temp_a-'A';
    station[0][1]=temp_b-1;
     
    int num=1;
    while(fin>>temp_a>>temp_b)
    {
        station[num][0]=temp_a-'A';
        station[num][1]=temp_b-1;
        num++;
    }

    int min=INF;
    for(int i=0;i<R;++i)
        for(int j=0;j<C;++j)//枚举所有格子作为汇点 
        {
            int sum=0;
            for(int k=1;k<num;++k)
                sum+=dist(station[k][0],station[k][1],i,j);
                
                
            int temp_min=INF;
            for(int l=1;l<=num;++l)//枚举接国王的骑士 
            {
                int x1=station[0][0]-2;
                int x2=station[0][0]+2;
                int y1=station[0][1]-2;
                int y2=station[0][1]+2;
                
                x1=x1>0?x1:0;
                x2=x2<R?x2:R;
                y1=y1>0?y1:0;
                y2=y2<C?y2:C;
                
                int temp;
                for(int t1=x1;t1<=x2;++t1)
                    for(int t2=y1;t2<=y2;++t2)
                    {
                        temp=dist(station[l][0],station[l][1],t1,t2)+
                             Max(abs(t1-station[0][0]),abs(t2-station[0][1]))+
                             dist(t1,t2,i,j)-
                             dist(station[l][0],station[l][1],i,j);
                        
                        if(temp<temp_min)temp_min=temp;
                    }
                
            }
            
            sum+=temp_min;
            
            if(sum<min)min=sum;
            
        }


    cout<<min<<endl;
    
    
    system("pause");
    return 0;
}
int dist(int x1,int y1,int x2,int y2)
{
    bool vis[M][N];
    queue<Node>Q;
    Node temp,T;

    if(x1==x2&&y1==y2)return 0;
    
    for(int i=0;i<M;++i)memset(vis[i],false,sizeof(vis[i]));
    
    T.x=x1;
    T.y=y1;
    T.step=0;
    
    Q.push(T);
    vis[T.x][T.y]=true;
    
    while(!Q.empty())
    {
         T=Q.front();
         Q.pop();
         
         for(int i=1;i<=8;++i)
         {
             temp=turn(T,i);
             if(temp.x>=0&&temp.y>=0&&temp.x<R&&temp.y<C&&(!vis[temp.x][temp.y]))
             {
                 if(temp.x==x2&&temp.y==y2)return temp.step;
                 else
                 {
                     vis[temp.x][temp.y]=true;
                     Q.push(temp); 
                 }
             }

         }                 
    }
    
    return INF;
}
Node turn(Node T,int n)
{
     Node P;
     if(n==1)
     {
          P.x=T.x+1;
          P.y=T.y+2;   
     }
     else if(n==2)
     {
          P.x=T.x+1;
          P.y=T.y-2;
     }
     else if(n==3)
     {
          P.x=T.x-1;
          P.y=T.y+2;
     }
     else if(n==4)
     {
          P.x=T.x-1;
          P.y=T.y-2;
     }
     else if(n==5)
     {
          P.x=T.x+2;
          P.y=T.y+1;
     }
     else if(n==6)
     {
          P.x+T.x+2;
          P.y=T.y-1;
     }
     else if(n==7)
     {
          P.x=T.x-2;
          P.y=T.y+1;
     }
     else
     {
         P.x=T.x-2;
         P.y=T.y-1;
     }
     P.step=T.step+1;
     
     return P;
}
