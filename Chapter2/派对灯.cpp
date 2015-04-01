/*
ID:cui chengpeng
PROG:lamps
LANG:C++
*/
#include<iostream>
#include<fstream>
using namespace std;

int light[102],a[102],b[102];//light用来存储灯的亮灭情况，a和b用来记录所给的灯的亮灭情况 
bool flag=false;


void Lamps(int N,int C);
void Home(int N);
void Switch(int n,int N);
void Output(int N);
bool match();
ifstream fin("lamps.in");
ofstream fout("lamps.out");
int main()
{
 	int N,C,n,i;

 	
 	fin>>N>>C;
 	
 	for(i=1;i<=N;++i)
    {
		light[i]=1;
		a[i]=0;
		b[i]=0;
    } 
 	
 	
 	i=0;
	fin>>n;
	while(n!=-1)
	{
	    a[++i]=n;
	    fin>>n;
	}
 	
 	
 	i=0;
	fin>>n;
	while(n!=-1)
	{
	    b[++i]=n;
	    fin>>n;
	}
 	
 	
	Lamps(N,C);
	
	if(!flag)fout<<"IMPOSSIBLE"<<endl;
 	
 //	system("pause");
 	return 0;
}


void Lamps(int N,int C)
{
    int k1,k2,k3,k4;
 	 
    if(C==1)
 	{
		for(k1=0;k1<=1;++k1)
		    for(k2=0;k2<=1;++k2)
		        for(k3=0;k3<=1;++k3)
		            for(k4=0;k4<=1;++k4)
		            {
					 	Home(N);				
					 					
					 	if((k1+k2+k3+k4)==1)
						{
						 	if(k1==1)Switch(1,N);
							if(k2==1)Switch(2,N);
							if(k3==1)Switch(3,N);
							if(k4==1)Switch(4,N);	
							
							if(match()){Output(N);flag=true;}
 					    }
  
		            }
					      
    }
 	else if(C==2)
 	{
        //有2个按钮按了奇数次
		for(k1=0;k1<=1;++k1)
		    for(k2=0;k2<=1;++k2)
		        for(k3=0;k3<=1;++k3)
		            for(k4=0;k4<=1;++k4)
		            {
                        Home(N);
							
					 	if((k1+k2+k3+k4)==2)
						{
						 	if(k1==1)Switch(1,N);
							if(k2==1)Switch(2,N);
							if(k3==1)Switch(3,N);
							if(k4==1)Switch(4,N);	
							
						    if(match()){Output(N);flag=true;}	
 					    }	
						 		
		            }
		            
    }
 	else
 	{
	 	if(C%2==0)
	 	{
		 	//有2个或4个按钮按了奇数次
			for(k1=0;k1<=1;++k1)
			    for(k2=0;k2<=1;++k2)
			        for(k3=0;k3<=1;++k3)
			            for(k4=0;k4<=1;++k4)
			            {
						 	if((k1+k2+k3+k4)==2||(k1+k2+k3+k4)==4)
							{
							 	Home(N);	
								 								  
							 	if(k1==1)Switch(1,N);
								if(k2==1)Switch(2,N);
								if(k3==1)Switch(3,N);
								if(k4==1)Switch(4,N);	
								
								if(match()){Output(N);flag=true;}	
	 					    }				
			            }				   
			   					  
	    }
		else
		{
		 	for(k1=0;k1<=1;++k1)
			    for(k2=0;k2<=1;++k2)
			        for(k3=0;k3<=1;++k3)
			            for(k4=0;k4<=1;++k4)
			            {
						 	if((k1+k2+k3+k4)==1||(k1+k2+k3+k4)==3)
							{
							 	Home(N);									  
							 									  
							 	if(k1==1)Switch(1,N);
								if(k2==1)Switch(2,N);
								if(k3==1)Switch(3,N);
								if(k4==1)Switch(4,N);	
								
								if(match()){Output(N);flag=true;}	
	 					    }				
			            }			
 	    }
		            
    }
    
}
void Home(int N)
{
 	 for(int i=1;i<=N;++i)light[i]=1;
}
void Switch(int n,int N)
{
 	 int k;
 	 
 	 if(n==1)
 	 {
	  	 for(int i=1;i<=N;++i)
		 {
		      if(light[i]==0)light[i]=1;
		      if(light[i]==1)light[i]=0;
		 }	 
     }
     else if(n==2)
     {
         for(int i=1;i<=N;i+=2)
  		 {
		      if(light[i]==0)light[i]=1;
		      if(light[i]==1)light[i]=0;
		 }	 
         
     }
     else if(n==3)
     {
         for(int i=2;i<=N;i+=2)
  		 {
		      if(light[i]==0)light[i]=1;
		      if(light[i]==1)light[i]=0;
		 }	 
     }
     else
     {
         for(int i=0,k=3*i+1;k<=N;++i,k=3*i+1)
  		 {
		      if(light[k]==0)light[k]=1;
		      if(light[k]==1)light[k]=0;
		 }	 
 	 }
}
void Output(int N)
{
 	 for(int i=1;i<=N;++i)fout<<light[i];fout<<endl;
}
bool match()
{
 	 int i;
 	 
 	 for(i=1;a[i]!=0;++i)
 	 {
	  	 if(light[a[i]]==0)return false;				 
     }
     
 	 for(i=1;b[i]!=0;++i)
 	 {
	  	 if(light[b[i]]==1)return false;				 
     }
 	 
 	 return true;
}





