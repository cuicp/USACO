/*
ID:cui chengpeng
PROG:frac1
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

typedef struct fractions{
		
		int x;//���� 
		int y;//��ĸ 
		double s;//��÷����ȼ۵�С�� 
		}fractions;

fractions a[100000];

bool cmp(const fractions &s1,const fractions &s2)
{
    if(s1.s==s2.s)
    {
        return s1.y<s2.y;
    }
    else return s2.s>s1.s;
}
void Qsort(fractions A[],int p,int r);
int Partition(fractions A[],int p,int r);


int main()
{
 	int i,j,t,n,m;
    ifstream fin("frac1.in");
    ofstream fout("frac1.out");
	fin>>n;
	
	m=n*(n-1)/2+2;
	
	t=0;
	for(i=1;i<=n;++i)//iΪ��ĸ
	    for(j=1;j<i;++j)
		{
		 	a[t].x=j;
			a[t].y=i;
			
		//	if((i%j==0)&&(j!=1))a[t].s=0;
		//	else
             a[t].s=(double)j/i;
			
			++t;
						
		} 
	sort(a,a+m,cmp);
//	Qsort(a,0,m-1);
	
	fout<<"0/1"<<endl;
 	for(i=0;i<m;++i)
    {
		if(a[i].s>0)
		{
		    if(a[i].s!=a[i-1].s)
		    {
		        fout<<a[i].x<<'/'<<a[i].y<<endl;
            }
		    
		}
	} 
	fout<<"1/1"<<endl;
 	
 	
// 	system("pause");
 	return 0;
}

void Qsort(fractions A[],int p,int r)
{
 	 int q;
 	 if(p<r)
 	 {
	  		q=Partition(A,p,r);
	  		Qsort(A,p,q-1);
	  		Qsort(A,q+1,r);
     }
}
int Partition(fractions A[],int p,int r)
{
 	int i,j;
 	fractions temp,x;
 	
 	x=A[r];
 	i=p-1;
 	
 	for(j=p;j<=r-1;++j)
 	{
	 	if(A[j].s<=x.s)
		{
		 	++i;
			
			temp=A[i];
			A[i]=A[j];
			A[j]=temp;	   
        }			   
    }
    
    temp=A[i+1];
    A[i+1]=A[r];
    A[r]=temp;
    
    return i+1;
 	
}
