#include <stdio.h>

int main(){
    int nums[2000], inc = 0;
    for (size_t i = 0; i < 2000; i++){
        scanf("%d", &nums[i]);
    }
    
    for (size_t i = 0; i < 1997; i++){
        int sum1 = nums[i] + nums[i + 1] + nums[i + 2];
        int sum2 = nums[i + 1] + nums[i + 2] + nums[i + 3];
        if(sum2 > sum1){
            inc++;
        }
    }
    printf("%d\n", inc);
    return 0;
}