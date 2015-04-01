/*
ID:cui chengpeng
PROG:dualpal
LANG:C++
*/
#include<iostream>
#include<stack>
#include<queue>
#include<fstream>
using namespace std;

bool Palindromic(int m,int t);

int main()
{
 	int i,N,S,count=0,count1;
 	ifstream fin("dualpal.in");
 	ofstream fout("dualpal.out");
 	fin>>N>>S;
 	
 	while(count<N)
 	{
	     count1=0;
         ++S;
         for(i=2;i<=10&&count1<2;++i)
         {
		     if(Palindromic(S,i))++count1;			   
         }
         if(count1==2)
		 {
	          fout<<S<<endl;
	          ++count;
	     }
    }
 	
 //	system("pause");
 	return 0;
}

bool Palindromic(int m,int t)
{
 	 int temp;
 	 stack<int>S;
 	 queue<int>Q;
 	 
 	 do{
	 	  temp=m%t;
	 	  Q.push(temp);
	 	  S.push(temp);
	 	  m=m/t;
	 	  
	 	}while(m>0);

     while(!Q.empty())
     {
          if(S.top()!=Q.front())return false;
          S.pop();
          Q.pop();
     }

 	 return true;
}



