/*
ID:cui chengpeng
PROG:preface
LANG:C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int count[7];
void Calculate(int n)
{
	int temp;
	//千位
	count[6]+=n/1000;
	n%=1000;

	//百位
	temp=n/100;
	if(temp==9)
	{
		count[6]+=1;
		count[4]+=1;
	}
	else if(temp>=5)
	{
		count[5]+=1;
		count[4]+=temp-5;
	}
	else if(temp==4)
	{
        count[5]+=1;
		count[4]+=1;
	}
	else
	{
		count[4]+=temp;
	}
	n%=100;

	//十位
	temp=n/10;
	if(temp==9)
	{
		count[4]+=1;
		count[2]+=1;
	}
	else if(temp>=5)
	{
		count[3]+=1;
		count[2]+=temp-5;
	}
	else if(temp==4)
	{
        count[3]+=1;
		count[2]+=1;
	}
	else
	{
		count[2]+=temp;
	}
	n%=10;

	//个位
	temp=n;
	if(temp==9)
	{
		count[2]+=1;
		count[0]+=1;
	}
	else if(temp>=5)
	{
		count[1]+=1;
		count[0]+=temp-5;
	}
	else if(temp==4)
	{
        count[1]+=1;
		count[0]+=1;
	}
	else
	{
		count[0]+=temp;
	}
}
int main()
{
	int N;

	ifstream fin("preface.in");
	ofstream fout("preface.out");

	fin>>N;

	
	for(int i=1;i<=N;++i)
	    Calculate(i);

	if(count[0]>0)
		fout<<'I'<<' '<<count[0]<<endl;
    if(count[1]>0)
		fout<<'V'<<' '<<count[1]<<endl;
    if(count[2]>0)
		fout<<'X'<<' '<<count[2]<<endl;
    if(count[3]>0)
		fout<<'L'<<' '<<count[3]<<endl;
    if(count[4]>0)
		fout<<'C'<<' '<<count[4]<<endl;
    if(count[5]>0)
		fout<<'D'<<' '<<count[5]<<endl;
    if(count[6]>0)
		fout<<'M'<<' '<<count[6]<<endl;



	return 0;

}