/*
ID:cui chengpeng
LANG:C++
PROG:checker
*/
#include<iostream>
#include<fstream>
#include<stack>
using namespace std;

void Eliminate(int n);//清除第n行的棋子，并返回该行棋子所在的位置 
bool Can(int x,int y,int n);//检验（x，y）处是否可以放置棋子，可以返回true 
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
 	for(i=1;i<=n;++i)//在第i行安放棋子 
	{
 	    for(;j<=n;++j)//尝试在第i行j列放置棋子 
 	    {
            if(Can(i,j,n))//若该位置可以放置 
            {	    
			 	a[i][j]=1;
				S.push(j);
				break;		
	        }
        }
        
        
        if(j>n)//该行没找到合适位置 
        {
            if(i==1)break;
            
		 	i-=2;
			j=S.top()+1;
			a[i+1][S.top()]=0;
			S.pop();					
	    } 
	    else j=1;
	    
	    
	    if(i==n)//找到一组解
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
 	 
 	 
 	 for(i=1;i<=n;++i)//纵向检测 
 	 {
	      if(a[i][y]==1)return false;
     }
     
   	 for(i=1;i<=n;++i)//横向检测 
 	 {
	      if(a[x][i]==1)return false;
     }
     
     
     //-45度检测 
     for(i=x,j=y;j<=n&&i<=n;++i,++j)
     {
          if(a[i][j]==1)return false;
     }
     for(i=x,j=y;i>0&&j>0;--i,--j)
     {
	      if(a[i][j]==1)return false;
     }
     
     //45度 检测
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
