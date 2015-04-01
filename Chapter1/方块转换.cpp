/*
ID:cui chengpeng
PROG:transform
LANG:C++
*/
#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

bool Transform(int n);

int m,m2;
char S[1000],E[1000],S1[100000],temp[12][12];

int main()
{
 	int i;
 	ifstream fin("transform.in");
 	ofstream fout("transform.out");
 	
 	
 	fin>>m;
 	m2=m*m;
 	
 	for(i=0;i<m2;++i)fin>>S[i];
 	for(i=0;i<m2;++i)fin>>E[i];
 	
 	strcpy(S1,S);
 	
 	for(i=1;i<=6;++i)
 	{
	     strcpy(S,S1);
	     if(Transform(i))break;
	}
 	
 	
 	fout<<i<<endl;
 	
 	//system("pause");
 	return 0;
}

bool Transform(int n)
{
 	 int i,j,t=-1;
 	 char ch;

 	 if(n==1)
 	 {
	 	 for(j=m-1;j>=0;j--)
	 	     for(i=0;i<m;++i)
	 	     {
		          temp[i][j]=S[++t];
		     }
		     
         t=-1;
		     
         for(i=0;i<m;++i)
             for(j=0;j<m;++j)
             {
			  	  S[++t]=temp[i][j];		 
			 }
     }
     else if(n==2)
     {
	  	  Transform(1);
	  	  Transform(1);
     }
     else if(n==3)
     {
	  	  Transform(1);
	  	  Transform(1);
	  	  Transform(1);
     }
     else if(n==4)
     {
	  	  for(i=0;i<m;++i)
	  	      for(j=0;j<m/2;j++)
	  	      {
 					ch=temp[i][j];
 					temp[i][j]=temp[i][m-j-1];
 					temp[i][m-j-1]=ch;
			  }
			  
         t=-1;
         for(i=0;i<m;++i)
         for(j=0;j<m;++j)
         {
	    	  S[++t]=temp[i][j];		 
		 }
		  if(strcmp(S,E)==0)return true;
		  	  	  
          for(i=0;i<m;++i)
          for(j=0;j<m/2;j++)
          {
 				ch=temp[i][j];
				temp[i][j]=temp[i][m-j-1];
				temp[i][m-j-1]=ch;
		  }
 	      for(j=0;j<m;++j)
 	      for(i=0;i<m/2;i++)
 	      {
				ch=temp[i][j];
				temp[i][j]=temp[m-i-1][j];
				temp[m-i-1][j]=ch;
		  }
		  
		  t=-1;
		  for(i=0;i<m;++i)
          for(j=0;j<m;++j)
          {
			  S[++t]=temp[i][j];		 
		  }

     }
     else if(n==5)
     {
  	      for(j=0;j<m;++j)
 	      for(i=0;i<m/2;i++)
 	      {
				ch=temp[i][j];
				temp[i][j]=temp[m-i-1][j];
				temp[m-i-1][j]=ch;
		  }
		  
		     t=-1;
		     for(i=0;i<m;++i)
             for(j=0;j<m;++j)
             {
			  	  S[++t]=temp[i][j];		 
			 }
  	      if(Transform(1))return true;
  	      if(Transform(1))return true;
  	      if(Transform(1))return true;
  	      
  	      Transform(1);
  	      for(j=0;j<m;++j)
 	      for(i=0;i<m/2;i++)
 	      {
				ch=temp[i][j];
				temp[i][j]=temp[m-i-1][j];
				temp[m-i-1][j]=ch;
		  }
             
             t=-1;
             for(i=0;i<m;++i)
             for(j=0;j<m;++j)
             {
			  	  S[++t]=temp[i][j];		 
			 }
   	  	  for(i=0;i<m;++i)
  	      for(j=0;j<m/2;j++)
  	      {
 			  ch=temp[i][j];
 			  temp[i][j]=temp[i][m-j-1];
 			  temp[i][m-j-1]=ch;
		  }
           	      
     }
     else
     {
	  	 
 	 }
 	 
 	 if(strcmp(S,E)==0)return true;
 	 return false;
 	 
}
