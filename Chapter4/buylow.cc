/*
ID:cuichengpeng
PROG:buylow
LANG:C++
*/
#include<iostream>
#include<fstream>
using namespace std;
const long long INF=100000000;
ifstream fin("buylow.in");
ofstream fout("buylow.out");

class big_num
{	
	public:
		big_num();
		big_num(long long int a);
		big_num& add(const big_num& a);
		bool equal(big_num& a)const;
		void print()const;	
		long long int base[50];
		int len;
};
big_num::big_num()
{
	for(int i=0;i<50;++i)
		this->base[i]=0;
	this->len=0;
}
big_num::big_num(long long int a)
{
	for(int i=0;i<50;++i)
		this->base[i]=0;
	this->base[0]=a;
	this->len=1;
}
big_num& big_num::add(const big_num& a)
{
	int n=a.len>this->len?a.len:this->len;
	for(int i=0;i<n;++i)
	{
		long long sum=this->base[i]+a.base[i];
		this->base[i]=sum%INF;
		this->base[i+1]+=sum/INF;
	}
	if(this->base[n]>0)this->len=n+1;
	else this->len=n;
	return *this;
}
bool big_num::equal(big_num& a)const
{
	if(this->len!=a.len)return false;
	
	for(int i=0;i<a.len;++i)
	{
		if(this->base[i]!=a.base[i])
			return false;
	}
	return true;
}
void big_num::print()const
{
	fout<<this->base[this->len-1];
	for(int i=this->len-2;i>=0;--i)
	{
		int mod=INF/10;
		for(int j=1;j<=7;++j)
		{
			if(this->base[i]<mod)
			{
				fout<<'0';
				mod/=10;
			}
			else break;
		}
		fout<<this->base[i];
	}
}

const int MAXN=5001;
int main()
{

	int N,a[MAXN];

	fin>>N;
	for(int i=0;i<N;++i)
	{
		fin>>a[i];
	}
	a[N]=0;
	N=N+1;

	int dp[MAXN];
	big_num count[MAXN];
	int next[MAXN];

	for(int i=0;i<N;++i)
	{
		next[i]=-1;
		for(int j=i+1;j<N;++j)
		{
			if(a[i]==a[j])
			{
				next[i]=j;
				break;
			}
		}
	}


	dp[0]=1;
	count[0].add(1);
	for(int i=1;i<N;++i)
	{
		dp[i]=1;
		count[i].add(1);
		for(int j=0;j<i;++j)
		{	
			if(next[j]!=-1&&next[j]<i)
				continue;
			if(a[i]<a[j])
			{
				if(dp[i]<dp[j]+1)
				{
					dp[i]=dp[j]+1;
					count[i]=count[j];
				}
				else if(dp[i]==dp[j]+1)
				{
					count[i].add(count[j]);
				}
			}
		}
	}

	fout<<dp[N-1]-1<<' ';
	count[N-1].print();
	fout<<endl;
	return 0;
}
