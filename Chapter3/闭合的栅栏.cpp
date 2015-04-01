/*
ID:cuichengpeng
PROG:fence4
LANG:C++
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <climits>
#include <cstring>
#define EPS 1e-6
const int M=220;
using namespace std;

class point
{
    public:
        point(){};
        point(double tx, double ty):x(tx), y(ty) {}
        double x, y;
};
 
class seg
{
    public:
        seg(){}
        seg(point a, point b) {s = a; t = b;}
        point s, t;
};
 
double dist(point a, point b)
{
    return (sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)));
}
 
double multiply(point sp, point ep, point op)
{
    return (((sp.x - op.x) * (ep.y - op.y)) - ((sp.y - op.y) * (ep.x - op.x)));
}
 
bool checkOnline(seg l, point p)
{
    return ((multiply(l.s, p, l.t) == 0) &&
            (((p.x - l.s.x) * (p.x - l.t.x) <= 0) &&
             ((p.y - l.s.y) * (p.y - l.t.y) <= 0)));
}
 
point midPoint(point a, point b)
{
    return point((a.x + b.x) / 2, (a.y + b.y) / 2);
}
 
bool intersect(seg a, seg b)
{
    return ((max(a.s.x, a.t.x) >= min(b.s.x, b.t.x)) &&
            (max(b.s.x, b.t.x) >= min(a.s.x, a.t.x)) &&
            (max(a.s.y, a.t.y) >= min(b.s.y, b.t.y)) &&
            (max(b.s.y, b.t.y) >= min(a.s.y, a.t.y)) &&
            (multiply(b.s, a.t, a.s) * multiply(a.t, b.t, a.s) >= 0) &&
            (multiply(a.s, b.t, b.s) * multiply(b.t, a.t, b.s) >= 0));
}
 
bool intersect_A(seg a, seg b)
{
    return ((intersect(a, b)) && (!checkOnline(a, b.s)) &&
            (!checkOnline(a, b.t)) && (!checkOnline(b, a.s)) &&
            (!checkOnline(b, a.t)));
}
//---------------------以上是模板----------------------------

int N,count=0;   //count为可以看到的线段数 
point P[M],me; //点 
seg S[M];      //线段 
bool can[M];   //can[i]=true代表第i条线段可以被看到 

//判断第k条线段a是否能够被看到 
bool check(int k,seg a)
{
    if(dist(a.s,a.t)<=EPS)return false;
    
    int flag=0;
    for(int i=0;i<N;++i)
        if(i!=k)
        {
            if(intersect(seg(me,a.s),S[i])&&intersect(seg(me,a.t),S[i]))
            {
                flag=1;
                break;
            }
            if(intersect_A(seg(me,a.s),S[i])||intersect(seg(me,a.t),S[i]))
            {
                flag=2;
            }
        }
        
    if(flag==0)return true;
    else if(flag==1)return false;
    else return (check(k,seg(a.s,midPoint(a.s,a.t)))||
                 check(k,seg(midPoint(a.s,a.t),a.t)));
} 

int solve()
{   
    int count=0;
    for(int i=0;i<N;++i)
    {
        if(check(i,S[i]))
        {
            can[i]=true;
            count++;
        }
    }
    return count;
}


int main()
{
    ifstream fin("fence4.in");
    ofstream fout("fence4.out");
    
    fin>>N;
    fin>>me.x>>me.y;
    for(int i=0;i<N;++i)
        fin>>P[i].x>>P[i].y;
    
    for(int i=0;i<N-2;++i)
    {
        S[i].s=P[i];
        S[i].t=P[i+1];
    }
    S[N-2].s=P[0];
    S[N-2].t=P[N-1];
    S[N-1].s=P[N-2];
    S[N-1].t=P[N-1];
    
    
    
    int count=solve();
    
    fout<<count<<endl;
    for(int i=0;i<N;++i)
    {
        if(can[i])
            fout<<S[i].s.x<<' '<<S[i].s.y<<' '<<S[i].t.x<<' '<<S[i].t.y<<endl;
    }
    
    //system("pause");
    return 0;
}
