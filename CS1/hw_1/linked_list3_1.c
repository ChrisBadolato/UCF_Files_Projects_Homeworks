#include <stdio.h>
#include <stdlib.h>

void print_list(struct node_t * head, int value);

int main () {

typedef struct node {
    int val;
    struct node * next;
} node_t;

node_t * head = NULL;
head = malloc(sizeof(node_t));
if (head == NULL) {
    return 1;
}
head->next = malloc(sizeof(node_t));
head->next->next = malloc (sizeof(node_t));
head->val = 1;
head->next->val = 2;
head->next->next->val = 500;
head->next->next->next = NULL;

printf("Value 1. 1st node, after head points to next: %d\n", head->val);
printf("Value 2: second node, after next, points to Null but value is: %d\n", head->next->val);
printf(" value 3: node 3: %d\n", head->next->next->val);

node_t * current = head;

while (current != NULL) {
    printf("current val: %d\n", current->val);
    current = current->next;

}



return 0;
}

