/*
ID:cui chengpeng
PROG:crypt1
LANG:C++
*/

#include<iostream>
#include<fstream>
using namespace std;
#define M 9
int BAO_HAN(int a[],int nu,int t);
int IS(int a[],int SHU_ZHI,int nu);//判断a【】中是否包含SHU_ZHI 
int ZHU_HE_3(int a,int b,int c);//将a b c组合成一个三位数 
int ZHU_HE_2(int a,int b);//将a b c组合成一个三位数 
int main()
{
    int i,j,k,m,n,nu,a[M],A,B,C,D,E,count=0;
    
    ifstream fin("crypt1.in");
    ofstream fout("crypt1.out");
    
    fin>>nu;
    for(i=0;i<nu;i++)
         fin>>a[i];
         
    for(i=0;i<nu;i++)
        for(j=0;j<nu;j++)
            for(k=0;k<nu;k++)
            { 
                A=ZHU_HE_3(a[i],a[j],a[k]);
                for(m=0;m<nu;m++)
                    for(n=0;n<nu;n++)
                    {
                        B=ZHU_HE_2(a[m],a[n]);
                        
                       
                        C=A*a[n];
                        if(C>=1000)continue;
                        D=A*a[m];
                        if(D>=1000)continue;
                        E=A*B;
                        if(E>=10000)continue;
                        
                        
                        
                        if(IS(a,C,nu)&&IS(a,D,nu)&&IS(a,E,nu))
                        count++;  
            
                    }
                 
                    
            }
   
    fout<<count<<endl;
    
    return 0;
}




int BAO_HAN(int a[],int nu,int t)
{
    int i;
    for(i=0;i<nu;i++)
        if(a[i]==t)
        break;
        
    if(i==nu)
    return 0;
    return 1;
}


int IS(int a[],int SHU_ZHI,int nu)//判断a【】中是否包含SHU_ZHI 
{
    int b[M],i=0,j,k;
    do{
        b[i]=SHU_ZHI%10;
        SHU_ZHI=SHU_ZHI/10;
        i++;
    }while(SHU_ZHI>0);
    
    for(j=0;j<i;j++)
    {
        if(BAO_HAN(a,nu,b[j])==0)
        break;
    }
    if(j==i)
    return 1;
    return 0;
    
}

int ZHU_HE_3(int a,int b,int c)//将a b c组合成一个三位数 
{
    int s;
    s=100*a+10*b+c;
    return s;
}
int ZHU_HE_2(int a,int b)//将a b c组合成一个三位数 
{
    int s;
    s=10*a+b;
    return s;
}
