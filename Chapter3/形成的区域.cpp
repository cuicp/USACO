/*
ID:cuichengpeng
PROG:rect1
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
typedef struct{
        int x1,y1;//���½����� 
        int x2,y2;//���Ͻ����� 
        int c;//��ɫ 
        }Node;
        
const int M=1000;
//a��Ϊ��ɢ����ľ��ε����λ�ã�squareΪ������
//Ϣ��x��y�ֱ�Ϊ��ɢ�����εıߵ�λ��,nΪx,y��ά
//�����ú���������a�о��ε���ɫ�����洢��a�С� 
void SetColour(int a[][2*M],Node square[],int x[],int y[],int n);  
 
//��Ԫ�ظ���Ϊn������a��Ѱ��Ԫ��e��������������     
int Search(int a[],int n,int e);        
        
        

int a[2*M][2*M];

int main()
{
    ifstream fin("rect1.in");
    ofstream fout("rect1.out");
    int A,B,N,x[2*M],y[2*M],s[5];
    Node square[M]; 
    
    fin>>A>>B>>N;
    
    int t=0;
    for(int i=0;i<N;++i)
    {
        fin>>square[i].x1>>square[i].y1>>square[i].x2>>square[i].y2>>square[i].c;
        x[t]=square[i].x1;
        y[t]=square[i].y1;
        x[t+1]=square[i].x2;
        y[t+1]=square[i].y2;
        t+=2;
    }
        
    sort(x,x+t);
    sort(y,y+t);
    
    SetColour(a,square,x,y,t);
    
    --t;
    for(int i=0;i<t;++i)
        for(int j=0;j<t;++j)
        {
             if(a[i][j]==2)s[2]+=(x[i+1]-x[i])*(y[j+1]-y[j]);
             else if(a[i][j]==3)s[3]+=(x[i+1]-x[i])*(y[j+1]-y[j]);
             else if(a[i][j]==4)s[4]+=(x[i+1]-x[i])*(y[j+1]-y[j]);
             else ;
        }
        
        
        
    s[1]=A*B-s[2]-s[3]-s[4];
    for(int i=1;i<=4;++i)
        fout<<i<<' '<<s[i]<<endl;
    
    
    
  //  system("pause");
    return 0;
}
void SetColour(int a[][2*M],Node square[],int x[],int y[],int n)
{
     int l,r,u,d;
     
     int m=n/2;
     for(int i=0;i<m;++i)
     {
          l=Search(x,n,square[i].x1); 
          r=Search(x,n,square[i].x2);  
          d=Search(y,n,square[i].y1);  
          u=Search(y,n,square[i].y2);     

          for(int k1=l;k1<r;++k1)
              for(int k2=d;k2<u;++k2)
              {
                  a[k1][k2]=square[i].c;
              }
     }

}  
int Search(int a[],int n,int e)
{
    int high,low,mid;
    high=n;
    low=0;
    
    while(low<high)
    {
          mid=(low+high)/2;
          
          if(a[mid]==e)return mid;
          else if(a[mid]>e) high=mid;
          else low=mid;         
    }
    return -1;
}  
