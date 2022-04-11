#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char data;
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

void push(node **list, char data){
    node *n = (node*)malloc(sizeof(node));
    n->data = data;
    n->next = *list;
    *list = n;
}

node* pop(node **list){
    node *n = *list;
    *list = n->next;
    n->next = NULL;
    return n;
}

int get_score(char c){
    switch (c){
    case ')':
        return 3;
    case ']':
        return 57;
    case '}':
        return 1197;
    case '>':
        return 25137;
    }
}

int main(){
    int syntax_err_score = 0;
    for (int i = 0; i < 94; i++){
        node *stack = NULL;
        int line_finished = 0;
        while (1){
            char c = getchar();
            if (c == '\n'){
                line_finished = 1;
                break;
            }
            if (strchr("[{<(", c) != NULL){
                push(&stack, c);
                continue;
            }
            node *current = pop(&stack);
            if (current == NULL){
                syntax_err_score += get_score(c);
                break;
            }
            switch (c){
            case ')':
                if (current->data == '('){
                    continue;
                }
                break;
            case ']':
                if (current->data == '['){   
                    continue;
                }
                break;
            case '}':
                if (current->data == '{'){   
                    continue;
                }
                break;
            case '>':
                if (current->data == '<'){   
                    continue;
                }
            }
            syntax_err_score += get_score(c);
            break;
        }
        if (!line_finished){
            while (getchar() != '\n');
        }
    }
    printf("syntax error score = %d\n", syntax_err_score);
    return 0;
}
