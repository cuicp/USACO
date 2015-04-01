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
char a[M],b[M];//a,b�ֱ�洢���������������� 
int lenth;
void CreatTree(BiTree &T,char ch,int m,int n);
int Search(char ch);//����ch��b�е��±�
char First(int m,int n);//����b[m]--b[n]��������a�г��ֵ��ַ� 
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
int Search(char ch)//����ch��b�е��±�
{
    for(int i=0;i<lenth;++i)
    {
        if(ch==b[i])
            return i;
    }
} 
char First(int m,int n)//����b[m]--b[n]��������a�г��ֵ��ַ� 
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
     mid=Search(ch);//�ҳ�����������Ԫ����b�еķֽ��� 

     char c;
     c=First(m,mid-1);//�ҳ�������������Ԫ�� 
     CreatTree(T->lchild,c,m,mid-1);

     c=First(mid+1,n);//�ҳ�������������Ԫ��
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
