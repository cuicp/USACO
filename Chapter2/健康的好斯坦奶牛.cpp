/*
ID:cui chengpeng
PROG:holstein
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
#include<bitset>
#include<cstdio>
using namespace std;

int sum[25];
int m,n;
vector<int>GOAL;
vector<vector<int> >V;

int main()
{
	ifstream fin("holstein.in");
	ofstream fout("holstein.out");

	int i,j,temp;
	fin>>n;
	
	for(i=0;i<n;++i)
	{
		fin>>temp;
		GOAL.push_back(temp);
	}

	vector<int>temp1;
	fin>>m;
	for(i=0;i<m;++i)
	{
		for(j=0;j<n;++j)
		{
			fin>>temp;
			temp1.push_back(temp);
		}
        V.push_back(temp1);
		temp1.clear();
	}

	int k,max=pow(2,m);
	for(int count=1;count<=m;++count)
	{
		for(i=1;i<max;++i)
		{
			bitset<16>b(i);
			
			temp=0;
			for(int t=0;t<m;++t)temp+=b[t];
			if(temp!=count)continue;

			for(int s=0;s<25;++s)sum[s]=0;
			for(int k1=0;k1<m;++k1)
			{
				if(b[k1]==0)continue;
				for(int k2=0;k2<n;++k2)
				{
					sum[k2]+=V[k1][k2];
				}
			}
			
		    for(k=0;k<n;++k)
			{
			    if(sum[k]<GOAL[k])break;
			}
			
			if(k>=n)
			{
				fout<<count;
				for(int k1=0;k1<m;++k1)
				{
					if(b[k1])fout<<' '<<k1+1;
				}
				break;
			}
		}
		if(k>=n)break;

	}

	fout<<endl;
	return 0;
}
