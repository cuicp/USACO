/*
ID:cuichnegpneg
PROG:skidesign
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<algorithm>
const int M=1000;
using namespace std;
bool compare(int a,int b)
{
    return a<b;
}
int main()
{
    ifstream fin("skidesign.in");
    ofstream fout("skidesign.out");
    
    
    int temp,N,A[M];
    fin>>N;
    for(int i=0;i<N;++i)fin>>A[i];
    
    sort(A,A+N,compare);
    
    double min_cost=10000000;
    int m=84;
    for(int i=0;i<m;++i)
    {
        temp=0;
        for(int j=0;A[j]<i&&j<N;++j)
        {
            temp+=(A[j]-i)*(A[j]-i);
        }
        int high=i+17;
        for(int j=N-1;j>=0&&A[j]>high;--j)
        {
            temp+=(A[j]-high)*(A[j]-high);
        }
        if(temp<min_cost)min_cost=temp;
    } 
    
    fout<<min_cost<<endl;
    
    //system("pause");
    return 0;
} 
