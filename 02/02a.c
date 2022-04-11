#include <stdio.h>
#include <string.h>

int main(){
    char command[8];
    int num, x = 0, y = 0;
    for (size_t i = 0; i < 1000; i++){
        scanf("%s %d", command, &num);
        if (strcmp(command, "forward") == 0){
            x += num;
        }
        else if (strcmp(command, "up") == 0){
            y -= num;
        }
        else {
            y += num;
        }
    }
    printf("%d\n", x * y);
    return 0;
}
