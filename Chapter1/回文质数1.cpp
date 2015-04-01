/*
ID:cui chengpeng
PROG:pprime
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
void change(char a[])
{
     int m,n;
     m=strlen(a);
     n=m/2;
     for(int i=0;i<n;++i)
     {
         char temp=a[i];
         a[i]=a[m-1-i];
         a[m-1-i]=temp;
     }
}
int is_prime(unsigned m)
{
    unsigned int i,t;
    if(m%2==0)  return 0;
    i=3;
    t=(unsigned int)sqrt(m)+1;
    while(i<=t){
        if(m%i==0) return 0;
        i+=2; 
        }
    return 1;
    
}
void Itoa(int n,char a[])
{
     int t=0;
     while(n>0)
     {
         a[t++]=n%10+'0';
         n/=10;
     }
     a[t]='\0';
     change(a);
}
int main()
{
    ifstream fin("pprime.in");
    ofstream fout("pprime.out");
/*
char tem[10],tem1[10];
                Itoa(12345,tem);
                strcpy(tem1,tem);
                
                change(tem1);
                cout<<tem<<endl<<tem1<<endl;
                strcat(tem,tem1);
cout<<tem<<endl;
system("pause");
*/


    
    long a,b;
    fin>>a>>b;

    vector<int>V;
    
    int n,p,q;
    char s[10],temp[10];
    
    
    for(int i=5;i<10;++i)V.push_back(i);
    for(int i=2;i<=8;++i)//回文数的位数递增
    {
        if(i%2==1)
        {
            n=i/2;
            q=pow(10.0,n);
            p=q/10;
            
            for(int j=p;j<q;++j)
            {
                Itoa(j,s);

                strcpy(temp,s);
                change(temp);
                
                for(int k=0;k<10;++k)
                {
                    s[n]=k+'0';s[n+1]='\0';
                    strcat(s,temp);
                    V.push_back(atoi(s));
                }
            }
        }
        else
        {
            n=i/2;
            q=pow(10.0,n);
            p=q/10;
            
            for(int j=p;j<q;++j)
            {
                Itoa(j,s);
                strcpy(temp,s);
                change(temp);
                
                strcat(s,temp);
                V.push_back(atoi(s));
            }
        }
    } 
    
 //   sort(V.begin(),V.end());
    n=V.size();
    
    for(int i=0;i<n;++i)
    {
        if(V[i]>b)break;    
        if(is_prime(V[i]))
        {
            if(V[i]>=a&&V[i]<=b)
                fout<<V[i]<<endl;
        }
    }

  //  system("pause");
    return 0;
}
