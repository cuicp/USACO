/*
ID:cui chengpeng
PROG:castle
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
using namespace std;

bool is_wall(int x1,int y1,int x2,int y2);
void BFS();

vector<vector<int> >V;
vector<int>V1;
const int MAX=55;
int M,N;
short int map[MAX][MAX],hash[MAX][MAX];
int main()
{
    ifstream fin("castle.in");
    ofstream fout("castle.out");
    

    fin>>M>>N;
    
    for(int i=0;i<N;++i)
        for(int j=0;j<M;++j)
        {
            fin>>map[i][j];
        }
    
    BFS();//找出所有房间，并将其编号，存放在V中,
          //V[i]为该房间所包含的单位房间的编号 ,
          //hash[i][j]为编号为[i][j]的单位房间所属的房间 
    
    fout<<V.size()<<endl;
    
    int max=0;
    for(int i=0;i<V.size();++i)
    {
        if(V[i].size()>max)
            max=V[i].size();
    }
    fout<<max<<endl;
    
    //计算拆除一面墙所能获得的最大房间 
    max=0;
    int x,y;//所拆除的墙所依附的房间的编号 
    char ch;//方向 
    for(int j=0;j<M;++j)
    {
        for(int i=N-1;i>=0;--i)
        {
            if(i>0&&hash[i][j]!=hash[i-1][j])//判断上下相邻的两个单位房间之间是否为墙壁，是返回true 
            {
                if(V[hash[i][j]].size()+V[hash[i-1][j]].size()>max)
                {
                    max=V[hash[i][j]].size()+V[hash[i-1][j]].size();                                               
                    x=i;y=j;ch='N';
                }
            }    
            if(j+1<M&&hash[i][j]!=hash[i][j+1])//判断左右相邻的两个单位房间之间是否为墙壁，是返回true 
            {
                if(V[hash[i][j]].size()+V[hash[i][j+1]].size()>max)
                {
                    max=V[hash[i][j]].size()+V[hash[i][j+1]].size();
                    x=i;y=j;ch='E';
                }
            }
        }
    }
    
    fout<<max<<endl;
    fout<<x+1<<' '<<y+1<<' '<<ch<<endl;


   // system("pause");
    return 0;
}
bool is_wall(int x1,int y1,int x2,int y2)
{//判断map[x2][y2],map[x1][y1]之间是否有墙壁，有则返回true 
     if(y2-y1==1)
     {
         if(map[x1][y1]==4||map[x1][y1]==5||map[x1][y1]==6||map[x1][y1]==12
            ||map[x1][y1]==7||map[x1][y1]==13||map[x1][y1]==14||map[x1][y1]==15)
            return true;
     }
     else if(y1-y2==1)
     {
          if(is_wall(x2,y2,x2,y2+1))return true;
     }
     else if(x2-x1==1)
     {
          if(map[x1][y1]>=8)return true;
     }
     else
     {
         if(is_wall(x2,y2,x2+1,y2))return true;
     }
     return false;
}

void BFS()
{
     int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
     queue<int>Q;
     bool vis[MAX][MAX];
     for(int i=0;i<N;++i)
         for(int j=0;j<M;++j)
             vis[i][j]=false;
     for(int i=0;i<N;++i)
     {
         for(int j=0;j<M;++j)
         {
             if(vis[i][j])continue;
             
             V1.clear();
             Q.push(i*M+j);
             vis[i][j]=true;
             V1.push_back(i*M+j);
             hash[i][j]=V.size();
             while(!Q.empty())
             {
                 int temp=Q.front();
                 Q.pop();
                 int x=temp/M;
                 int y=temp%M;
                 
                 for(int k=0;k<4;++k)
                 {
                     int temp_x=x+dir[k][0];
                     int temp_y=y+dir[k][1];
                     
                     if(temp_x>=0&&temp_x<N&&temp_y>=0&&temp_y<M&&(!vis[temp_x][temp_y]))
                     {
                         if(is_wall(x,y,temp_x,temp_y))continue;
                         
                         vis[temp_x][temp_y]=true;
                         Q.push(temp_x*M+temp_y);
                         V1.push_back(temp_x*M+temp_y);
                         hash[temp_x][temp_y]=V.size();
                     }//if
                 }//for

             }//while
             V.push_back(V1);
         }//for
     }//for
}
