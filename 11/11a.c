#include <stdio.h>
#include <stdlib.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"

typedef struct Node{
    unsigned short energy;
    unsigned short is_flashed;
}node;

void print_octs(node **octs){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (octs[i][j].is_flashed){
                printf("%s%hu", KRED, octs[i][j].energy);
            }
            else{
                printf("%s%hu", KNRM, octs[i][j].energy);
            }
        }
        printf("\n");
    }
}

int main(){
    node **octs = (node**)calloc(sizeof(node*), 10);
    for (int i = 0; i < 10; i++){
        octs[i] = (node*)calloc(sizeof(node), 10);
    }
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            octs[i][j].energy = getchar() - '0';
            octs[i][j].is_flashed = 0;
        }
        getchar();
    }
    int flash_cnt = 0;
    for (int k = 0; k < 100; k++){
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                octs[i][j].energy++;
                octs[i][j].is_flashed = 0;
            }
        }
        int changed = 1;
        while (changed){
            changed = 0;
            for (int i = 0; i < 10; i++){
                for (int j = 0; j < 10; j++){
                    if(!octs[i][j].is_flashed && octs[i][j].energy > 9){
                        octs[i][j].is_flashed = 1;
                        flash_cnt++;
                        octs[i][j].energy = 0;
                        if (i - 1 >= 0){
                            if (j - 1 >= 0 && !octs[i-1][j-1].is_flashed){
                                octs[i-1][j-1].energy++;
                                changed = 1;
                            }
                            if (!octs[i-1][j].is_flashed){
                                octs[i-1][j].energy++;
                                changed = 1;
                            }
                            if (j + 1 < 10 && !octs[i-1][j+1].is_flashed){
                                octs[i-1][j+1].energy++;
                                changed = 1;
                            }
                        }
                        if (i + 1 < 10){
                            if (j - 1 >= 0 && !octs[i+1][j-1].is_flashed){
                                octs[i+1][j-1].energy++;
                                changed = 1;
                            }
                            if (!octs[i+1][j].is_flashed){
                                octs[i+1][j].energy++;
                                changed = 1;
                            }
                            if (j + 1 < 10 && !octs[i+1][j+1].is_flashed){
                                octs[i+1][j+1].energy++;
                                changed = 1;
                            }
                        }
                        if (j - 1 >= 0 && !octs[i][j-1].is_flashed){
                            octs[i][j-1].energy++;
                            changed = 1;
                        }
                        if (j + 1 < 10 && !octs[i][j+1].is_flashed){
                            octs[i][j+1].energy++;
                            changed = 1;
                        }
                    }
                }
            }
        }
    }
    printf("Flash times = %d\n", flash_cnt);
    
    return 0;
}
