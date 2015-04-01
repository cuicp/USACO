/*
ID:cuichengpeng
PROG:fracdec
LANG:C++
*/ 
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
const int MAX=100000;
string Itoa(int n)
{
    char ch;
    string s;
    while(n>=10)
    {
        ch=n%10+'0';
        s=ch+s;
        n=n/10;
    }
    ch=n+'0';
    s=ch+s;
    return s;
}
int main()
{
    int i,j,k;
    ifstream fin("fracdec.in");
    ofstream fout("fracdec.out");
    
    int N,D;
    fin>>N>>D;

    int hash[MAX];//hash[i]表示第一次产生余数i的位置 
    int M_A[MAX];//M_A[i]表示进行第i次除法所得到的数字 
    int M_N[MAX];//M_A[i]表示进行第i次除法所得到的余数 
    
    for(i=0;i<MAX;++i)hash[i]=-1;
    M_A[0]=N/D;
    M_N[0]=N-M_A[0]*D;
    hash[M_N[0]]=0;

    i=0;
    while(M_N[i]!=0)
    {
        M_A[i+1]=10*M_N[i]/D;
        M_N[i+1]=10*M_N[i]-M_A[i+1]*D;
        if(hash[M_N[i+1]]!=-1)break;
        else hash[M_N[i+1]]=i+1;
        i++;
    }

    string S;
    if(M_N[i]==0)
    {
        S=Itoa(M_A[0]);
        S+='.';
        for(j=1;j<=i;++j)S+=Itoa(M_A[j]); 
        if(i==0)S+='0';              
    }
    else
    {
        S=Itoa(M_A[0]);
        S+='.';
        for(j=1;j<=i;++j)
        {
            if(j==hash[M_N[i+1]]+1)S+='(';
            S+=Itoa(M_A[j]);
        }
        S+=Itoa(M_A[i+1]);
        S+=')';
    }
    
    
    for(i=0;i<S.size();++i)
    {
        fout<<S[i];
        if((i+1)%76==0)fout<<endl;
    }
    if(i%76!=0)fout<<endl;
    
 //   system("pause");
    return 0;
}
