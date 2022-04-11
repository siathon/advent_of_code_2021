#include <stdio.h>
#include <stdlib.h>

int main(){
    long long lfish_cnt = 300;
    char *lfishs = (char*)calloc(sizeof(char), 300);
    for (int i = 0; i < 300; i++){
        scanf("%hhu,", &lfishs[i]);
    }
    for (int i = 0; i < 80; i++){
        int new_born_cnt = 0;
        for (int j = 0; j < lfish_cnt; j++){
            if (lfishs[j] == 0){
                lfishs[j] = 6;
                new_born_cnt++;
            }
            else{
                lfishs[j]--;
            }
        }
        if (new_born_cnt){
            lfishs = (char*)realloc(lfishs, (lfish_cnt + new_born_cnt) * sizeof(char));
            for (int j = lfish_cnt; j < lfish_cnt + new_born_cnt; j++){
                lfishs[j] = 8;
            }
            lfish_cnt += new_born_cnt;
        }
    }
    printf("lanternfish count = %lld\n", lfish_cnt);
    return 0;
}
