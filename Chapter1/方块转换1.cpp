/*
ID:cui chengpeng
PROG: transform
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main(){
    ifstream fin("transform.in");
    ofstream fout("transform.out");
    int n;
    int i,j;
    char temp[12];
    fin >> n;
    fin.getline(temp,5);
    char rawdata[12];
    bool dataa[12][12];
    bool datab[12][12];
    int a;
    a = n / 2;
    bool swap;
    for(i=1;i<=n;i++){
        fin.getline(rawdata,15);
        for(j=0;j<n;j++){
            if(rawdata[j] == '@'){dataa[i][j + 1] = false;} else {dataa[i][j + 1] = true;}
        }
    }
    for(i=1;i<=n;i++){
        fin.getline(rawdata,15);
        for(j=0;j<n;j++){
            if(rawdata[j] == '@'){datab[i][j + 1] = false;} else {datab[i][j + 1] = true;}
        }
    }
    bool test;
    test = true;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(dataa[i][j] != datab[j][n + 1 - i]){test = false;break;}
        }
        if(test == false){break;}
    }
    if(test == true){fout << 1 << endl;return 0;}
    test = true;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(dataa[i][j] != datab[n + 1 - i][n + 1 - j]){test = false;break;}
        }
        if(test == false){break;}
    }
    if(test == true){fout << 2 << endl;return 0;}
    test = true;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(dataa[i][j] != datab[n + 1 - j][i]){test = false;break;}
        }
        if(test == false){break;}
    }
    if(test == true){fout << 3 << endl;return 0;}
    for(i=1;i<=n;i++){
        for(j=1;j<=a;j++){
            swap = datab[i][j];
            datab[i][j] = datab[i][n + 1 - j];
            datab[i][n + 1 - j] = swap;
        }
    }
    test = true;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(dataa[i][j] != datab[i][j]){test = false;}
        }
        if(test == false){break;}
    }
    if(test == true){fout << 4 << endl;return 0;}
    test = true;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(dataa[i][j] != datab[j][n + 1 - i]){test = false;break;}
        }
        if(test == false){break;}
    }
    if(test == true){fout << 5 << endl;return 0;}
    test = true;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(dataa[i][j] != datab[n + 1 - i][n + 1 - j]){test = false;break;}
        }
        if(test == false){break;}
    }
    if(test == true){fout << 5 << endl;return 0;}
    test = true;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(dataa[i][j] != datab[n + 1 - j][i]){test = false;break;}
        }
        if(test == false){break;}
    }
    if(test == true){fout << 5 << endl;return 0;}
    test = true;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(dataa[i][j] != datab[i][n + 1 - j]){test = false;break;}
        }
        if(test == false){break;}
    }
    if(test == true){fout << 6 << endl;return 0;}
    fout << 7 << endl;
    return 0;
}
