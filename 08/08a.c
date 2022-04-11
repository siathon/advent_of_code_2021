#include <stdio.h>
#include <string.h>

int main(){
    int cnt = 0;
    for (int i = 0; i < 200; i++){
        while (getchar() != '|');
        getchar();
        char temp[8];
        for (int j = 0; j < 4; j++){
            scanf("%s", temp);
            int len = strlen(temp);
            if (len == 2 || len == 3 || len == 4 || len == 7){
                cnt++;
            }
        }
    }
    printf("digit count = %d\n", cnt);
    return 0;
}
