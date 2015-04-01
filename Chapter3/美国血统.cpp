#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
typedef struct Node{
        char data;
        struct Node *lchild;
        struct Node *rchild;
        }Node,*BiTree;

const int M=30;
char a[M],b[M];//a,b分别存储先序和中序遍历序列 
int lenth;
void CreatTree(BiTree &T,char ch,int m,int n);
int Search(char ch);//返回ch在b中的下标
char First(int m,int n);//返回b[m]--b[n]中首先在a中出现的字符 
void Travel(Node* T);

int main()
{
    ifstream fin("heritage.txt");
    BiTree Tree;
    fin>>b>>a;

    cout<<b<<endl<<a<<endl;
    lenth=strlen(a);

    CreatTree(Tree,a[0],0,lenth-1);

    Travel(Tree);
    cout<<endl;

    system("pause");
    return 0;
}
int Search(char ch)//返回ch在b中的下标
{
    for(int i=0;i<lenth;++i)
    {
        if(ch==b[i])
            return i;
    }
} 
char First(int m,int n)//返回b[m]--b[n]中首先在a中出现的字符 
{
     if(m>n)return NULL;
     
     for(int i=0;i<lenth;++i)
     {
         for(int j=m;j<=n;++j)
         {
             if(a[i]==b[j])
                 return a[i];
         }
     }
} 
void CreatTree(BiTree &T,char ch,int m,int n)
{
     if(m>n)
     {
             T=NULL; 
             return ;
     }
     
     T=(Node*)malloc(sizeof(Node));
     T->data=ch;
     
     int mid;
     mid=Search(ch);//找出左右字子树元素在b中的分界线 

     char c;
     c=First(m,mid-1);//找出左子树的树根元素 
     CreatTree(T->lchild,c,m,mid-1);

     c=First(mid+1,n);//找出右子树的树根元素
     CreatTree(T->rchild,c,mid+1,n);

}
void Travel(Node* T)
{
     if(T)
     {
          Travel(T->lchild);
          Travel(T->rchild);
          cout<<T->data;
     }
}
