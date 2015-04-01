#include<iostream>
#include<fstream>
#include<string>
#include<queue>
#include<map>

using namespace std;
typedef struct{
        string pash;
        string state;
        }Node;

string Change(char ch,string s);//对s的三种操作
void BFS(string goal); 
void Qutput(Node T);//输出长度和路径 
map<string,bool>MAP;
int main()
{
    ifstream fin("msquare.txt");
    string goal;
    char temp;

    for(int i=0;i<8;++i)
    {
            fin>>temp;
            goal+=temp;
    }

    BFS(goal); 

    system("pause");
    return 0;
}
string Change(char ch,string s)
{
     if(ch=='A')
     {
          for(int i=0;i<4;++i)
          {
              char temp=s[i];
              s[i]=s[7-i];
              s[7-i]=temp;
          }
     }
     else if(ch=='B')
     {
          string temp;
          temp=s;
          s[0]=temp[3];s[1]=temp[0];s[2]=temp[1];s[3]=temp[2];
          s[4]=temp[5];s[5]=temp[6];s[6]=temp[7];s[7]=temp[4];
     }
     else
     {
          char temp;
          temp=s[1];
          s[1]=s[6];s[6]=s[5];s[5]=s[2];s[2]=temp;
     }
     return s;
     
}
void BFS(string goal)
{
     queue<Node>Q;
     Node T,temp;
     
     
     T.state="12345678";

     
     MAP[T.state]=true;
     Q.push(T);
     
     while(!Q.empty())
     {
          T=Q.front();
          Q.pop();
          
          temp.state=Change('A',T.state);
          temp.pash=T.pash+'A';
          if(!MAP[temp.state])
          {
              if(temp.state==goal)
              {
                  Qutput(temp);
                  return;
              }
              else 
              {
                  Q.push(temp);
                  MAP[temp.state]=true;
              }
          }         
            
          temp.state=Change('B',T.state);
          temp.pash=T.pash+'B';
          if(!MAP[temp.state])
          {
              if(temp.state==goal)
              {
                  Qutput(temp);
                  return;
              }
              else
              {
                  Q.push(temp);
                  MAP[temp.state]=true;
              }
          }        
                         
          temp.state=Change('C',T.state);
          temp.pash=T.pash+'C';
          if(!MAP[temp.state])
          {
              if(temp.state==goal)
              {
                  Qutput(temp);
                  return;
              }
              else 
              {
                  Q.push(temp);
                  MAP[temp.state]=true;
              }
          }                       
     }
}
void Qutput(Node T)
{
     cout<<T.pash.size()<<endl;
     for(int i=1;i<=T.pash.size();++i)
     {
             cout<<T.pash[i];
             if(i%60==0)cout<<endl;
     } 
     cout<<endl;
} 
