#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct Digit{
    char segments[8];
    int digit;
}digit;

int get_digit(char* segments){
    int seg_cnt = strlen(segments);
    switch (seg_cnt){
    case 2:
        return 1;
    case 3:
        return 7;
    case 4:
        return 4;
    case 7:
        return 8;
    default:
        return -1;
    }
}

int get_digit_index(digit* digits, int digit){
    for (int i = 0; i < 10; i++){
        if (digits[i].digit == digit){
            return i;
        }
    }
    return -1;
}

void sort_segments(char* segments){
    char t;
    int len = strlen(segments);
    for (int i = 0; i < len; i++){
        for (int j = i + 1; j < len; j++){
            if (segments[i] > segments[j]){
                t = segments[i];
                segments[i] = segments[j];
                segments[j] = t;
            }
        }
    }
}

void find_6(digit* digits){
    // if only one of the segments of digit 1 exists in a 6-segmented digit, that is digit 6
    int index_1 = get_digit_index(digits, 1);
    for (int i = 0; i < 10; i++){
        if ((strlen(digits[i].segments) == 6) && ((strchr(digits[i].segments, digits[index_1].segments[0]) == NULL) != (strchr(digits[i].segments, digits[index_1].segments[1]) == NULL))){
            digits[i].digit = 6;
            return;
        }
    }
}

void find_9(digit* digits){
    // if all of the segments of digit 4 exists in a 6-segmented digit, that is digit 9
    int index_4 = get_digit_index(digits, 4);
    for (int i = 0; i < 10; i++){
        if (strlen(digits[i].segments) == 6){
            int all_in = 1;
            for (int j = 0; j < 4; j++){
                if (strchr(digits[i].segments, digits[index_4].segments[j]) == NULL){
                    all_in = 0;
                    break;
                }
            }
            if (all_in == 1){
                digits[i].digit = 9;
                return;
            }
        }
    }
}

void find_0(digit* digits){
    // the remaining 6-segmented digit is 0
    for (int i = 0; i < 10; i++){
        if (strlen(digits[i].segments) == 6 && digits[i].digit == -1){
            digits[i].digit = 0;
            return;
        }
    }
}

void find_3(digit* digits){
    // if all of the segments of digit 1 exists in a 5-segmented digit, that is digit 3
    int index_1 = get_digit_index(digits, 1);
    for (int i = 0; i < 10; i++){
        if (strlen(digits[i].segments) == 5 && strchr(digits[i].segments, digits[index_1].segments[0]) != NULL && strchr(digits[i].segments, digits[index_1].segments[1]) != NULL){
            digits[i].digit = 3;
            return;
        }
    }
}

void find_5(digit* digits){
    // if the segment of 1 which is in 6 too, exists in a 5-segmented digit, that is digit 5
    int index_1 = get_digit_index(digits, 1);
    int index_6 = get_digit_index(digits, 6);
    char c = strchr(digits[index_6].segments, digits[index_1].segments[0]) != NULL ? digits[index_1].segments[0] : digits[index_1].segments[1];
    for (int i = 0; i < 10; i++){
        if (strlen(digits[i].segments) == 5 && digits[i].digit == -1 && strchr(digits[i].segments, c) != NULL){
            digits[i].digit = 5;
            return;
        }
    }
}

void find_2(digit* digits){
    // the remaining digit is 2
    for (int i = 0; i < 10; i++){
        if (digits[i].digit == -1){
            digits[i].digit = 2;
            return;
        }
        
    }
    
}

void get_number(digit* digits, digit* number){
    for (int i = 0; i < 4; i++){
        if (number[i].digit != -1){
            continue;
        }
        for (int j = 0; j < 10; j++){
            if (strcmp(number[i].segments, digits[j].segments) == 0){
                number[i].digit = digits[j].digit;
            }
        }
    }
}

int main(){
    int sum = 0;
    digit digits[10], number[4];
    for (int i = 0; i < 200; i++){
        for (int j = 0; j < 10; j++){
            scanf("%s", digits[j].segments);
            sort_segments(digits[j].segments);
            digits[j].digit = get_digit(digits[j].segments);
        }
        getchar();
        getchar();
        for (int j = 0; j < 4; j++){
            scanf("%s", number[j].segments);
            sort_segments(number[j].segments);
            number[j].digit = get_digit(number[j].segments);
        }
        find_6(digits);
        find_9(digits);
        find_0(digits);
        find_3(digits);
        find_5(digits);
        find_2(digits);
        get_number(digits, number);
        int num = 0;
        for (int j = 0; j < 4; j++){
            num += number[j].digit * pow(10.0, 3 - j);
        }
        sum += num;
    }
    printf("sum of the numbers: %d\n", sum);
    return 0;
}
