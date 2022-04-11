#include <stdio.h>
#include <stdlib.h>

typedef struct Point{
    char height;
    char is_lowest;
}point;


int main(){
    point **floor = (point**)calloc(sizeof(point*), 100);
    for (int i = 0; i < 100; i++){
        floor[i] = (point*)calloc(sizeof(point), 100);
    }
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            floor[i][j].height = getchar();
            floor[i][j].is_lowest = 1;
        }
        getchar();
    }
    int sum = 0;
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            if (i - 1 >= 0 && floor[i-1][j].height <= floor[i][j].height){
                floor[i][j].is_lowest = 0;
                continue;
            }
            if (j - 1 >= 0 && floor[i][j-1].height <= floor[i][j].height){
                floor[i][j].is_lowest = 0;
                continue;
            }
            if (i + 1 < 100 && floor[i+1][j].height <= floor[i][j].height){
                floor[i][j].is_lowest = 0;
                continue;
            }
            if (j + 1 < 100 && floor[i][j+1].height <= floor[i][j].height){
                floor[i][j].is_lowest = 0;
                continue;
            }
            sum += (floor[i][j].height - '0') + 1;
        }
    }
    printf("sum of the risk = %d\n", sum);
    return 0;
}
