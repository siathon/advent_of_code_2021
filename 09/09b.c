#include <stdio.h>
#include <stdlib.h>

typedef struct Point{
    char height;
    char is_lowest;
}point;

typedef struct Node{
    unsigned short x, y, size;
    struct Node *next;
}node;

void print_list(node **list){
    node *temp = *list;
    while (temp != NULL){
        printf("(%lu, %lu, %lu)->", temp->x, temp->y, temp->size);
        temp = temp->next;
    }
    printf("NULL\n");
}

void add_node(node **list, unsigned short x, unsigned short y, unsigned short size){
    node *n = (node*)malloc(sizeof(node));
    n->x = x;
    n->y = y;
    n->next = *list;
    *list = n;
}

node* pop_node(node **list){
    node *n = *list;
    *list = n->next;
    return n;
}

int contains(node **list, unsigned short x, unsigned short y){
    node *temp = *list;
    while (temp != NULL){
        if (temp->x == x && temp->y == y){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
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

void add_sorted(node **list, unsigned short x, unsigned short y, unsigned short size){
    node *n = (node*)malloc(sizeof(node));
    n->x = x;
    n->y = y;
    n->size = size;
    if (*list == NULL || (*list)->size <= size){
        n->next = *list;
        *list = n;
        return;
    }
    node *current = *list;
    while (current->next != NULL && current->next->size >= n->size) {
        current = current->next;
    }
    n->next = current->next;
    current->next = n;
}

int main(){
    point **floor = (point**)calloc(sizeof(point*), 100);
    for (int i = 0; i < 100; i++){
        floor[i] = (point*)calloc(sizeof(point), 100);
    }
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            floor[i][j].height = getchar();
            floor[i][j].is_lowest = 1;
        }
        getchar();
    }
    node *low_points = NULL;
    int cnt = 0;
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            if (i - 1 >= 0 && floor[i-1][j].height <= floor[i][j].height){
                floor[i][j].is_lowest = 0;
                continue;
            }
            if (j - 1 >= 0 && floor[i][j-1].height <= floor[i][j].height){
                floor[i][j].is_lowest = 0;
                continue;
            }
            if (i + 1 < 100 && floor[i+1][j].height <= floor[i][j].height){
                floor[i][j].is_lowest = 0;
                continue;
            }
            if (j + 1 < 100 && floor[i][j+1].height <= floor[i][j].height){
                floor[i][j].is_lowest = 0;
                continue;
            }
            cnt++;
            add_node(&low_points, i, j, 0);
        }
    }
    node *basins = NULL;
    for (int i = 0; i < cnt; i++){
        node *stack = NULL;
        node *visited = NULL;
        node *low_point = pop_node(&low_points);
        add_node(&stack, low_point->x, low_point->y, 0);
        while (stack != NULL){
            node *point = pop_node(&stack);
            add_node(&visited, point->x, point->y, 0);
            if (point->x - 1 >= 0 && 
                floor[point->x-1][point->y].height != '9' && 
                !contains(&visited, point->x-1, point->y) &&
                !contains(&stack, point->x-1, point->y)){
                add_node(&stack, point->x - 1, point->y, 0);
            }
            if (point->y - 1 >= 0 && 
                floor[point->x][point->y-1].height != '9' && 
                !contains(&visited, point->x, point->y-1) &&
                !contains(&stack, point->x, point->y-1)){
                add_node(&stack, point->x, point->y - 1, 0);
            }
            if (point->x + 1 < 100 && 
                floor[point->x+1][point->y].height != '9' && 
                !contains(&visited, point->x+1, point->y) &&
                !contains(&stack, point->x+1, point->y)){
                add_node(&stack, point->x + 1, point->y, 0);
            }
            if (point->y + 1 < 100 && 
                floor[point->x][point->y+1].height != '9' && 
                !contains(&visited, point->x, point->y+1) &&
                !contains(&stack, point->x, point->y+1)){
                add_node(&stack, point->x, point->y + 1, 0);
            }
        }
        int size = list_size(&visited);
        add_sorted(&basins, low_point->x, low_point->y, size);
    }

    node *current = basins;
    int res = 1;
    for (int i = 0; i < 3; i++){
        res *= current->size;
        current = current->next;
    }
    printf("result = %d\n", res);
    return 0;
}
