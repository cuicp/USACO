/*
ID:cui chengpeng
PROG:packrec
LANG:C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
 
#define MAX(a,b) (a>b?a:b)
#define MAX3(a,b,c) (a>MAX(b,c)?a:MAX(b,c))
#define MAX4(a,b,c,d) (a>MAX3(b,c,d)?a:MAX3(b,c,d))
struct Rect{
    int w;
    int h;
    //重载小于操作符，用于排序，按宽然后面积的顺序排序
    bool operator< (const Rect &r) const
    {
        if(w<r.w) return true;
        else return w*h<r.w*r.h;
    }
 
};
Rect rect0[4]; //这个保存原始输入的4个矩形
Rect rect1[4]; //这个保存变换长宽后的4个矩形
Rect rect[4]; //这个保存变换位置后的4个矩形
Rect rst[1000]; //这个保存结果了
int n;
int m=0xfffffff;
//MIN用来更新结果数组，如果当前得到的面积等于最小面积就增加一个结果，
//如果大于最小面积，结果就等于当前的宽高和面积
#define MIN()\
    if(m>w*h)\
    {\
        m=w*h;\
        n=1;\
        rst[0].w=w;\
        rst[0].h=h;\
    }else if(m==w*h)\
    {\
        rst[n].w=w;\
        rst[n].h=h;\
        n++;\
    }
 
//主体判断宽高，更新结果
void work()
{
    int w,h;
	int f;
	int ary[4]={0,1,2,3};
    do{
        for(int i=0;i<4;i++)
        {
            rect[i]=rect1[ary[i]];
        }
	    w=rect[0].w+rect[1].w+rect[2].w+rect[3].w;
	    h=MAX4(rect[0].h,rect[1].h,rect[2].h,rect[3].h);
	    MIN();
 
	    w=MAX(rect[0].h,rect[1].w+rect[2].w+rect[3].w);
	    h=rect[0].w+MAX3(rect[1].h,rect[2].h,rect[3].h);
	    MIN();
 
	    w=MAX(rect[0].w+rect[1].w+rect[2].w,rect[3].h+rect[2].w);
	    h=MAX(rect[2].h,rect[3].w+MAX(rect[0].h,rect[1].h));
	    MIN();
 
	    w=rect[0].w+rect[3].w+MAX(rect[1].w,rect[2].w);
	    h=MAX3(rect[0].h,rect[3].h,rect[1].h+rect[2].h);
	    MIN();
 
	    if(rect[1].h<=rect[2].h)
	    {
	        if(rect[0].h+rect[1].h>rect[2].h)
	        {
	            if(rect[3].h>rect[2].w)
	                w=MAX(rect[0].w+rect[3].h,rect[1].w+rect[2].w);
	            else
	                w=MAX(rect[0].w,rect[1].w)+rect[2].w;
	            h=MAX(rect[0].h+rect[1].h,rect[2].h+rect[3].w);
	            MIN();
	        }
	    }
	}while(next_permutation(ary,ary+4));//生成全排列，即交换4个矩形的位置
}
main()
{
	freopen("packrec.in","r",stdin);
	freopen("packrec.out","w",stdout);
	int change[5][4]={{0,0,0,0},{0,0,0,1},{0,0,1,1},{0,1,1,1},{1,1,1,1}};//用于交换宽高
	for(int i=0;i<4;i++)
	{
	    cin>>rect0[i].w>>rect0[i].h;
	}
	sort(rect0,rect0+4);
	for(int i=0;i<5;i++)
	{
	    do{
	        memcpy(rect1,rect0,sizeof(rect0));
	        for(int j=0;j<4;j++)
	        {
	            if(change[i][j])
	            {
	                swap(rect1[j].w,rect1[j].h);
	            }
	        }
	        work();
	    }while(next_permutation(change[i],change[i]+4));
	}
 
	for(int i=0;i<n;i++)
	    if(rst[i].w>rst[i].h) swap(rst[i].w,rst[i].h);
	sort(rst,rst+n);
 
	cout<<m<<endl;
	cout<<rst[0].w<<' '<<rst[0].h<<endl;
	for(int i=1;i<n;i++)
	    if(rst[i].w!=rst[i-1].w && rst[i].h!=rst[i-1].h)
	        cout<<rst[i].w<<' '<<rst[i].h<<endl;
	exit(0);
}
