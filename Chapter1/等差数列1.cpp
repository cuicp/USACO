/*
ID:cui chnegpeng
PROG:ariprog
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef struct{
        int a;
        int b;
        }Node;

bool cmp(const Node &x,const Node &y)
{
     return x.b<y.b;
}


const int MAX=62500; 
int main()
{
    bool hash[MAX];
    int A[MAX];
    Node T[10000];
    
    
    ifstream fin("ariprog.in");
    ofstream fout("ariprog.out");
    
    memset(hash,false,sizeof(hash));
    
    int M,N;
    fin>>N>>M;
    
    int t=0;
    for(int i=0;i<=M;++i)
        for(int j=0;j<=M;++j)
        {
            int temp=i*i+j*j;    
            if(hash[temp])continue;
            hash[temp]=true;
            A[t++]=temp;
        }
    sort(A,A+t);

    int max=(M*M*2+1)/(N-1);//b可能的最大值 
    int k,count=0;
    for(int i=0;i<t;++i)
    {
        int a=A[i];    
        for(int j=i+1;j<t;++j)
        {
            int b=A[j]-A[i];

            for(k=1;k<N;++k)
            {
                 int temp=a+k*b;
                 if((!hash[temp])||(temp>A[t-1]))
                     break;
            } 
            if(k>=N)
            {
                T[count].a=a;
                T[count].b=b;
                count++;
            }
        }
    
    }
    
    
    sort(T,T+count,cmp);
    
    for(int i=0;i<count;++i)
    {
        fout<<T[i].a<<' '<<T[i].b<<endl;
    }
    
    if(count==0)fout<<"NONE"<<endl;

    return 0;
}
