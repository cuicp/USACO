/*
ID:cui chengpeng
PROG:zerosum
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<cmath>
#include<stack>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


int Sum(int a[],int N);//计算此种情况下产生的和 
void Output(int a[],int N);//输出当前算式 
vector<string>V;
ifstream fin("zerosum.in");
ofstream fout("zerosum.out");
int main()
{
    int N,n,s,t,a[9];

    fin>>N;
    
    //枚举N-1个运算符，0代表‘+’，1代表‘-’，2代表’ ‘ 
    n=(int)pow(3.0,N-1);
    
    for(int i=1;i<=n;++i)
    {
         for(int j=0;j<9;++j)a[j]=0;     
                
         t=0;
         s=i;
     
         do{
            a[++t]=s%3;
            s/=3;
         }while(s>0);
        
         if(Sum(a,N)==0) Output(a,N);
         
                    
    }
    
    sort(V.begin(),V.end());
    for(int i=0;i<V.size();++i)
    {
            fout<<V[i]<<endl;
    }
    
 //   system("pause");
    return 0;
}

int Sum(int a[],int N)
{
    int num[10],i,j=0,m,n,sum=0;
    stack<int>S;
    
    for(i=1;i<=N;++i)
    {
        num[i]=i;   
    }
    
    
    S.push(1);
    for(i=1;i<N;++i)
    {
        if(a[i]==2)//当运算符为空格时 
        {
             n=S.top();
             S.pop();
             S.push(10*n+num[i+1]);     
        } 
        else// 当运算符不为空格时 
        {
             S.push(num[i+1]);
        }           
    }
    
    i=S.size();
    while(!S.empty())
    {
         num[i--]=S.top();
         S.pop();            
    }
    
    sum+=num[1];j=1;
    for(i=1;i<N;++i)
    {
        if(a[i]==0)sum+=num[++j];
        else if(a[i]==1)sum-=num[++j];
        else ;
    }


    return sum;  
      
}

void Output(int a[],int N)
{
    int i;
    int n;
    string s;


    for(i=1;i<N;++i)
    {
        //cout<<i;
        s+=char(i+'0');

        if(a[i]==0)
        {
            //cout<<'+';
            s+='+';
            
        }
        else if(a[i]==1)
        {
            //cout<<'-';
            s+='-';
        }
        else
        {
            //cout<<' ';
            s+=' ';
        }            
    }
    
    //cout<<N<<endl;
    s+=char(N+'0');
    
    V.push_back(s);
   
}






