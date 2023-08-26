#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b){
    if(a < b){
        return a;
    }else{
        return b;
    }
}

int main(){
    int n;
    scanf("%d", &n); getchar();

    int coins[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &coins[i]); getchar();
    }

    int value;
    scanf("%d", &value); getchar();

    int table[n + 1][value + 1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= value; j++){
            if(i == 0){
                // possible coin to make up the value
                if (j % coins[i] == 0){
                    table[i][j] = j / coins[i];
                }else{
                    table[i][j] = -1;
                }
            }else if(j == 0){
                table[i][j] = 0;
            }else if(coins[i-1] <= j){
                table[i][j] = min(table[i-1][j], 1 + table[i][j-coins[i-1]]);
            }else{
                table[i][j] = table[i-1][j];
            }
        }
    }

    printf("%d\n", table[n][value]);

    return 0;
}