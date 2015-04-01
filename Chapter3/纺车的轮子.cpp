#include<iostream>
#include<fstream>
using namespace std;
typedef struct{
        int start;
        int end;
        int lenth;
        }Node;
        
//����ǰ״̬�������ⷵ��true�����򷵻�false 
bool IsAnswer(Node w[][180],int n[]);
//��ÿ�����ӽ���ת��,ÿ��ת��һ��
void Trun(Node w[][180],int v[],int n[]);
//������m��n֮����û�п��Դ���2-4�����ӵĹ��� s��e�ֱ�Ϊ��һ��������ȱ�ڵĿ�ʼֵ�����ֵ 
bool Check(int s,int e,Node w[][180],int n[]);

int main()
{
    Node w[5][180];//��¼��n�����ӵ�ȱ����Ϣ 
    int v[5];//��¼ÿ�����ӵ�ת���ٶ� 
    int n[5];//��¼ÿ�����ӵ�ȱ�ڸ��� 
    
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
          //��Ѱ�ҵ��𰸣��˳�ѭ�� 
          if(IsAnswer(w,n)) 
          {
              break;
          }
          //��ÿ�����ӽ���ת��,ÿ��ת��һ��
          Trun(w,v,n);
    }
    
    
    cout<<t<<endl; 
    

    system("pause");
    return 0;
}

bool IsAnswer(Node w[][180],int n[])
{
     int i;
     
     //�Ե�һ�����ӵ�n[0]��ȱ��Ϊ��׼���鵱ǰ״̬�Ƿ�������� 
     for(i=0;i<n[0];++i)
     {
         if(w[0][i].start>=w[0][i].end)//0��ֲ��ڱ�׼�ֵ�ȱ�ڶ˵�֮��ʱ
         {
             if(Check(w[0][i].start,359,w,n)||Check(0,w[0][i].end,w,n))
                 return true;
         }
         else//0��ֲ��ڱ�׼�ֵ�ȱ�ڶ˵�֮��ʱ
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
     for(t=s;t<=e;++t)//tΪ���� 
     {
          for(i=1;i<5;++i)//��̽�����ĸ����� 
          {
               for(j=0;j<n[i];++j)//����i�������Ƿ�������� 
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
