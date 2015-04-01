/*
ID:cuichengpeng
PROG:shuttle
LANG:C++
*/
    #include<iostream>  
    #include<fstream>  
    #include<cstring>  
    #include<cstdio>  
    #define zout fout  
    using namespace std;  
    ifstream fin("shuttle.in");  
    ofstream fout("shuttle.out");  
    int n,ic;  
    void init()  
    {  
        fin>>n;     
    }  
    void op(int r[],int num)  
    {  
        for(int i=0;i<num;i++)  
        {  
            zout<<r[i];  
            ic++;  
            if(ic%20==0)  
            zout<<endl;  
            else  
            zout<<" ";  
        }  
    }  
    void slove()  
    {  
        int a[100][100];  
        int i,alen,len,odd=n+1,even=n+2;  
        alen=0;  
        for(int len=2;len<=n+1;len++)  
        {  
            if(len%2==0)  
            {  
                even-=2;  
                a[alen][0]=even;  
                for(i=1;i<len;i++)  
                a[alen][i]=a[alen][i-1]+2;  
            }  
            else  
            {  
                odd+=2;  
                a[alen][0]=odd;  
                for(i=1;i<len;i++)  
                a[alen][i]=a[alen][i-1]-2;  
            }  
            alen++;  
        }  
        ic=0;  
        int oplen=2;  
        for(i=0;i<alen;i++)  
        {  
            op(a[i],oplen);  
            oplen+=1;  
        }  
        oplen-=2;  
        for(i=alen-2;i>=0;i--)  
        {  
            op(a[i],oplen);  
            oplen-=1;  
        }  
        zout<<n+1;  
        zout<<endl;  
    }  
    int main()  
    {  
        init();  
        slove();  
        return 0;  
    }  
