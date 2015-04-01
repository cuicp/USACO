/*
ID:cuichengpeng
PROG:job
LANG:C++
*/ 
#include<iostream>
#include<fstream>
using namespace std;
const int INF=100000000;
const int MAXM=30;
const int MAXN=1000;
//该函数更新q并且返回刚加入的工件的加工完毕时刻 
//cost[i]为第i台机器做一次操作的时间，n代表机器的台数
int updata(int q[],int cost[],int n)
{
	int min=INF;
	int index;
	for(int i=0;i<n;++i)
	{
		int temp=(q[i]+1)*cost[i];
		if(temp<min)
		{
			min=temp;
			index=i;
		}
	}	
	q[index]++;
	return q[index]*cost[index];
} 
int main()
{
	ifstream fin("job.in");
	ofstream fout("job.out");
	int costA[MAXM],costB[MAXM];
	int N,M1,M2;
	
	fin>>N>>M1>>M2;
	for(int i=0;i<M1;++i)fin>>costA[i];
	for(int i=0;i<M2;++i)fin>>costB[i];
	
	int qA[MAXM],qB[MAXM],timeA[MAXN],timeB[MAXN];
	
	for(int i=0;i<N;++i)
	{
		timeA[i]=updata(qA,costA,M1);
		timeB[i]=updata(qB,costB,M2); 
	}
	
	
	int max=-INF;
	for(int i=0;i<N;++i)
	{
		if(timeA[i]+timeB[N-1-i]>max)
			max=timeA[i]+timeB[N-1-i];
	}
	
	fout<<timeA[N-1]<<' '<<max<<endl;
	
	return 0;
}
