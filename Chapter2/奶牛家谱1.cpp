/*
ID:cui chengpeng
PROG:nocows
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<cmath> 
using namespace std;
long int f[201][100]={0};
int main()
{
	int i,j,k,m,n,ans;
    ifstream fin("nocows.in");
    ofstream fout("nocows.out");
    
    fin>>n>>k;
	f[1][1]=0;
	f[3][2]=0;
	for(i=1;i<=k;i++)f[1][i]=1;
	for(i=1;i<=n;i+=2)
		for(j=1;j<=k;j++)
			for(m=1;m<=i-2;m+=2){
				f[i][j]=(f[i][j]+f[m][j-1]*f[i-1-m][j-1])%9901;
			}
	fout<<(f[n][k]+9901-f[n][k-1])%9901<<endl;
//	printf("%ld",(f[n][k]+9901-f[n][k-1])%9901);
//	system("pause");
	return 0;

}
