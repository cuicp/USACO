#include<iostream>
#include<cstring>
#include<fstream> 
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
typedef struct{
        int count;
        char a[13];
        }Node;

struct cmp
{
       bool operator()(Node x,Node y)
       { 
            if(x.count!=y.count) return x.count<y.count;
            else
            {
                if(strlen(x.a)<strlen(y.a))return false;
                else if(strlen(x.a)>strlen(y.a))return true;
                else
                {
                    if(strcmp(x.a,y.a)<0) return false;
                    else return true;
                }
            }
       } 
};
void GetNextval(char s[],int p[]);
int Index_KMP(char s[],char t[],int pos,int next[]);

const int M=200002;
const int M1=1000;


int main()
{
    int A,B,N,next[13];
    char S[M],T[M1];
    priority_queue<Node,vector<Node>,cmp>que;
    ifstream fin("contact.txt");
    
    fin>>A>>B>>N;
    
    while(fin>>S);
    
    int len=strlen(S);
    
    int m,n,pos,count;
    Node temp;
    for(int i=A;i<=B;++i)
    {
        n=pow(2.0,i);       
        m=n+n;
        
        for(int j=n;j<m;++j)
        {
             _itoa(j,T,2);
             GetNextval(&T[1],next);          
             
             pos=Index_KMP(S,&T[1],0,next);
             count=0;
             while(pos!=-1){
                 count++;
                 pos=Index_KMP(S,&T[1],pos+1,next);
             }
             
             temp.count=count;
             strcpy(temp.a,&T[1]);
             que.push(temp);
             
        }
    
    }
    
    Node temp1;
    temp=que.top();
    que.pop();
    cout<<temp.count<<endl;
    count=0;
    
    cout<<temp.a;
    count++;
    for(int i=1;i<N;)
    {
         temp1=que.top();
         que.pop();
         
         if(temp1.count==temp.count)
         {
             cout<<' '<<temp1.a;
             i++;
             count++;
             if(count%6==0)cout<<endl;
         }
         else{
              cout<<endl<<temp1.count<<endl;
              count=0;
              cout<<temp1.a;
              count++;
         }   
         temp=temp1;
    }
    cout<<endl;

    fin.close();

    system("pause");
    return 0;
}
        
void GetNextval(char s[],int p[])
{
     int i=0,j=-1;
     p[0]=-1;
     int len=strlen(s);
     while(i<len)
     {
         if(j==-1||s[i]==s[j])
         {
             ++i;++j;
             if(s[i]!=s[j])p[i]=j;
             else p[i]=p[j];
         }
         else j=p[j];
     }
}

int Index_KMP(char s[],char t[],int pos,int next[])
{
    int i=pos,j=0;
    int s_len=strlen(s);
    int t_len=strlen(t);
    while(i<s_len&&j<t_len)
    {
        if(j==-1||s[i]==t[j])++i,++j;
        else j=next[j];                         
    }
    if(j>=t_len)return i-t_len;
    return -1;
}

