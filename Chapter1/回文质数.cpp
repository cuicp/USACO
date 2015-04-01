/*
ID:cui chnegpeng
PROG:pprime
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
#define M 100000000
int ISP(unsigned m);
int ISH(int n);
int main()
{
    unsigned long i,MIN,MAX;
    ifstream fin("pprime.in");
    ofstream fout("pprime.out");
    fin>>MIN>>MAX;
    
    for(i=MIN;i<MAX;i++)
        if(ISP(i))
        {
               if(ISH(i))
               fout<<i<<endl;
        }
    
    
    return 0;
}    
    
int ISP(unsigned m)
{
    unsigned int i,t;
    if(m%2==0)  return 0;
    i=3;
    t=(unsigned int)sqrt(m)+1;
    while(i<=t){
        if(m%i==0) return 0;
        i+=2; 
        }
    return 1;
    
}
int ISH(int m)
{
    int A[10],i=0,j;
    do{
          A[i++]=m%10;
          m=m/10;  
          
    }while(m!=0);
    for(j=0;j<i/2;j++)
        if(A[j]!=A[i-1-j])
            break;
    if(j==i/2)
        return 1;
    return 0;
       
}












