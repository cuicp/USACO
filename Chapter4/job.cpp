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
//�ú�������q���ҷ��ظռ���Ĺ����ļӹ����ʱ�� 
//cost[i]Ϊ��į������һ�β�����ʱ�䣬n���������̨��
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
