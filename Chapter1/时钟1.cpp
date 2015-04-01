/*
ID:yuanpen1
PROB:clocks
LANG:C++
*/
#include <iostream>
#include <fstream>
#include <string.h>
    
using namespace std;
char ways[9][6] = {"ABDE", "ABC", "BCEF", "ADG", "BDEFH", "CFI",
                        "DEGH", "GHI", "EFHI"};
int clocks[9];
int used[9];
int ans[9];
int len = 48;

void change(const int a)
{
        char *str = ways[a];
        while(*str != '\0'){
                clocks[*str - 'A']++;
                if(clocks[*str - 'A'] == 5){
                        clocks[*str - 'A'] = 1;
                }
                str++;
        }
}

void check(const int sum)
{
        int i;
        if(sum > len){
                return;
        }
        for(i = 0; i < 9; i++){
                if(clocks[i] != 4){
                        return;
                }
        }
        if(sum < len){
                memcpy(ans, used, sizeof(used));
                len = sum;
        }else if(sum == len){
                for(i = 0; i < 9; i++){
                        if(used[i] >= ans[i]){
                                break;
                        }
                }
                if(i != 9){
                        memcpy(ans, used, sizeof(used));
                        len = sum;
                }
        }
}

void srch(int now, int sum)
{
        int i;
        check(sum);
        if(now == 9){
                return;
        }
        for(i = 1; i <= 4; i++){
                srch(now + 1, sum + used[now]);
                used[now]++;
                change(now);
        }
        used[now] = 0;
}


int main() {
        int i, j, k = 0;
        freopen("clocks.in", "r", stdin);
        freopen("clocks.out", "w", stdout);
        memset(used,0,sizeof(used));
        memset(ans,0,sizeof(ans));
        for(i = 0; i < 9; i++){
                scanf("%d", &clocks[i]);
                clocks[i] /= 3;
        }
        srch(0, 0);
        for(i = 0; i < 9; i++){
                for(j = 0; j < ans[i]; j++){
                        if(k){
                                printf(" ");
                        }
                        k = 1;
                        printf("%d", i + 1);
                }
        }
        printf("\n");
        return 0;

}
