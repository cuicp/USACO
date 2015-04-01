/*
ID:cui chengpeng
PROG:hamming
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<bitset>
#include<vector>
using namespace std;
int N,B,D;
int Calculate_hamming_codes(int x,int y)
{
	bitset<8>s(x^y);

	int count=0;
	for(int i=0;i<B;++i)
	{
		count+=s[i];
	}
	return count;
}

int main()
{
	ifstream fin("hamming.in");
	ofstream fout("hamming.out");
	vector<int>V;
	fin>>N>>B>>D;

	V.push_back(0);
	int count=0,i;
	while(V.size()<N)
	{
		++count;
		for(i=0;i<V.size();++i)
		{
			if( Calculate_hamming_codes(V[i],count)<D)
				break;
		}
		if(i>=V.size())
			V.push_back(count);
	}

	fout<<0<<' ';
	for(i=1;i<V.size()-1;++i)
	{
		fout<<V[i];
		if((i+1)%10==0)
			fout<<endl;
		else fout<<' ';
	}
	fout<<V[i]<<endl;

	return 0;
}