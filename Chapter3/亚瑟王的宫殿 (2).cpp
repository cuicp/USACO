/*
ID:cuichengpeng
PROG:camelot
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
typedef struct point{
        int first;
        int second;
        point(int fir,int sec)
        {
            first=fir;
            second=sec;
        }
};

const int INF=10000000;
int R,C;//�к���
int step,row1,row2,col1,col2;
vector<vector<int> >location; 
vector<vector<vector<int> > >map1;
int dir[][2]={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};

/***********************************
����㣨x��y����������ľ��� 
***********************************/ 
vector<vector<int> > bfs(int x,int y)
{
    vector<vector<int> >map(R);
    for(int i=0;i<R;++i)
        for(int j=0;j<C;++j)
           map[i].push_back(-1);
    point p(x,y);
    map[x][y]=0;
    queue<point>Q;
    Q.push(p);

    while(!Q.empty())
    {
        p=Q.front();
        Q.pop();

        for(int i=0;i<8;++i)
        {
            int fir=p.first+dir[i][0];
            int sec=p.second+dir[i][1];
            if(fir>=0&&fir<R&&sec>=0&&sec<C)
            {
                if(map[fir][sec]!=-1)continue;
                point temp(fir,sec);
                map[fir][sec]=map[p.first][p.second]+1;
                Q.push(temp);
            }
        }
    }
    return map;
}

/**********************************
������������ĵ㵽���̸�λ�õľ��� 
************************************/
void getMap1()
{
    vector<vector<int> >temp;
    for(int i=row1;i<=row2;++i)
    {
        for(int j=col1;j<=col2;++j)
        {
            temp=bfs(i,j);
            map1.push_back(temp);
        }
    }
} 
/******************************
��õ���x��y���㼯�ϵ���С���� 
******************************/
int getMinStep(int x,int y)
{
    if(location.size()==1)//û����ʿ 
        return max(abs(location[0][0]-x),abs(location[0][1]-y));

    vector<vector<int> >map;
    map=bfs(x,y);
    int min_steps=INF;
    int a,b;
    //ö�ٽ������λ��
    for(int i=0;i<map1.size();++i)
    {
        //(king_x,king_y)Ϊ��ʿ�ӹ�����λ�� 
        int king_x=row1+i/(col2-col1+1);
        int king_y=col1+i%(col2-col1+1);
        int king_steps=max(abs(location[0][0]-king_x),abs(location[0][1]-king_y)); //����Ҫ�ߵ�·�ĳ���
        //ö�ٽӹ�������ʿ
        int min=INF;//�ӹ���Ҫ���ߵ�· 
        for(int k=1;k<location.size();++k)//Ѱ����ѽӹ�������ʿ�����������ߵ�· 
        {
            if(map1[i][x][y]==-1||map1[i][location[k][0]][location[k][1]]==-1)continue;
                
            int temp=map1[i][x][y]+map1[i][location[k][0]][location[k][1]]
                    -map[location[k][0]][location[k][1]];
            if(temp<min)
            {a=king_x;b=king_y;
                min=temp;
                if(min==0)break;
            }
        }
            
        int steps;//��Ҫ�ߵĲ���
        steps=king_steps+min;
        for(int k=1;k<location.size();++k)
            steps+=map[location[k][0]][location[k][1]];
        
        if(steps<min_steps)min_steps=steps;
    }
    
    return min_steps;
}
int main()
{
    ifstream fin("camelot.in");
    ofstream fout("camelot.out");
    
    fin>>R>>C;
    
    char a;
    int b;
    vector<int>temp(2);
    while(fin>>a>>b)
    {
        temp[0]=b-1;
        temp[1]=a-'A';
        location.push_back(temp);
    }

    //�������������λ�� 
    step=3;
    row1=max(location[0][0]-step,0);
    row2=min(location[0][0]+step,R-1);
    col1=max(location[0][1]-step,0); 
    col2=min(location[0][1]+step,C-1);
    
    getMap1();
    //ö�ټ���λ�� 
    int min=INF;
    
    for(int i=0;i<R;++i)
    {
        for(int j=0;j<C;++j)
        {
            int steps=getMinStep(i,j);
            if(steps<min)min=steps;
        }
    }

    fout<<min<<endl;
   // system("pause");
    return 0;
}
