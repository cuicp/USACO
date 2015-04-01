/*
    ID:cui chengpeng
    PROG:beads
    LANG:C++
*/
#include<iostream>
#include<fstream>
using namespace std;
typedef struct LNode{
		char data;
		struct LNode *pri,*next;
		}LNode,*list;
		
void Insert(list &L,char e);
int Search(list L,int n);
int Search_pri(list L);
int Search_next(list L);
int main()
{
 	int i,n,max;
 	char ch;
 	ifstream fin("beads.in");
 	ofstream fout("beads.out");
 	list L,p;
 	L=(list)malloc(sizeof(LNode));
 	
 	fin>>n;
 	
 	fin>>ch;
	L->data=ch;
	L->next=L;L->pri=L;
 	
 	for(i=1;i<n;i++)
 	{
	     fin>>ch;
	     Insert(L,ch);
	}
 	
 	max=Search(L,n);
 	
 	fout<<max<<endl;
 	
 	

 	return 0;
}


void Insert(list &L,char e)
{
 	 list p;
 	 p=(list)malloc(sizeof(LNode));
 	 p->data=e;
 	 p->next=L;
 	 p->pri=L->pri;
 	 p->pri->next=p;
 	 L->pri=p;
}

int Search(list L,int n)
{
 	int i,max=0,a,b;
 	list p;
 	p=L;
 	
 	for(i=1;i<n;++i)
 	{
		a=Search_pri(p);
		b=Search_next(p->next);
		if(a+b>max)max=a+b;
		if(max>=n)return n;
		p=p->next;
	}
	return max;
}

int Search_pri(list L)
{
 	int num=1;
 	list p;
 	char ch;
 	p=L;
 	ch=L->data;
 	L=L->pri;
 	
 	if(ch=='w')
 	{
        while(L->data==ch&&L!=p)
        {
  		    ++num;
  		    L=L->pri;
  		}
  		ch=L->data;
  		while((L->data==ch||L->data=='w')&&L!=p)
  		{
		    ++num;
		    L=L->pri;
		}
    }
    else
	{
	 	while((L->data==ch||L->data=='w')&&L!=p)
  		{
		    ++num;
		    L=L->pri;
		}
    }
    
    return num;
}

int Search_next(list L)
{
 	int num=1;
 	list p;
 	char ch;
 	
 	p=L;
 	ch=L->data;
 	L=L->next;
 	
 	if(ch=='w')
 	{
        while(L->data==ch&&L!=p)
        {
  		    ++num;
  		    L=L->next;
  		}
  		ch=L->data;
  		while((L->data==ch||L->data=='w')&&L!=p)
  		{
		    ++num;
		    L=L->next;
		}
    }
    else
	{
	 	while((L->data==ch||L->data=='w')&&L!=p)
  		{
		    ++num;
		    L=L->next;
		}
    }
    
    return num;
}








