/*
ID: cui chengpeng
PROG: ride
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    ofstream  fout ("ride.out");
    ifstream  fin  ("ride.in");
    string a,b;
    while(fin>>a>>b)
    {
    int suma=1,sumb=1;
    for(int i=0;i<a.size();i++)
    {
        suma*=(a[i]-'A'+1);
    }
    suma%=47;
    for(int i=0;i<b.size();i++)
    {
        sumb*=(b[i]-'A'+1);
    }
    sumb%=47;
    if(suma==sumb)
        fout<<"GO"<<endl;
    else
        fout<<"STAY"<<endl;
    }
    return 0;
}
