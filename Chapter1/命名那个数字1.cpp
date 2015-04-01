/*
ID:cui chengpeng
PROG:namenum
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<string> 
#include<map>
using namespace std;

int main()
{
    ifstream fin("namenum.in");
    ifstream fin1("dict.txt");
    ofstream fout("namenum.out");
    
    map<char,char>M;
    
    M['A']='2';M['B']='2';M['C']='2';
    M['D']='3';M['E']='3';M['F']='3';
    M['G']='4';M['H']='4';M['I']='4';
    M['J']='5';M['K']='5';M['L']='5';
    M['M']='6';M['N']='6';M['O']='6';
    M['P']='7';M['R']='7';M['S']='7';
    M['T']='8';M['U']='8';M['V']='8';
    M['W']='9';M['X']='9';M['Y']='9';
    
    
    string num;
    fin>>num;
    
    int count=0;
    
    string s;
    while(getline(fin1,s))
    {
         string temp;
         int len=s.length();
         
         for(int i=0;i<len;++i)
         {
              temp+=M[s[i]];   
         }

         if(temp==num)
         {
             fout<<s<<endl;
             count++;
         }

    }
    
    if(count==0)
    {
        fout<<"NONE"<<endl;
    }

 //   system("pause");
    return 0;
}
