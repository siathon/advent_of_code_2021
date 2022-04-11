#include <stdio.h>

int main(){
    long long days[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 300; i++){
        int temp;
        scanf("%d,", &temp);
        days[temp]++;
    }

    for (int i = 0; i < 256; i++){
        long long new_borns = days[0];
        for (int j = 0; j < 8; j++){
            days[j] = days[j+1];
        }
        days[8] = new_borns; // new borns
        days[6] += new_borns; // adults reseted to 6 days
    }
    
    long long sum = 0;
    for (int i = 0; i < 9; i++){
        sum += days[i];
    }
    printf("lanternfish count = %lld\n", sum);
    return 0;
}
