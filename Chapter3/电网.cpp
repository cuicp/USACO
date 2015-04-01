/*
ID:cuichengpeng
PROG:fence9
LANG:C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)return a;
    else return gcd(b,a%b);
}
int main()
{
    ifstream fin("fence9.in");
    ofstream fout("fence9.out");

    int n,m,p;
    fin>>n>>m>>p;
    int s=p*m/2;
    int b1=gcd(max(m,n),min(m,n));
    int b2=gcd(p,0);
    int b3=gcd(max(abs(n-p),m),min(abs(n-p),m));
    int b=b1+b2+b3;
    
    fout<<s-b/2+1<<endl;
    //system("pause");
    return 0;
}
