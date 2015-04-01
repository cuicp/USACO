/*
ID: happy_c1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include<algorithm>
using namespace std;main()
{
      ofstream fout ("milk2.out");
      ifstream fin ("milk2.in");
      int n,i,j,begin[5000],end[5000];
      long int max=0,temp=0,maxzero=0,tempzero=0;
      static int flag[2000001];
      for(i=0;i<=2000000;i++)flag[i]=0;
      
      fin>>n;
      for(i=0;i<n;i++)
      {
         fin>>begin[i]>>end[i];
         for(j=2*begin[i];j<=2*end[i];j++)flag[j]=1;
      }
if(n==1)fout<<end[0]-begin[0]<<" 0"<<endl;
else
{
      sort(begin,begin+n);
      sort(end,end+n);
      i=2*begin[0];
      while(i<=2*end[n-1])
      {
          if(flag[i]==1||(flag[i]==1&&flag[i-1]==-1))
            {max++;flag[i]=-1;i++;}
          else if(flag[i]==0&&flag[i-1]==-1)break;
      }max--;
x:   {
      for(;i<=2*end[n-1];i++)
      if(flag[i]==1)break;
      while(i<=2*end[n-1])
      {
          if(flag[i]==1||(flag[i]==1&&flag[i-1]==-1))
            {temp++;flag[i]=-1;i++;}
          else if(flag[i]==0&&flag[i-1]==-1)break;
      }temp--;
      if(temp>max)max=temp;
      temp=0;
     }
      if(i<2*end[n-1])goto x; 
      max=max/2;
      //for(i=300;i<=2100;i++)cout<<"#"<<i<<" "<<flag[i]<<"# ";cout<<endl;
      
      for(i=2*begin[0];i<=2*end[n-1];i++)
      if(flag[i]==0)break;//cout<<i<<endl;
      while(i<=2*end[n-1])
      {
          if(flag[i]==0||(flag[i]==0&&flag[i-1]==-2))
            {maxzero++;flag[i]=-2;i++;}
          else if(flag[i]==-1&&flag[i-1]==-2)break;
      }maxzero++;
y:   {
      for(;i<=2*end[n-1];i++)
      if(flag[i]==0)break;
      while(i<=2*end[n-1])
      {
          if(flag[i]==0||(flag[i]==0&&flag[i-1]==-2))
            {tempzero++;flag[i]=-2;i++;}
          else if(flag[i]==-1&&flag[i-1]==-2)break;
      }tempzero++;
      if(tempzero>maxzero)maxzero=tempzero;
      tempzero=0;
     }
      if(i<2*end[n-1])goto y; 
      maxzero=maxzero/2;
      fout<<max<<" "<<maxzero<<endl;
}
      return 0;
}
