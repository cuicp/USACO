/*
ID:cuichengpeng
PROG:lamps
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<bitset>
#include<string>
#include<algorithm>
using namespace std;

ifstream fin("lamps.in");
ofstream fout("lamps.out");
int N,C;
vector<vector<int> >V;
vector<int>ON,OFF;
void LAMPS(int n);
void Output();
void Change(vector<int>&v,int n);
bool Match(vector<int>&v);
int main()
{
	fin>>N>>C;

	int temp;
	fin>>temp;
	while(temp!=-1)
	{
		ON.push_back(temp);
		fin>>temp;
	}
	fin>>temp;
	while(temp!=-1)
	{
		OFF.push_back(temp);
		fin>>temp;
	}
	
	
	int i=0;
	if(C<=4)
	{
		for(i=C;i>=0;i-=2)
		{
			LAMPS(i);
		}
	}
	else
	{
		if(C%2==0)
		{
            LAMPS(0);
			LAMPS(2);
			LAMPS(4);
		}
		else 
		{
			LAMPS(1);
			LAMPS(3);
		}
	}

	Output();


	return 0;
}
bool Match(vector<int>&v)
{
	int k;
	for(k=0;k<ON.size();k++)
	{
		if(v[ON[k]-1]!=1)
			return false;
	}
	for(k=0;k<OFF.size();++k)
	{
		if(v[OFF[k]-1]!=0)
			return false;
	}
	return true;
}
void Change(vector<int>&v,int n)
{
	if(n==1)
	{
		for(int i=0;i<v.size();++i)
		{
			if(v[i]==0)v[i]=1;
			else v[i]=0;
		}
	}
	else if(n==2)
	{
		for(int i=0;i<v.size();i+=2)
		{
			if(v[i]==0)v[i]=1;
			else v[i]=0;
		}
	}
	else if(n==3)
	{
		for(int i=1;i<v.size();i+=2)
		{
            if(v[i]==0)v[i]=1;
			else v[i]=0;
		}
	}
	else
	{
		for(int i=0;i<v.size();i+=3)
		{
			if(v[i]==0)v[i]=1;
			else v[i]=0;
		}
	}
}

void LAMPS(int n)
{
	int i,j,k;
	bool flag=true;

	vector<int>temp(N,1);

	if(n==0)
	{
		if(Match(temp))
		    V.push_back(temp);
	}
	else if(n==1)
	{
		for(i=0;i<16;++i)
		{
			bitset<4>b(i);
			if(b[0]+b[1]+b[2]+b[3]==1)
			{
				for(k=0;k<N;++k)temp[k]=1;
				for(j=0;j<4;j++)
				{
					if(b[j]==1)
						Change(temp,j+1);
				}
		        if(Match(temp))
		            V.push_back(temp);
			}
		}
	}
	else if(n==2)
	{
		for(i=0;i<16;++i)
		{
			bitset<4>b(i);
			if(b[0]+b[1]+b[2]+b[3]==2)
			{
                for(k=0;k<N;++k)temp[k]=1;
				for(j=0;j<4;j++)
				{
					if(b[j])
						Change(temp,j+1);
				}
				if(Match(temp))
					V.push_back(temp);
			}
		}
	}
	else if(n==3)
	{
		for(i=0;i<16;++i)
		{
			bitset<4>b(i);
			if(b[0]+b[1]+b[2]+b[3]==3)
			{			
                for(k=0;k<N;++k)temp[k]=1;
				for(j=0;j<4;j++)
				{
					if(b[j])
						Change(temp,j+1);
				}
				if(Match(temp))
		            V.push_back(temp);
			}
		}
	}
	else
	{
		for(i=0;i<16;++i)
		{
			bitset<4>b(i);
			if(b[0]+b[1]+b[2]+b[3]==4)
			{
                for(k=0;k<N;++k)temp[k]=1;
				for(j=0;j<4;j++)
				{
					if(b[j])
						Change(temp,j+1);
				}
				if(Match(temp))
					V.push_back(temp);
			}
		}
	}
}
void Output()
{
	if(V.size()==0)
	{
		fout<<"IMPOSSIBLE"<<endl;
		return ;
	}

	int i,j;
	string s[16];
	for(i=0;i<V.size();++i)
	{
		for(j=0;j<V[i].size();++j)
		{
			s[i]+=('0'+V[i][j]);
		}
	}
	sort(s,s+10);
	for(i=0;i<10;++i)
	{
		if(s[i].size()>0)
		    fout<<s[i]<<endl;
	}
}