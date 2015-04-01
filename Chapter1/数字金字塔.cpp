/*
ID:cui chengpeng
LANG:C++
PROG:numtri
*/

#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

const int M=500501; 

int Max(int a,int b)
{
 	return a>b?a:b;
}

int a[M];

int main()
{
 	int i,j,n,m,t;
 	ifstream fin("numtri.in");
 	ofstream fout("numtri.out");
 	fin>>n;
 	
 	m=n*(n+1)/2;
 	
 	for(i=1;i<=m;++i)fin>>a[i];
 	
 	for(i=m-n;i>=1;--i)
 	{
        t=sqrt(2*i+0.25)+0.49999;

        a[i]+=Max(a[i+t],a[i+t+1]);
    }
 	
 	fout<<a[1]<<endl;

 	return 0;
}
