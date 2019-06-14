#include <stdio.h>

struct block {

    int number;
    char letter;
    char color[15];

};

void setup_block(struct block *b);
void print_block(struct block b);
int equal(struct block a, struct block b);

#define SIZE 3

int main () {

    int i, j;

        //so this declares the block of size 3,
        //structure block, "myset has size 3" so three structures called my_set each with
        //number, color, letter
    struct block my_set[SIZE];

    //set up and print out each block

    for(i=0; i<SIZE; i++) {
            //we are able to go through each memory adress because [i]
        setup_block(&my_set[i]);
        print_block(my_set[i]);

    }

    //see if any pairs are equal
    for(i=0; i<SIZE; i++) {
        for(j=i+1; j<SIZE; j++){
            if(equal(my_set[i],my_set[j])){
            printf("Blocks %d and %d are identical\n",i,j);

            }

        }

    }

}

//B will be initialized
void setup_block(struct block *b) {
    printf("Enter number, letter, and color\n");
    scanf("%d %c %s", &(b->number), &(b->letter), &(b->color));

}

//print out B
void print_block(struct block b) {
    printf("%d %c %s\n", b.number, b.letter, b.color);

}

//will return 1 if each component of block a and b are equal

int equal(struct block a, struct block b) {
    if(a.number == b.number && a.letter == b.letter && !strcmp(a.color, b.color)){
    return 1;
    }
    else {
    return 0;
    }
}
