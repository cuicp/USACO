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
    //����С�ڲ��������������򣬰���Ȼ�������˳������
    bool operator< (const Rect &r) const
    {
        if(w<r.w) return true;
        else return w*h<r.w*r.h;
    }
 
};
Rect rect0[4]; //�������ԭʼ�����4������
Rect rect1[4]; //�������任������4������
Rect rect[4]; //�������任λ�ú��4������
Rect rst[1000]; //�����������
int n;
int m=0xfffffff;
//MIN�������½�����飬�����ǰ�õ������������С���������һ�������
//���������С���������͵��ڵ�ǰ�Ŀ�ߺ����
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
 
//�����жϿ�ߣ����½��
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
	}while(next_permutation(ary,ary+4));//����ȫ���У�������4�����ε�λ��
}
main()
{
	freopen("packrec.in","r",stdin);
	freopen("packrec.out","w",stdout);
	int change[5][4]={{0,0,0,0},{0,0,0,1},{0,0,1,1},{0,1,1,1},{1,1,1,1}};//���ڽ������
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
