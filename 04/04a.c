#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int number;
    int flag;
}node;

void print_board(node **board){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            printf("%2d(%c) ", board[i][j].number, board[i][j].flag ? '*' : ' ');
        }
        printf("\n");
    }
}

void set_flag(node **board, int num){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (board[i][j].number == num){
                board[i][j].flag = 1;
            }
        }
    }
}

int check_win(node **board){
    for (int i = 0; i < 5; i++){
        int cnt = 0;
        for (int j = 0; j < 5; j++){
            cnt += board[i][j].flag;
        }
        if (cnt == 5){
            return 1;
        }
    }
    for (int i = 0; i < 5; i++){
        int cnt = 0;
        for (int j = 0; j < 5; j++){
            cnt += board[j][i].flag;
        }
        if (cnt == 5){
            return 1;
        }
    }
    return 0;
}

int main(){
    node ***boards = (node***)calloc(sizeof(node**), 100);
    for (int i = 0; i < 100; i++){
        boards[i] = (node**)calloc(sizeof(node*), 5);
        for (int j = 0; j < 5; j++){
            boards[i][j] = (node*)calloc(sizeof(node), 5);
        }
    }
    
    int numbers[100];
    for (int i = 0; i < 100; i++){
        scanf("%d,", &numbers[i]);
    }
    for (int j = 0; j < 100; j++){
        for (int i = 0; i < 5; i++){
            scanf("%d %d %d %d %d", &boards[j][i][0].number, &boards[j][i][1].number, &boards[j][i][2].number, &boards[j][i][3].number, &boards[j][i][4].number);
        }
    }
    int winner = 0, last_number = 0;;
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            set_flag(boards[j], numbers[i]);
        }
        winner = 0;
        for (int j = 0; j < 100; j++){
            winner = check_win(boards[j]);
            if (winner){
                print_board(boards[j]);
                winner = j;
                last_number = numbers[i];
                break;
            }
        }
        if (winner){
            break;
        }
    }
    int sum = 0;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (!boards[winner][i][j].flag){
                sum += boards[winner][i][j].number;
            }
        }
    }
    printf("score = %d\n", sum * last_number);
    return 0;
}
