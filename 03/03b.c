#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap_str(char *s1, char *s2){
    char temp[12];
    for (int i = 0; i < 12; i++){
        temp[i] = s1[i];
        s1[i] = s2[i];
        s2[i] = temp[i];
    }
    
}

void get_most_or_least_common(char **num_list, int size, int index, int most_or_least){
    if (size == 1){
        return;
    }
    int cnt = 0;
    for (int i = 0; i < size; i++){
        if (num_list[i][index] == '1'){
            cnt++;
        }
    }
    char digit;
    if (most_or_least == 1){
        if (cnt >= size - cnt){
            digit = '1';
        }
        else{
            digit = '0';
            cnt = size - cnt;
        }
    }
    else{
        if (cnt < size - cnt){
            digit = '1';
        }
        else{
            digit = '0';
            cnt = size - cnt;
        }
    }
    
    for (int i = 0; i < cnt; i++){
        if (num_list[i][index] == digit){
            continue;
        }
        int j = i + 1;
        while (num_list[j][index] != digit){
            j++;
        }
        swap_str(num_list[i], num_list[j]);
    }
    return get_most_or_least_common(num_list, cnt, index + 1, most_or_least);
}

int main(){
    char **num_list = (char**)malloc(1000 * sizeof(char*));
    for (int i = 0; i < 1000; i++){
        num_list[i] = (char*)malloc(13);
        scanf("%s", num_list[i]);
    }
    get_most_or_least_common(num_list, 1000, 0, 1);
    long oxygen = strtol(num_list[0], NULL, 2);
    get_most_or_least_common(num_list, 1000, 0, 0);
    long co2 = strtol(num_list[0], NULL, 2);
    printf("%ld\n", oxygen * co2);
    return 0;
}
