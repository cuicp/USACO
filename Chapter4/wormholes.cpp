/*
ID:cuichengpeng
PROG:wormhole
LANG:C++
*/ 
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
typedef long long LL;
int count=0;
const int MAXLOOP=12;
const LL INF=1000000000;
//v是节点的组合向量，port是出口向量，返回下一个出口向量
//如果没有下一个出口，返回空向量 
int find_next(vector<vector<LL> >v,int port)
{
	LL x=v[port][0];
	LL y=v[port][1];
	
	LL left=INF;
	int next=-1;
	for(int i=0;i<v.size();i++)
	{
		if(i==port)continue;
		if(v[i][1]==y&&v[i][0]>x&&v[i][0]<left)
		{
			left=v[i][0];
			next=i;
		}
	}
	
	if(next==-1) return next; 
	if(next%2==0)return next+1;
	else return next-1;
}

bool circle(vector<vector<LL> >v)
{
	int n=v.size();
	int loop,next;//记录在寻找下一个节点的过程中遇到了几个节点 
	for(int i=0;i<v.size();i++)
	{
		//从v[i]出去 
		next=find_next(v,i);
		loop=0;
		while(next!=-1)
		{
			loop++;
			if(loop>=MAXLOOP)return true;
			next=find_next(v,next);
		}
	}
	return false;
}
void dfs(vector<vector<LL> >have,vector<vector<LL> >leave,bool flag)
{
	if(leave.size()==0)
	{
		if(circle(have))
			count++;
		return ;
	}
	
	if(flag==false)
	{
		have.push_back(leave[0]);
		leave.erase(leave.begin());
		dfs(have,leave,true);
		
	}else
	{
		int n=leave.size();
		for(int i=0;i<n;++i)
		{
			vector<LL>temp=leave[i];
	
			have.push_back(temp);
			leave.erase(leave.begin()+i);
			dfs(have,leave,false);
			leave.insert(leave.begin()+i,temp);
			have.erase(have.end()-1);
		}
	}
}


int main()
{
	ifstream fin("wormhole.in");	
	ofstream fout("wormhole.out");
	int N;
	fin>>N;
	vector<vector<LL> >v;
	
	for(int i=0;i<N;++i)
	{
		vector<LL>temp(2);
		fin>>temp[0]>>temp[1];
		v.push_back(temp);
	}

	vector<vector<LL> >have;
	dfs(have,v,0);
	fout<<count<<endl;
	
	return 0;
}
