/*
ID:cui chengpeng
PROG:sprime
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
using namespace std;
bool is_prime(int m)
{
     int t=sqrt(m)+1;
     
     if(m%2==0)return false;
     for(int i=3;i<t;i+=2)
     {
          if(m%i==0)return false;
     }    
     return true;
}
int main()
{
    ifstream fin("sprime.in");
    ofstream fout("sprime.out");
    vector<vector<int> >V;
    vector<int>temp;
    
    temp.push_back(2);
    temp.push_back(3);
    temp.push_back(5);
    temp.push_back(7);
    
    int N;
    fin>>N;
    V.push_back(temp);
    V.push_back(temp);

    for(int i=2;i<=N;++i)
    {
        temp.clear();   
        for(int j=0;j<V[i-1].size();++j)
        {
            int m=V[i-1][j]*10;

            for(int k=1;k<10;k+=2)
            { 
                 if(is_prime(m+k))
                     temp.push_back(m+k);   
            }
        }
        V.push_back(temp);

    }
        
    
    
    for(int i=0;i<V[N].size();++i)
    {
        fout<<V[N][i]<<endl;
    }
    
  //  system("pause");
    return 0;
}
