/*
    ID:cui chnegpeng
    PROG:milk2
    LANG:C++
*/
#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;

const int M=5001; 
int main()
{
 	//time1用来记录无人挤奶时间段，time2用来记录有人段,impoint用来记录关键时间点 
 	 int i,j,t=0,n,time1=0,time2=0,START[M],END[M],important[M];
	 ifstream fin("milk2.in");
	 ofstream fout("milk2.out");
	 fin>>n;
	 for(i=1;i<=n;++i){fin>>START[i]>>END[i];}
	 
	 
	 for(i=1;i<=n;++i)
	 {
         for(j=1;j<=n;++j)
         {
  		     if(END[j]<START[i]||START[j]>=START[i]);
  		     else break;
  		 }
  		 if(j>n)important[++t]=START[i];
	 }



	 for(i=1;i<=n;++i)
	 {
         for(j=1;j<=n;++j)
         {
  		     if(END[j]<=END[i]||START[j]>END[i]);
  		     else break;
  		 }
  		 if(j>n)important[++t]=END[i];
	 }
	 
	 sort(important+1,important+t);
	 	 
	 for(i=2;i<=t;i+=2)
	 {
          if(important[i+1]-important[i]>time1)time1=important[i+1]-important[i];
          if(important[i]-important[i-1]>time2)time2=important[i]-important[i-1];
     }
     
     fout<<time2<<' '<<time1<<endl;

 	return 0;
}
