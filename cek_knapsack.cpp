#include <stdio.h>
#include <string.h>

int main(){
    int profit[] = {4, 6, 2};
    int weight[] = {2, 4, 1};
    int count[] = {1, 2, 2};
    int capacity = 4;
    int n = sizeof(profit) / sizeof(profit[0]);

    int table[n + 1][capacity + 1];
    int selected[n + 1][capacity + 1];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= capacity; j++){
            if(i == 0 || j == 0){
                table[i][j] = 0;
                selected[i][j] = 0;
            }else{
                table[i][j] = table[i-1][j];
                selected[i][j] = 0;
                for (int k = 1; k <= count[i-1] && k * weight[i-1] <= j; k++) {
                    int newProfit = profit[i-1] * k + table[i-1][j - k * weight[i-1]];
                    printf("(%d, %d); k = %d| %d * %d + %d\n", i, j, k, profit[i-1], k, table[i-1][j - k * weight[i-1]]);
                    if (newProfit > table[i][j]) {
                        table[i][j] = newProfit;
                        selected[i][j] = k;
                    }
                }
            }
        }
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= capacity; j++){
            printf("%4d ", table[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= capacity; j++){
            printf("%4d ", selected[i][j]);
        }
        printf("\n");
    }

    // Printing the selected items and their counts
    int i = n;
    int j = capacity;
    while (i > 0 && j > 0) {
        if (selected[i][j] > 0) {
            printf("Item %d (Count: %d)\n", i, selected[i][j]);
            j -= selected[i][j] * weight[i-1];
            i--;
        } else {
            i--;
        }
    }

    return 0;
}
