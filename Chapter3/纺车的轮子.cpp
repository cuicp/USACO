#include<iostream>
#include<fstream>
using namespace std;
typedef struct{
        int start;
        int end;
        int lenth;
        }Node;
        
//若当前状态符合题意返回true，否则返回false 
bool IsAnswer(Node w[][180],int n[]);
//对每个轮子进行转动,每次转动一秒
void Trun(Node w[][180],int v[],int n[]);
//检验在m，n之间有没有可以穿过2-4号轮子的光线 s，e分别为第一个轮子中缺口的开始值与结束值 
bool Check(int s,int e,Node w[][180],int n[]);

int main()
{
    Node w[5][180];//记录第n个轮子的缺口信息 
    int v[5];//记录每个轮子的转动速度 
    int n[5];//记录每个轮子的缺口个数 
    
    ifstream fin("spin.txt");
    
    for(int i=0;i<5;++i)
    {
         fin>>v[i]>>n[i];
         for(int j=0;j<n[i];++j)
         {
             fin>>w[i][j].start>>w[i][j].lenth;
             w[i][j].end=(w[i][j].start+w[i][j].lenth)%360;
         }
    }
    
    
    int t;
    for(t=0;t<360;++t)
    {
          //若寻找到答案，退出循环 
          if(IsAnswer(w,n)) 
          {
              break;
          }
          //对每个轮子进行转动,每次转动一秒
          Trun(w,v,n);
    }
    
    
    cout<<t<<endl; 
    

    system("pause");
    return 0;
}

bool IsAnswer(Node w[][180],int n[])
{
     int i;
     
     //以第一个轮子的n[0]个缺口为标准检验当前状态是否符合题意 
     for(i=0;i<n[0];++i)
     {
         if(w[0][i].start>=w[0][i].end)//0点分布在标准轮的缺口端点之间时
         {
             if(Check(w[0][i].start,359,w,n)||Check(0,w[0][i].end,w,n))
                 return true;
         }
         else//0点分布在标准轮的缺口端点之外时
         {
             if(Check(w[0][i].start,w[0][i].end,w,n))
                 return true;
         }//if
         
     }//for
     
     return false;

} 
void Trun(Node w[][180],int v[],int n[])
{
     for(int i=0;i<5;++i)
     {
         for(int j=0;j<n[i];++j)
         {
              w[i][j].start=(w[i][j].start+v[i])%360;
              w[i][j].end=(w[i][j].end+v[i])%360;
         }
     } 
} 
bool Check(int s,int e,Node w[][180],int n[])
{
     int t,i,j;
     for(t=s;t<=e;++t)//t为光线 
     {
          for(i=1;i<5;++i)//试探其余四个轮子 
          {
               for(j=0;j<n[i];++j)//检测第i个轮子是否符合题意 
               {
                   if(w[i][j].start>w[i][j].end)
                   {
                        if((t>=w[i][j].start&&t<360)||(t>=0&&t<w[i][j].end))
                            break;                        
                   }
                   else 
                   {
                        if(t>=w[i][j].start&&t<=w[i][j].end)
                            break;
                   }//if
               }//for
               
               if(j>=n[i])break;
               
          }//for
          
          if(i>=5)return true;

     }//for

     return false;
}
