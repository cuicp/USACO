#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

const long INF=100000000;

int main()
{
    double a[4][3];
    double k1,k2,k3,a1=9,a2,a3;
    long min=INF;
    
    ifstream fin("ratios.txt");
    
    for(int i=0;i<4;++i)
        fin>>a[i][0]>>a[i][1]>>a[i][2];

        
    for(int i=0;i<100;++i)
    {
         for(int j=0;j<100;++j)
         {
              for(int k=0;k<100;++k)
              {
                     k1=(i*a[1][0]+j*a[2][0]+k*a[3][0])/a[0][0];
                     k2=(i*a[1][1]+j*a[2][1]+k*a[3][1])/a[0][1];
                     k3=(i*a[1][2]+j*a[2][2]+k*a[3][2])/a[0][2];
 
                     if(floor(k1)!=k1)continue;
                     if(k1==k2&&k2==k3&&k1!=0)
                     {
                           if(k1<min)
                           {
                               min=k1;
                               a1=i;
                               a2=j;
                               a3=k;
                           }                     
                                       
                     }  
                      
              }   
              
         }   
            
    }
    
    if(min<100)
        cout<<a1<<' '<<a2<<' '<<a3<<' '<<min<<endl;
    else cout<<"NONE"<<endl;
    

    system("pause");
    return 0;
}
