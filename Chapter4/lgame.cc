/*
ID:cuichengpeng
PROG:lgame
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=40005;
const short l_score[26]={2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7};
short l_set[26];
short d_score[MAX];
vector<string>dict;

inline bool contain(const string s)
{
	int len=s.size();
	bool flag=true;
	int n;
	for(n=0;n<len;++n)
	{
		int temp=--l_set[s[n]-'a'];
		if(temp<0)
		{
			flag=false;
			break;
		}
	}
	
	if(n==len)n--;
	for(int i=0;i<=n;++i)
	{
		++l_set[s[i]-'a'];
	}

	return flag;
}
inline short get_score(const string& s)
{
	short score=0;
	int len=s.size();
	for(int i=0;i<len;++i)
	{
		score+=l_score[s[i]-'a'];
	}
	return score;
}
int main()
{
	ifstream fin("lgame.in");
	ofstream fout("lgame.out");
	ifstream dict_in("lgame.dict");
	
	string temp;
	fin>>temp;
	const short INF_SCORE=get_score(temp);

	memset(l_set,0,sizeof(l_set));
	for(int i=0;i<temp.size();++i)
		l_set[temp[i]-'a']++;

	memset(d_score,0,sizeof(d_score));
	int n=0;
	while(dict_in>>temp)
	{
		if(temp==".")break;
		if(!contain(temp))continue;

		dict.push_back(temp);
		d_score[n++]=get_score(temp);
	}

	int max_score=0;
	vector<vector<int> >max_list;
	vector<int>tempv;

	n=dict.size();
	for(int i=0;i<n;++i)
	{
		if(d_score[i]>max_score)
		{
			max_score=d_score[i];
			max_list.clear();

			tempv.clear();
			tempv.push_back(i);
			tempv.push_back(-1);
			max_list.push_back(tempv);
		}else if(d_score[i]==max_score){
			tempv.clear();
			tempv.push_back(i);
			tempv.push_back(-1);
			max_list.push_back(tempv);
		}
	}

	for(int i=0;i<n;++i)
	{
		for(int j=i+1;j<n;++j)
		{
			if(!contain(dict[i]+dict[j]))continue;
			int sc=d_score[i]+d_score[j];
			if(sc>max_score&&sc<=INF_SCORE)
			{
				max_score=sc;
				max_list.clear();
				
				tempv.clear();
				tempv.push_back(i);
				tempv.push_back(j);
				max_list.push_back(tempv);
			}else if(sc==max_score){
				tempv.clear();
				tempv.push_back(i);
				tempv.push_back(j);
				max_list.push_back(tempv);

			}else{

			}
		}
	}

	fout<<max_score<<endl;
	vector<string>out;
	for(int i=0;i<max_list.size();++i)
	{
		if(max_list[i][1]==-1)
		{
			out.push_back(dict[max_list[i][0]]);
		}else{
			out.push_back(dict[max_list[i][0]]+' '+dict[max_list[i][1]]);
		}
	}
	
	sort(out.begin(),out.begin()+out.size());
	for(int i=0;i<out.size();++i)
		fout<<out[i]<<endl;


	return 0;
}
