/*
ID:cui chengpeng
PROG:friday
LANG:C++
*/
#include<iostream>
#include<fstream> 

using namespace std; 

   

int main() 

{ 

 

int year,month,i,n,last=3; 

 

 

 

 

int dayOfMonth[12]={31,31,28,31,30,31,30,31,31,30,31,30}; 

 

 

 

 

 

int result[7]={0}; 

 

 

 

 

 

 

 

 

 

 

 

ifstream fin("friday.in"); 

 

ofstream fout("friday.out"); 

  

 

fin>>n; 

  

 

for(year=1900;year<1900+n;++year){  









 

 

if(year%400==0||(year%100!=0&&year%4==0)) dayOfMonth[2]=29; 

 

 

for(month=0;month<12;++month){ 

 

 

 

last=(last+dayOfMonth[month])%7; 

 

 

 

result[last]++; 

 

 

}  

 

 

dayOfMonth[2]=28;  

 

}  

  

 

for(i=0;i<6;++i) fout<<result[(i+6)%7]<<' '; 

 

fout<<result[5]<<endl; 

  

 

fin.close(); 

 

fout.close(); 

  

 

return 0;  

} 

  
