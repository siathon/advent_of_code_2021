#include <stdio.h>
#include <math.h>

int main(){
    int bdigits[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    char num[13];
    for (int i = 0; i < 1000; i++){
        scanf("%s", num);
        for (int j = 11; j >= 0; j--){
            if (num[j] == '1'){
                bdigits[j]++;
            }
        }
    }
    int gamma = 0, epslion = 0;
    for (size_t i = 0; i < 12; i++){
        if (bdigits[i] > 500){
            gamma += pow(2.0f, i);
        }
    }
    epslion = 4095 - gamma;
    printf("%d\n", gamma * epslion);
    return 0;
}
