/*
ID:cui chengpeng
PROG:runround
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

bool Runaround(unsigned long n);//判断n是否为循环数，若是返回true，否则返回false 

int main()
{
 	unsigned long n;
 	ifstream fin("runround.in");
 	ofstream fout("runround.out");
 	fin>>n;
 	
 	for(n=n+1;n<100000000&&!Runaround(n);++n);

	if(n<100000000)
        fout<<n<<endl;
	 
    
    return 0;	 
}

bool Runaround(unsigned long n)
{
	vector<int>V;

	while(n>0)
	{
		V.push_back(n%10);
		n/=10;
	}

	int t;
	for(t=0;t<V.size()/2;++t)
	{
		int temp=V[t];
		V[t]=V[V.size()-1-t];
        V[V.size()-1-t]=temp;
	}

	int k1,k2;
	for(k1=0;k1<V.size()-1;++k1)
	{
		for(k2=k1+1;k2<V.size();++k2)
		{
			if(V[k1]==V[k2])return false;
		}
	}

	bool vis[10];
	for(t=0;t<10;++t)vis[t]=false;

	int i=0;
	for(int count=1;count<=V.size();count++)
	{
		vis[i]=true;

		i=(i+V[i])%V.size();

		if(vis[i]==true&&count<V.size())
			return false;
	}

	if(i==0)return true;
	return false;

} 

