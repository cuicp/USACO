/*
ID:cuichengpeng
PROG:shuttle
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<queue>
#include<set>
using namespace std;
static int goal_cnt=0;
static int min_step=100000000;
string goal;

ifstream fin("shuttle.in");
ofstream fout("shuttle.out");

typedef struct 
{
	short point;//空格位置
	string s;//棋盘
	vector<short>path;//转移到该状态所需的步骤
}state;

void start_state(state& s,int N)
{
	for(int i=0;i<N;++i)s.s+='0';
	s.s+=' ';
	for(int i=0;i<N;++i)s.s+='1';
	s.path.clear();
	s.point=N;
}
state change_state(state st,int n)
{
	int point=st.point;
	if(n==0){//ABA BBA-->A ABBBA
		if(point>=2&&st.s[point-1]!=st.s[point-2]){
			st.s[point]=st.s[point-2];
			st.s[point-2]=' ';
			st.point-=2;
			st.path.push_back(st.point);
		}
	}else if(n==1){//ABA BBA-->AB ABBA
		if(point>=1)
		{
			st.s[point]=st.s[point-1];	
			st.s[point-1]=' ';
			st.point-=1;
			st.path.push_back(st.point);
		}
	}else if(n==2){//ABA BBA-->ABAB BA
		if(point<=st.s.size()-2)
		{
			st.s[point]=st.s[point+1];	
			st.s[point+1]=' ';
			st.point+=1;
			st.path.push_back(st.point);
		}
		
	}else{//ABA ABB-->ABABA B
		if((point<=st.s.size()-3)&&st.s[point+1]!=st.s[point+2])
		{
			st.s[point]=st.s[point+2];
			st.s[point+2]=' ';
			st.point+=2;
			st.path.push_back(st.point);
		}
	}	
	return st;
}
void output(const state& s)
{
	fout<<s.path[0]+1;
	for(int j=1;j<s.path.size();++j)
	{
		if(j%20==0)
		{
			fout<<endl;
			fout<<s.path[j++]+1;
		}
		fout<<' '<<s.path[j]+1;
	}
	fout<<endl;
}

queue<state>Q;
set<string>S;
void bfs(int N)
{
	state start;
	start_state(start,N);

	Q.push(start);
	S.insert(start.s);
	
	state st,next;
	while(!Q.empty())
	{
		st=Q.front();
		Q.pop();
		
		if(goal_cnt==1||st.path.size()>=min_step)break;

		for(int i=0;i<4;++i)
		{
			next=change_state(st,i);
			if(S.find(next.s)!=S.end())
				continue;
			
			if(next.s==goal)
			{
				if(goal_cnt==0)
				{
					min_step=next.path.size();
					goal_cnt++;
					output(next);
				}
				else{
					output(next);
					break;
				}
			}


			S.insert(next.s);
			Q.push(next);
		}
		
	}


}
int main()
{
	int N;
	fin>>N;
	for(int i=0;i<N;++i)goal+='1';
	goal+=' ';
	for(int i=0;i<N;++i)goal+='0';
	
	bfs(N);
	
	return 0;
}
