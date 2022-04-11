#include <stdio.h>
#include <stdlib.h>

void swap_points(int *x1, int *y1, int *x2, int *y2){
    int temp = *x1;
    *x1 = *x2;
    *x2 = temp;
    temp = *y1;
    *y1 = *y2;
    *y2 = temp;
}

int main(){
    int **floor = (int**)calloc(sizeof(int*), 1000);
    for (int i = 0; i < 1000; i++){
        floor[i] = (int*)calloc(sizeof(int), 1000);
    }

    for (int i = 0; i < 500; i++){
        int x1, y1, x2, y2;
        scanf("%d,%d -> %d,%d", &x1, &y1, &x2, &y2);
        if (x1 != x2 && y1 != y2){
            continue;
        }
        if (x1 > x2){
            swap_points(&x1, &y1, &x2, &y2);
        }
        if (y1 > y2){
            swap_points(&x1, &y1, &x2, &y2);
        }
        if(y1 == y2){
            for (int i = x1; i < x2 + 1; i++){
                floor[i][y1]++;
            }
        }
        if (x1 == x2){
            for (int i = y1; i < y2 + 1; i++){
                floor[x1][i]++;
            }
        }
    }
    
    int overlaps = 0;
    for (int i = 0; i < 1000; i++){
        for (int j = 0; j < 1000; j++){
            if (floor[i][j] >= 2){
                overlaps++;
            }
        }
    }
    printf("overlaps = %d\n", overlaps);
    return 0;
}
