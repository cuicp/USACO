/*
ID: caiwush1
LANG: C++
TASK: gift1
*/
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
struct gift
{
 char name[15];
 int start;//初始要送礼的钱数
 int get;//记录收发礼物情况，不考虑初始钱数

}info[10];//建立第个人的信息

int cmp(char *g,struct gift *info,int num)
{
 int i;
 for(i = 0 ; i < num ; i++)
  if(strcmp(info[i].name,g) == 0)
   return i;
  
}//比较姓名，并返回该姓名的数组下标

int main()
{
 ifstream fcin ("gift1.in");
 ofstream fcout ("gift1.out");
 char g[15],r[10][15];//g[15]为发礼物的人，r[10][15]为相应接受礼物的人
 int i,j,k;//计数
 int num , rnum , give ;//num-NP数，rnum-接受礼物的人数，give-发出的总钱数
 fcin>>num;
 for(i = 0; i < num; i++)
  fcin>>info[i].name;
 for(i = 0; i < num; i++)
 {
  fcin>>g;
  k = cmp (g , info , num);
  fcin>>info[k].start;
  fcin>>rnum;
  if(rnum != 0)
  {
   give = info[k].start-info[k].start%rnum;
   info[k].get = info[k].get - give;
   for(j = 0; j < rnum; j++)
   {
    fcin>>r[j];
    k = cmp (r[j], info , num);
    info[k].get = info[k].get + give/rnum;
   }
  }

 }
 for( i = 0; i < num ; i++)
 {
  fcout<<info[i].name<<" "<<info[i].get<<endl;
 
 }
 return 0;
} 
 
 
