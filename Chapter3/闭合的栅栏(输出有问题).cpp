#include<iostream>
#include<fstream>
using namespace std;
typedef struct{
        double x;//横坐标 
        double y;//纵坐标 
        }Point;
typedef struct{
        Point s;//起点 
        Point e;//终点 
        }Line; 

const double ENS=0.01; 
const int M=200;
Line L[M];
Point S;//人的位置
int N;
bool flag;
//计算(p1-p0)与(p2-p0)的叉积 
double  CrossProduct(Point p0,Point p1,Point p2);
//判断ls1和ls2是否规范相交
bool StandardIntersect(Line ls1,Line ls2);
//判断P1,P2之间的线段是否可以被看见,若是则将flag标记为true 
void Visible(Point P1,Point P2,int n); 


int main()
{
    ifstream fin("fence4.txt");

    
    fin>>N;
    fin>>S.x>>S.y;
    
    Line L1,L2;
    L1.s.x=1;L1.s.y=1;
    L1.e.x=5;L1.e.y=5;
    L2.s.x=1;L2.s.y=5;
    L2.e.x=5;L2.e.y=1;
    

    
    fin>>L[0].s.x>>L[0].s.y;
    fin>>L[0].e.x>>L[0].e.y;
    for(int i=1;i<N-1;++i)
    {
        L[i].s.x=L[i-1].e.x;
        L[i].s.y=L[i-1].e.y;
        fin>>L[i].e.x>>L[i].e.y;
    }
    L[N-1].s.x=L[N-2].e.x;
    L[N-1].s.y=L[N-2].e.y;
    L[N-1].e.x=L[0].s.x;
    L[N-1].e.y=L[0].s.y;
    
    
    //检验该栅栏是否合法 
    for(int i=1;i<N;++i) 
    {//检验第i条线段是否与前i-1条相交
        for(int j=i-1;j>=0;--j)
        {
            if(StandardIntersect(L[i],L[j]))
            {
                cout<<"NOFENCE"<<endl;
                system("pause");
                return 0;
            }
        }
    }
    
    
    //计算能被看到的栅栏 
    for(int i=0;i<N;++i)
    {
        flag=false;
        Visible(L[i].s,L[i].e,i);
        if(flag)
        {
            cout<<L[i].s.x<<' '<<L[i].s.y<<' '<<L[i].e.x<<' '<<L[i].e.y<<endl;
        }
    }


    system("pause");
    return 0;
}
double  CrossProduct(Point p0,Point p1,Point p2)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
bool StandardIntersect(Line ls1,Line ls2)
{
    double k1,k2,k3,k4;
    k1=CrossProduct(ls1.s,ls2.s,ls1.e);
    k2=CrossProduct(ls1.s,ls2.e,ls1.e);
    k3=CrossProduct(ls2.s,ls1.s,ls2.e);
    k4=CrossProduct(ls2.s,ls1.e,ls2.e);
    
    
    if(k1*k2<0&&k3*k4<0)return true;
    return false;
}
void Visible(Point P1,Point P2,int n)
{
     if((P1.x-P2.x)*(P1.x-P2.x)+(P1.y-P2.y)*(P1.y-P2.y)<ENS)return ;
     
     Point mid;
     mid.x=(P1.x+P2.x)/2;
     mid.y=(P1.y+P2.y)/2;
     
     Line SM;
     SM.s=S;
     SM.e=mid;
     
     int i;
     for(i=0;i<N;++i)
     {
          if(i==n)continue;
          if(StandardIntersect(L[i],SM))
              break;
     }
     if(i>=N)
     {
             flag=true;
             return ;
     }
     else
     {
         Visible(P1,mid,n);
         if(flag)return ;
         Visible(mid,P2,n);
     }
}
