/*
ID:cui chengpeng
PROG:barn1
LANG:C++
*/ 
#include<fstream>   
#include<cstring>   
#include<climits>   
using namespace std;   
//���涼�Ƿ����Ķ���   
struct data   
{   
  int where;//���նε���ֹλ��   
  int length;//���նεĳ���   
}a;   
int main()   
{   
  ifstream in("barn1.in");//������   
  ofstream out("barn1.out");//�����  

  long woods,cows,maxn,temp,min,max,length;   
//woodsľ������cowsţ����maxn���ţ������temp��ʱ������min�����С��ţ���ڵ���   
//max�������ţ���ڵ�ţ�length���ľ��ĳ���   
  min=LONG_MAX;//��ֵ��������   
  max=LONG_MIN;//��ֵ��С����   
  in >> woods >> maxn >> cows;//����   
  int peng[maxn+1];//C++&C99��׼�ɶ�̬��������   
  memset(peng,0,sizeof(peng));//��ʼ������   
  for(int i=0;i<cows;i++)//����   
    {   
       in >> temp;   
       peng[temp]=1;   
       if ( temp > max )   
         max = temp;   
       if( temp < min )   
         min = temp;   
    }   
  for(int k=1;k<woods;k++)//��n��ľ��ѭ��n-1��   
    {      
       temp=1;//��ʼ����������ν����   
       a.length=1;//Ŀǰ�ն������   
       for(int i=min;i<=max;i++)//������ն�   
           {   
             if(peng[i]==0)//0Ϊûţ��   
               temp++;   
             else if(peng[i]==1&&peng[i-1]!=1)//1Ϊ��ţ��   
                      if(temp>=a.length)//����һ��Ҫ�Ǵ��ڵ���   
                        {   
                           a.length=temp;   
                           a.where=i;   
                           temp=0;   
                        }   
             else if(peng[i]==-1)//-1Ϊ�Ѿ��п��˵Ŀն�   
                     temp=0;   
             else temp=0;   
             }   
       for(int i=a.where-1,j=a.length;j>0;i--,j--) //����Ŀն��е�   
         peng[i] = -1;   
    }   
  length=0;   
  for(int i=min;i<=max;i++)//�ӵ�һͷţס�ĵط������һͷţס�ĵط���ʼѰ��   
    if(peng[i]!=-1)//�������ط�û���жϣ���ô˵������Ҫ��ľ��   
      length++;   
  out << length << endl;//���   
  in.close();//�ر��ļ�   
  out.close();  

  return 0;   
         
}   
 
