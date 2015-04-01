/*
ID:cuichengpeng
PROG:race3
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<cstring>
using namespace std;
bool dfs(vector<vector<int> >&v,int s,int end,bool vis[])
{
	//int n=v.size();
	//if(s==n-1)return true;
	if(s==end)return true;

	vis[s]=true;
	int n1=v[s].size();
	for(int i=0;i<n1;++i)
	{
		if(vis[v[s][i]]==true)continue;
		if(dfs(v,v[s][i],end,vis)==true)return true;
	}

	return false;
}
bool is_split(vector<vector<int> >&v,int s)
{
	//vis1和vis2分别代表两个连通分量，vis[i]==true代表该子图中包含i
	//节点，否则该节点不在该子图中
	bool vis1[55],vis2[55];
	memset(vis1,0,sizeof(vis1));
	memset(vis2,0,sizeof(vis2));
	
	vector<int>tempv=v[s];
	v[s].clear();
	dfs(v,0,v.size(),vis1);
	v[s]=tempv;
	dfs(v,s,v.size(),vis2);
	//判断两个子图中是否有含有除s之外的节点
	int n=v.size();
	for(int i=0;i<n;i++)
	{
		if(vis1[i]&&vis2[i]&&i!=s)
			return false;
	}


	//判断vis1是不是well-form的
	//case1
	for(int i=0;i<v[s].size();++i)
		if(vis1[v[s][i]]&&v[s][i]!=s)return false;
	//case2
	//case3


	//判断vis2是不是well-form的
	//case1
	//case2
	//case3

	return true;
}

int main()
{
	ifstream fin("race3.in");
	ofstream fout("race3.out");
	
	vector<vector<int> >v;
	
	int temp;
	vector<int>tempv;
	while(fin>>temp)
	{
		if(temp==-1)break;
		tempv.push_back(temp);
		while(fin>>temp)
		{
			if(temp==-2)break;
			tempv.push_back(temp);
		}
		v.push_back(tempv);
		tempv.clear();
	}
	v[v.size()-1].clear();

	bool vis[55];

	vector<int>unav;
	int n=v.size()-1;
	for(int i=1;i<n;++i)
	{
		memset(vis,0,sizeof(vis));
		tempv=v[i];
		v[i].clear();
		if(!dfs(v,0,n,vis))
			unav.push_back(i);
		v[i]=tempv;
	}
	
	
	vector<int>split;
	for(int i=0;i<unav.size();++i)
	{
		if(is_split(v,unav[i]))split.push_back(unav[i]);
	}

		
	fout<<unav.size();
	for(int i=0;i<unav.size();++i)
		fout<<' '<<unav[i];
	fout<<endl;
	fout<<split.size();
	for(int i=0;i<split.size();++i)
		fout<<' '<<split[i];
	fout<<endl;


	return 0;
}
