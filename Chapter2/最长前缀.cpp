/*
ID:cui chengpeng
PROG:prefix
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cstring>
using namespace std;
bool dp[200005];
int main()
{
	ifstream fin("prefix.in");
	ofstream fout("prefix.out");

	string s,temp;
	vector<string>V;

	int max_lenth=0;
	fin>>temp;
	
	while(temp!=".")
	{
		if(max_lenth<temp.size())
			max_lenth=temp.size();
		V.push_back(temp);
		fin>>temp;
	}

    temp="";
	do{
        s+=temp;
		fin>>temp;
	}while(fin);
	

	memset(dp,false,sizeof(dp));

	dp[0]=true;

	int lenth=1,prifix=0,i,j,l=1;

	while(l<=max_lenth)
	{
		lenth=prifix+l;
		for(i=0;i<V.size();++i)//枚举所有的元素
		{
			if(lenth>=V[i].size())
			{
				for(j=V[i].size()-1;j>=0;j--)//进行匹配
				{
					if(V[i][j]!=s[lenth-(V[i].size()-j)])break;
				}
				if(j<0&&dp[lenth-V[i].size()])
				{
					dp[lenth]=true;
					prifix=lenth;
					l=0;
					break;
				}
			}//if
		}//for

		l++;
	}//while

	
	fout<<prifix<<endl;
    
	return 0;
}
