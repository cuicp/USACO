#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    int N,num=1;
    
    ifstream fin("fact4.txt");

    
    fin>>N;
    
    for(int i=1;i<=N;++i)
    {
         num*=i;
         
         while(num/10*10==num)
         {
             num/=10;
         }
         
         num%=100000000;
    }
    

    cout<<(num%10)<<endl;
    
    
    system("pause");
    return 0;
}
