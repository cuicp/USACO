/*
ID:cui chengpeng
PROG:barn1
LANG:C++
*/ 
#include<fstream>   
#include<cstring>   
#include<climits>   
using namespace std;   
//上面都是烦琐的东西   
struct data   
{   
  int where;//最大空段的中止位置   
  int length;//最大空段的长度   
}a;   
int main()   
{   
  ifstream in("barn1.in");//输入流   
  ofstream out("barn1.out");//输出流  

  long woods,cows,maxn,temp,min,max,length;   
//woods木板数，cows牛数，maxn最大牛棚数，temp临时变量，min编号最小的牛所在的棚   
//max编号最大的牛所在的牛棚，length最后木板的长度   
  min=LONG_MAX;//赋值最大的整数   
  max=LONG_MIN;//赋值最小整数   
  in >> woods >> maxn >> cows;//输入   
  int peng[maxn+1];//C++&C99标准可动态定义数组   
  memset(peng,0,sizeof(peng));//初始化数组   
  for(int i=0;i<cows;i++)//输入   
    {   
       in >> temp;   
       peng[temp]=1;   
       if ( temp > max )   
         max = temp;   
       if( temp < min )   
         min = temp;   
    }   
  for(int k=1;k<woods;k++)//有n块木板循环n-1次   
    {      
       temp=1;//初始化。。无所谓的了   
       a.length=1;//目前空段最长长度   
       for(int i=min;i<=max;i++)//查找最长空段   
           {   
             if(peng[i]==0)//0为没牛的   
               temp++;   
             else if(peng[i]==1&&peng[i-1]!=1)//1为有牛的   
                      if(temp>=a.length)//这里一定要是大于等于   
                        {   
                           a.length=temp;   
                           a.where=i;   
                           temp=0;   
                        }   
             else if(peng[i]==-1)//-1为已经切开了的空段   
                     temp=0;   
             else temp=0;   
             }   
       for(int i=a.where-1,j=a.length;j>0;i--,j--) //将最长的空段切掉   
         peng[i] = -1;   
    }   
  length=0;   
  for(int i=min;i<=max;i++)//从第一头牛住的地方到最后一头牛住的地方开始寻找   
    if(peng[i]!=-1)//如果这个地方没被切断，那么说明这里要塞木板   
      length++;   
  out << length << endl;//输出   
  in.close();//关闭文件   
  out.close();  

  return 0;   
         
}   
 
