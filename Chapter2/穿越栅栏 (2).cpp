/*
ID:cui chengpeng
PROG:maze1
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<queue>
using namespace std;

typedef struct LNode{
        int n;
        struct LNode* next;
        }LNode;
//表示顶点的结构体    
typedef struct{
        int n;//顶点序号 
        int step;//从该顶点到目标顶点的最短距离 
        LNode* first;
        }Peak;
        
void BFS(int n);//计算从第n个顶点到其他顶点的最短距离 
int Min(int a,int b){return a<b?a:b;}

const int MAXW=38;
const int MAXH=100;
char MAP[MAXW][MAXH];//存放原始地图 
Peak V[3800];//存放所有顶点 
LNode* p[3800];//对应第i个顶点的邻接链表的为指针 
bool vis[3800];
int dis[3800];//dis[i]表示第i个顶点到 第一个出口的距离 


int main()
{
    ifstream fin("maze1.in");
    ofstream fout("maze1.out");
    int W,H,W1,H1,max,EXIT[2];char ch;

    fin>>W>>H;
    max=W*H;  
      
    W1=2*W+1;
    H1=2*H+1;
      
    for(int i=0;i<max;++i)
    {
        V[i].n=i;
        V[i].first=(LNode*)malloc(sizeof(LNode));
        V[i].first->next=(LNode*)malloc(sizeof(LNode));
        p[i]=V[i].first->next;
    }
    
    
    fin.getline(MAP[0],80);
    for(int i=0;i<H1;++i)fin.getline(MAP[i],80);
    
    
    //寻找出口 
    int t=0;
    for(int i=0;i<W1;++i)
    {
        if(MAP[0][i]==' ')
        {
            EXIT[t]=i/2;
            ++t;                
        }
        if(MAP[H1-1][i]==' ')
        {
            EXIT[t]=W*(H-1)+i/2;
            ++t;               
        }    
    }
    for(int i=0;i<H1;++i)
    {
        if(MAP[i][0]==' ')
        {
            EXIT[t]=W*(i/2);
            ++t;                
        }
        if(MAP[i][W1-1]==' ')
        {
            EXIT[t]=W*(i/2+1)-1;
            ++t;                
        }    
    }
    fin.close();

    //计算图的所有结点之间的连通性 （两点连通性是指相邻且之间不存在障碍）并将其存储在a中 
    for(int i=0;i<max;++i)
    {
        int x=i/W;
        int y=i%W;
            
        if((2*y+3<W1)&&(MAP[2*x+1][2*y+2]==' '))
        {
            p[i]->n=i+1;
            p[i]->next=(LNode*)malloc(sizeof(LNode));
            p[i]=p[i]->next;
            p[i+1]->n=i;
            p[i+1]->next=(LNode*)malloc(sizeof(LNode));
            p[i+1]=p[i+1]->next;
        } 
        if((2*x+3<H1)&&(MAP[2*x+2][2*y+1]==' '))
        {   
            p[i]->n=i+W; 
            p[i]->next=(LNode*)malloc(sizeof(LNode));
            p[i]=p[i]->next;
            p[i+W]->n=i;
            p[i+W]->next=(LNode*)malloc(sizeof(LNode));
            p[i+W]=p[i+W]->next;
        } 
    }
    
    for(int i=0;i<max;++i)vis[i]=false;
    BFS(EXIT[0]);
    for(int i=0;i<max;++i)  dis[i]=V[i].step;
    for(int i=0;i<max;++i)vis[i]=false;
    BFS(EXIT[1]);
    
    int temp=0;
    for(int i=0;i<max;++i)
    {
         if(Min(dis[i],V[i].step)>temp)
         {
              temp=Min(dis[i],V[i].step);                         
         }
    }
    
    fout<<temp<<endl;
       
       
    return 0;    
}
void BFS(int n)
{
     queue<int>Q;
     
     vis[n]=true;
     V[n].step=1;
     Q.push(n);
     
     while(!Q.empty())
     {
         int m=Q.front();
         Q.pop();
         
         dis[m]=V[m].step;
         LNode* q;
         q=V[m].first->next;

         while(q!=p[m])
         {          
             if(!vis[q->n])
             {
                 V[q->n].step=V[m].step+1;
                 vis[q->n]=true;
                 Q.push(q->n);      
             }
             q=q->next;                   
         }//while                 
     }//while
}//DFS
