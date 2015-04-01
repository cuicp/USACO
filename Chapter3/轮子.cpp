/*
ID:cuichengpeng
PROG:spin
LANG:C++
*/ 
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
vector<int>Speed;
vector<int>Num;
vector<vector<int> >Wheel;
bool Spin()
{
    int i,j,k,k1,light;//lightΪ�������ڽǶ� 
    
    for(i=0;i<Num[0];++i)
    {
        int low=Wheel[0][i*2];
        int high=Wheel[0][i*2+1];
        if(high<low)high=360+high;
        
        for(j=low;j<=high;++j)
        {
            light=j%360;
            
            for(k=1;k<Wheel.size();++k)//��������� 
            {
                for(k1=0;k1<Num[k];++k1)//k���ӵ�ÿ��ȱ�� 
                {
                    int temp_low=Wheel[k][k1*2];
                    int temp_high=Wheel[k][k1*2+1];
                    
                    if(temp_low<=temp_high)
                    {
                        if(light>=temp_low&&light<=temp_high)break;             
                    }
                    else
                    {
                        if((light>=temp_low&&light<360)||(light>=0&&light<=temp_high))break;
                    }
                } 
                if(k1>=Num[k])break;//���߲���ͨ�������� 
            }
            if(k>=Wheel.size())break;//����ͨ������������ 
        }
        if(j<=high)break;//�ҵ�һ�����߿��Դ���ÿ������ 
    }
    
    if(i>=Num[0])return false;
    else  return true;
}

int main()
{
    int i;
    
    ifstream fin("spin.in");
    ofstream fout("spin.out");
    
    int speed,num,wheel,length;
    vector<int>temp_Wheel;
    while(fin>>speed>>num)
    {
        Speed.push_back(speed);
        Num.push_back(num);
        
        temp_Wheel.clear();
        for(i=0;i<num;++i)
        {
            fin>>wheel>>length;
            temp_Wheel.push_back(wheel);
            temp_Wheel.push_back((wheel+length)%360);
        }
        Wheel.push_back(temp_Wheel);
    }    
   
   
    for(i=0;i<=360;i++)
    {
        if(Spin())break;
        else
        {
            for(int k1=0;k1<Wheel.size();++k1)//ÿ������ 
            {
                for(int k2=0;k2<Wheel[k1].size();++k2)//ÿ��ȱ�� 
                {
                    Wheel[k1][k2]=(Wheel[k1][k2]+Speed[k1])%360;
                }
            }
        }
  /*      
            for(int k1=0;k1<Wheel.size();++k1)
            {
                for(int k2=0;k2<Wheel[k1].size();++k2)
                {
                    cout<<Wheel[k1][k2]<<' ';
                }
                cout<<endl;
            }        
            system("pause");
   */     
         
    }
    if(i<=360) fout<<i<<endl;
    else fout<<"none"<<endl;
    
    
 //   system("pause");
    return 0;
}
