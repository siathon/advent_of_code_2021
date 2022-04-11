#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    long data;
    struct Node *next;
}node;

void print_list(node **list){
    node *temp = *list;
    while (temp != NULL){
        printf("%c--", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void push(node **list, long data){
    node *n = (node*)malloc(sizeof(node));
    n->data = data;
    n->next = *list;
    *list = n;
}

node* pop(node **list){
    node *n = *list;
    *list = n->next;
    return n;
}

void push_sorted(node **list, long data){
    node *n = (node*)malloc(sizeof(node));
    n->data = data;
    if (*list == NULL || (*list)->data <= data){
        n->next = *list;
        *list = n;
        return;
    }
    node *current = *list;
    while (current->next != NULL && current->next->data >= n->data) {
        current = current->next;
    }
    n->next = current->next;
    current->next = n;
}

int list_size(node **list){
    node *temp = *list;
    int cnt = 0;
    while (temp != NULL){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

int get_score(long c){
    switch (c){
    case '(':
        return 1;
    case '[':
        return 2;
    case '{':
        return 3;
    case '<':
        return 4;
    }
}

void flush_line(){
    while (getchar() != '\n');
}

int main(){
    node *sequence_score = NULL;
    for (int i = 0; i < 94; i++){
        node *stack = NULL;
        int corrupted = 0;
        while (1){
            char c = getchar();
            if (strchr(")]}>", c) != NULL){
                node *current = pop(&stack);
                if (current == NULL){
                    flush_line();
                    corrupted = 1;
                    break;
                }
                switch (c){
                case ')':
                    if (current->data != '('){
                        corrupted = 1;
                    }
                    break;
                case ']':
                    if (current->data != '['){   
                        corrupted = 1;
                    }
                    break;
                case '}':
                    if (current->data != '{'){   
                        corrupted = 1;
                    }
                    break;
                case '>':
                    if (current->data != '<'){   
                        corrupted = 1;
                    }
                }
                if (corrupted){
                    flush_line();
                    break;
                }
            }
            else if (strchr("[{<(", c) != NULL){
                push(&stack, c);
            }
            else if (c == '\n'){
                if (stack == NULL){
                    break;
                }
                long score = 0;
                while (stack != NULL){
                    node *temp = pop(&stack);
                    score = 5 * score + get_score(temp->data);
                }
                push_sorted(&sequence_score, score);
                break;
            }
        }
    }
    int size = list_size(&sequence_score);
    node *middle = sequence_score;
    for (int i = 0; i < size / 2; i++){
        middle = middle->next;
    }
    printf("middle score = %ld\n", middle->data);
    return 0;
}
