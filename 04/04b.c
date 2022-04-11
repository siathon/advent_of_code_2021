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
    int winner_cnt = 0, last_index = 0, last_to_win = 0;
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            set_flag(boards[j], numbers[i]);
        }
        winner_cnt = 0;
        for (int j = 0; j < 100; j++){
            int win = check_win(boards[j]);
            if (win){
                winner_cnt++;
            }
            else{
                last_to_win = j;
            }
            
        }
        if (winner_cnt == 99){
            last_index = i;
            break;
        }
    }
    int last_number;
    for (int i = last_index + 1; i < 100; i++){
        set_flag(boards[last_to_win], numbers[i]);
        if (check_win(boards[last_to_win])){
            last_number = numbers[i];
            break;
        }
    }
    print_board(boards[last_to_win]);
    int sum = 0;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (!boards[last_to_win][i][j].flag){
                sum += boards[last_to_win][i][j].number;
            }
        }
    }
    printf("score = %d\n", sum * last_number);
    return 0;
}
