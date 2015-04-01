/*
ID:cui chengpeng
PROG:calfflac
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
using namespace std;
int Front(int n);
int Next(int n);
const int M=21000;
string s;
int main()
{
    ifstream fin("calfflac.in");
    ofstream fout("calfflac.out");

    string temp;
    int t=0;
    while(getline(fin,temp))
    {
        s+=temp;
        s+='\n';
    }

    int lenth=s.size();
    lenth-=2;
    int count,max=0,p,q,n,m;
    string maxstr;
    for(int i=1;i<lenth;++i)
    {
        if(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z')
        {
            p=Front(i),q=Next(i);
            count=1;
            while(p>=0&&q<s.size()&&(s[p]==s[q]||s[p]-s[q]==32||s[q]-s[p]==32))
            {
                count+=2;
                p=Front(p);
                q=Next(q);
            }
            if(count>max)
            {
                max=count;
                maxstr.clear();
                n=Next(p);
                m=Front(q)-n;
            
                maxstr.insert(0,&s.c_str()[n],m+1);
            }
            
            
            p=i,q=Next(i);
            count=0;
            while(p>=0&&q<s.size()&&(s[p]==s[q]||s[p]-s[q]==32||s[q]-s[p]==32))
            {
                count+=2;
                p=Front(p);
                q=Next(q);
            }
            if(count>max)
            {
                max=count;
                maxstr.clear();
                n=Next(p);
                m=Front(q)-n;
                maxstr.insert(0,&s.c_str()[n],m+1);
            }  
        }
    }
    
    fout<<max<<endl;

    fout<<maxstr<<endl;
    

    
  //  system("pause");
    return 0;
}
int Front(int n)
{
    int i;
    
    for(i=n-1;i>-1;--i)
    {
        if(s[i]>='A'&&s[i]<='Z'||s[i]>='a'&&s[i]<='z')break;
    }
    return i;
}
int Next(int n)
{
    int i;
    for(i=n+1;i<s.size();++i)
    {
        if(s[i]>='A'&&s[i]<='Z'||s[i]>='a'&&s[i]<='z')break;
    }
    return i;
}
