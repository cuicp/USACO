/*
ID:cui chnegpeng
PROG:milk3
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<queue>
#include<vector>
using namespace std;
typedef struct{
        short a,b,c;//当前状态下ABC中的牛奶量 
        }Node;
struct cmp
{
       bool operator()(int x,int y){ return x>y;} 
};
const int M=21;        
Node turn(int a,int b,int c,int n);
void DFS();

ifstream fin("milk3.in");
ofstream fout("milk3.out");
bool vis[M][M][M];
int A,B,C;
int main()
{
    fin>>A>>B>>C;
    
    DFS();

    return 0;
}
void DFS()
{
     queue<Node>Q;
     priority_queue<int,vector<int>,cmp>pri_q;
     Node T,temp;
     
     T.a=0;
     T.b=0;
     T.c=C;
     
     Q.push(T);
     vis[T.a][T.b][T.c]=true;
     pri_q.push(C);
     while(!Q.empty())
     {
          T=Q.front();          
          Q.pop();
          for(int i=1;i<=6;++i)
          {
              temp=turn(T.a,T.b,T.c,i);

              if(!vis[temp.a][temp.b][temp.c])
              {
                  vis[temp.a][temp.b][temp.c]=true;
                  if(temp.a==0)pri_q.push(temp.c);
                  Q.push(temp);
              }
          }//for 
          
     }//while
     
     fout<<pri_q.top();
     pri_q.pop();
     while(!pri_q.empty())
     {
         fout<<' '<<pri_q.top();
         pri_q.pop();
     }
     fout<<endl;
     
}
Node turn(int a,int b,int c,int n)
{
     Node N;
     N.a=a;N.b=b;N.c=c;
     
     if(n==1)//A->B
     {
          if(a>(B-b)){N.a=a-(B-b);N.b=B;}   
          else {N.a=0;N.b+=a;}
     }
     else if(n==2)//A->C
     {
          if(a>(C-c)){N.a=a-(C-c);N.c=C;}   
          else {N.a=0;N.c+=a;}
     }
     else if(n==3)//B->A
     {
          if(b>(A-a)){N.a=A;N.b=b-(A-a);}
          else {N.b=0;N.a+=b;}
     }
     else if(n==4)//B->C
     {
          if(b>(C-c)){N.c=C;N.b=b-(C-c);}
          else {N.b=0;N.c+=b;}
     }
     else if(n==5)//C->A
     {
          if(c>(A-a)){N.a=A;N.c=c-(A-a);}
          else {N.c=0;N.a+=c;}
     }
     else//C->B
     {
         if(c>(B-b)){N.b=B;N.c=c-(B-b);}
         else {N.c=0;N.b+=c;}
     }
     
     return N;
}

