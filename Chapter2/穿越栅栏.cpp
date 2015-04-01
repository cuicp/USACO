/*
ID:cuichengpeng
PROG:maze1
LANG:C++
*/ 
#include<iostream>
#include<fstream>
#include<queue> 
#include<cstring>
using namespace std;
typedef struct{
        int x;
        int y;
        int distance;
}point;
const int MAXW=80,MAXH=203;
char map[MAXH][MAXW];
int dis1[MAXH][MAXW];
int dis2[MAXH][MAXW];
int W,H;
point Exit[2];

void minDistance(point Point,int dis[][MAXW]);//计算 Point到map各个点的最短距离 
int main()
{
    int i,j,k;
    ifstream fin("maze1.in");
    ofstream fout("maze1.out");

    fin>>W>>H;

    W=2*W+1;
    H=2*H+1;
    fin.getline(map[0],79);
    for(i=0;i<H;++i)fin.getline(map[i],79);
    
    k=0;
    for(i=0;i<W;++i)
        if(map[0][i]==' '||map[H-1][i]==' ')
        {
            if(map[0][i]==' ')
            {
                Exit[k].x=0;
                Exit[k++].y=i;
            }
            if(map[H-1][i]==' ')
            {
                Exit[k].x=H-1;
                Exit[k++].y=i;
            }
        }
    for(i=0;i<H;++i)
        if(map[i][0]==' '||map[i][W-1]==' ')
        {
            if(map[i][0]==' ')
            {
                Exit[k].x=i;
                Exit[k++].y=0;
            }
            if(map[i][W-1]==' ')
            {
                Exit[k].x=i;
                Exit[k++].y=W-1;
            }
        }

    Exit[0].distance=0;
    Exit[1].distance=0;
    minDistance(Exit[0],dis1);
    minDistance(Exit[1],dis2);
    
    int max_dis=0;
    for(i=0;i<MAXH;++i)
        for(j=0;j<MAXW;++j)
        {
            dis1[i][j]=(min(dis1[i][j],dis2[i][j])+1)/2;
            if(dis1[i][j]>max_dis)max_dis=dis1[i][j];
        }

    fout<<max_dis<<endl;
    
   // system("pause");
    return 0;
}
void minDistance(point Point,int dis[][MAXW])
{
     int i,dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
     bool vis[MAXH][MAXW];
     point temp_point;
     queue<point>Q;
     for(i=0;i<H;++i)memset(vis[i],0,sizeof(vis[i]));
     Q.push(Point);
     vis[Point.x][Point.y]=true;
     while(!Q.empty())
     {
         Point=Q.front();
         Q.pop();
         dis[Point.x][Point.y]=Point.distance;

         for(i=0;i<4;++i)
         {
             temp_point.x=Point.x+dir[i][0];
             temp_point.y=Point.y+dir[i][1];
             temp_point.distance=Point.distance+1;
            
             if(temp_point.x>=0&&temp_point.x<H&&temp_point.y>=0&&temp_point.y<W&&(!vis[temp_point.x][temp_point.y])&&(map[temp_point.x][temp_point.y]==' '))
             { 
                 Q.push(temp_point);
                 vis[temp_point.x][temp_point.y]=true;
             }
         }
         
     }
}
