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
 int start;//��ʼҪ�����Ǯ��
 int get;//��¼�շ���������������ǳ�ʼǮ��

}info[10];//�����ڸ��˵���Ϣ

int cmp(char *g,struct gift *info,int num)
{
 int i;
 for(i = 0 ; i < num ; i++)
  if(strcmp(info[i].name,g) == 0)
   return i;
  
}//�Ƚ������������ظ������������±�

int main()
{
 ifstream fcin ("gift1.in");
 ofstream fcout ("gift1.out");
 char g[15],r[10][15];//g[15]Ϊ��������ˣ�r[10][15]Ϊ��Ӧ�����������
 int i,j,k;//����
 int num , rnum , give ;//num-NP����rnum-���������������give-��������Ǯ��
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
 
 
