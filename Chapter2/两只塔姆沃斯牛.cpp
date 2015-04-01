/*
ID:cuichengpeng
PROG:ttwo
LANG:C++
*/
#include<iostream>
#include<fstream>
using namespace std;
typedef struct
{
    int x;//横坐标 
    int y;//纵坐标 
    int dirction;//方向0，1,2,3分别代表上，右，下，左 
}status;

const int MAX=10;
const int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};//上右下左;
char map[MAX][MAX];
status farmer,cow;

void Move();//移动函数，用来更新farmer和cow的status 

int main()
{
    int i,j;
    ifstream fin("ttwo.in");
    ofstream fout("ttwo.out");

    int count=2;
    for(i=0;i<MAX;++i)
        for(j=0;j<MAX;++j)
        {  
            fin>>map[i][j];
            if(map[i][j]=='F'){farmer.x=i,farmer.y=j,farmer.dirction=0;}
            if(map[i][j]=='C'){cow.x=i,cow.y=j,cow.dirction=0;}
            if(map[i][j]!='*')  ++count;
        }

    int max_status=count*count*4;
    int step=0;
    for(i=0;i<max_status;++i)
    {
        ++step;    
        Move();
        if((farmer.x==cow.x)&&(farmer.y==cow.y))break;
    }
    
    if(i<max_status)  fout<<step<<endl;
    else fout<<0<<endl;

    return 0;
}
void Move()
{
     int i,tempx,tempy;
     
     //更新牛的状态 
     tempx=cow.x+dir[cow.dirction][0];
     tempy=cow.y+dir[cow.dirction][1];
     if((tempx>=0&&tempx<10)&&(tempy>=0&&tempy<10)&&(map[tempx][tempy]!='*'))
     {
         cow.x=tempx;
         cow.y=tempy;
     }
     else cow.dirction=(cow.dirction+1)%4;
     
     //更新农民的状态 
     tempx=farmer.x+dir[farmer.dirction][0];
     tempy=farmer.y+dir[farmer.dirction][1];
     if((tempx>=0&&tempx<10)&&(tempy>=0&&tempy<10)&&(map[tempx][tempy]!='*'))
     {
         farmer.x=tempx;
         farmer.y=tempy;
     }
     else farmer.dirction=(farmer.dirction+1)%4;
     
} 
