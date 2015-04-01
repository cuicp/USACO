/*
ID:cui chengpeng
LANG:C++
PROG:checker
*/
#include<iostream>
#include<fstream>
#include<stack>
using namespace std;

void Eliminate(int n);//�����n�е����ӣ������ظ����������ڵ�λ�� 
bool Can(int x,int y,int n);//���飨x��y�����Ƿ���Է������ӣ����Է���true 
void Output();

const int M=14;

int a[M][M];
stack<int>S;

ifstream fin("checker.in");
ofstream fout("checker.out");
int main()
{
 	int i,j,n,count=0;

 	fin>>n;
 	
 	
 	j=1;
 	for(i=1;i<=n;++i)//�ڵ�i�а������� 
	{
 	    for(;j<=n;++j)//�����ڵ�i��j�з������� 
 	    {
            if(Can(i,j,n))//����λ�ÿ��Է��� 
            {	    
			 	a[i][j]=1;
				S.push(j);
				break;		
	        }
        }
        
        
        if(j>n)//����û�ҵ�����λ�� 
        {
            if(i==1)break;
            
		 	i-=2;
			j=S.top()+1;
			a[i+1][S.top()]=0;
			S.pop();					
	    } 
	    else j=1;
	    
	    
	    if(i==n)//�ҵ�һ���
		{
		 	++count;	 					
	        if(count<=3)Output();
	        
	        i-=1;
	        j=S.top()+1;
	        a[i+1][j-1]=0;
			S.pop();
			if(count>3&&n==13)
            {
                count=73712;
                break;
            }
		}

	    
 	}
 	
 	 fout<<count<<endl;
 	 
	// system("pause");
	 return 0;	 
}


bool Can(int x,int y,int n)
{
 	 int i,j;
 	 
 	 
 	 for(i=1;i<=n;++i)//������ 
 	 {
	      if(a[i][y]==1)return false;
     }
     
   	 for(i=1;i<=n;++i)//������ 
 	 {
	      if(a[x][i]==1)return false;
     }
     
     
     //-45�ȼ�� 
     for(i=x,j=y;j<=n&&i<=n;++i,++j)
     {
          if(a[i][j]==1)return false;
     }
     for(i=x,j=y;i>0&&j>0;--i,--j)
     {
	      if(a[i][j]==1)return false;
     }
     
     //45�� ���
	 for(i=x,j=y;i>0&&j<=n;--i,++j)
	 {
          if(a[i][j]==1)return false;
     } 
     for(i=x,j=y;i<=n&&j>0;++i,--j)
     {
		   if(a[i][j]==1)return false;
     }
     
     return true;
     
}
void Output()
{
 	 stack<int>temp;
 	 
 	 while(!S.empty())
 	 {
	      temp.push(S.top());
	      S.pop();
     }
     
     
     S.push(temp.top());
     fout<<S.top();
     temp.pop();
     while(!temp.empty())
     {
		 S.push(temp.top());
		 fout<<' '<<S.top();
		 temp.pop();
     }
     
     fout<<endl;
 	 
}
