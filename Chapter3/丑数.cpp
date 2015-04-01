/*
ID:cuichengpeng
PROG:humble
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<queue>
using namespace std;
typedef struct{
        long long hum;//丑数 
        int n;//该丑数最后一次乘的素数的下标 
        }node;
struct cmp{
       bool operator()(node x,node y){ return x.hum>y.hum;} 
};

const int MAXN=100002;
const int MAXK=102;

long long humble[MAXN];//humble[i]代表第i个丑数 
int S[MAXK];//S[i]代表第i的素数，S为从小到大 
int T[MAXK];//T[i]第i个素数所指向的丑数 
int N,K;
int main()
{
    int i,j;
    ifstream fin("humble.in");
    ofstream fout("humble.out");
    
    priority_queue<node,vector<node>,cmp>Q;
    
    
    fin>>K>>N;
    for(i=0;i<K;++i)fin>>S[i];
    
    node temp;
    for(i=0;i<K;++i)
    {
        T[i]=0;
        temp.hum=S[i];
        temp.n=i;
        Q.push(temp);
    }
    
    humble[0]=1;
    for(int i=1;i<=N;++i)
    {
        temp=Q.top();
        Q.pop();
        if(humble[i-1]!=temp.hum)   humble[i]=temp.hum;
        else i--;
        
        temp.hum=S[temp.n]*humble[++T[temp.n]];
        Q.push(temp);
    } 

    fout<<humble[N]<<endl;
   // system("pause");
    return 0;
}
