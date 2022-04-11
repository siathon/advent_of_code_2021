#include <stdio.h>
#include <stdlib.h>

int main(){
    int **floor = (int**)calloc(sizeof(int*), 1000);
    for (int i = 0; i < 1000; i++){
        floor[i] = (int*)calloc(sizeof(int), 1000);
    }

    for (int i = 0; i < 500; i++){
        int x1, y1, x2, y2;
        scanf("%d,%d -> %d,%d", &x1, &y1, &x2, &y2);
        int dir_x, dir_y;
        dir_x = x1 == x2 ? 0 : (x2 - x1) / abs(x2 - x1);
        dir_y = y1 == y2 ? 0 : (y2 - y1) / abs(y2 - y1);
        while (1){
            floor[x1][y1]++;
            if (x1 == x2 && y1 == y2){
                break;
            }
            
            x1 += dir_x;
            y1 += dir_y;
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
