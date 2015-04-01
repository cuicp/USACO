/*
ID:cui chengpeng
PROG:subset
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int main()
{
	ifstream fin("subset.in");
	ofstream fout("subset.out");

	int N,T,S;
	fin>>N;

	T=N*(N+1);

	vector<vector<int> >V;
	vector<int>V1(T,0);
	V.push_back(V1);
	V.push_back(V1);

	V[1][1]=1;
	for(int i=1;i<=N;++i)//集合的元素个数递增
	{
		T=i*(i+1)/2+1;
		S=(i+1)%2;
		for(int k=0;k<T;k++)V[S][k]=0;
		for(int j=0;j<T;++j)//两个集合的差
		{
			V[S][j+i+1]+=V[i%2][j];

			if(j-i-1>=0)
			    V[S][j-i-1]+=V[i%2][j];
			else
                V[S][i+1-j]+=V[i%2][j];

		}
		
	}
	
	if(N%2==0)
		fout<<V[0][0]<<endl;
	else
		fout<<V[1][0]<<endl;

	return 0;
}