/*
ID: cui chengpeng
LANG: C++
TASK: palsquare
*/
#include <iostream>
#include <fstream>
using namespace std;
 int main(){
 char a[]="0123456789ABCDEFGHIJ";
 char b[200],c[200];
 long i,j,k,m,n,p;
 bool hash;
 ifstream fin("palsquare.in");
 ofstream fout("palsquare.out");

 fin>>n;
 for(i=1;i<=300;i++){
 m=i;
 k=1;
 while(m!=0){
 c[k]=a[m%n];
 m=m/n;
 k++;
 } 
 p=k-1;

 m=i*i;
 k=1;
 while(m!=0){
 b[k]=a[m%n];
 m=m/n;
 k++;
 }

 k--;hash=0;
 for(j=1;j<=k/2;j++) if(b[j]!=b[k-j+1]) hash=1;
 if(hash==0) {
 for(j=p;j>=1;j--) fout<<c[j];
 fout<<" ";
 for(j=k;j>=1;j--) fout<<b[j];
 fout<<endl;
 } 
 }
 fin.close();
 fout.close();
 return 0;
 }

