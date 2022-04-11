#include <stdio.h>

int main(){
    int inc = 0, num = 0, temp;
    scanf("%d", &num);
    for (int i = 0; i < 2000; i++){
        int temp;
        scanf("%d", &temp);
        
        if (temp > num){
            inc++;       
        }
        num = temp;
    }
    printf("%d\n", inc);
    return 0;
}
