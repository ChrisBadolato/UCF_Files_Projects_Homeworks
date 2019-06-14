#include <stdio.h>

#define TRI 1
#define BACKTRI 2
#define PYRAMID 3
#define PGRAM 4
#define QUIT 5

int menu();
void print_chars(char c, int n);
void print_triangle(char c, int n);
void print_back_triangle(char c, int n);
void print_side_pryamid(char c, int n);
void print_parallelogram(char c, int height, int width);

int main () {

    char ch;
    int ans, n, height, width;
    //gets a choice from the menu function
    ans = menu();
    //continue processing choices until the user quits
        while (ans != QUIT) {
            //ask for the character and the size for the design.
            printf("what character would you like for your design?\n");
            scanf(" %c", &ch);

            //need only one dimension for the first three choices
            if (ans != PGRAM) {
                printf("What size do you want your design to be?\n");
                scanf("%d", &n);
            }

            //get both dimensions for the parallelogram.
            else {
                printf("Height of your design?\n");
                scanf("%d", &height);
                printf("What is the width of your design?\n");
                scanf("%d", &width);
            }

            if (ans == TRI) {
                print_triangle(ch, n);
            }
            if (ans == BACKTRI){
                print_back_triangle(ch, n);
            }
            if (ans == PYRAMID) {
                print_side_pyramid(ch, n);
            }
            if (ans == PGRAM){
                print_parallelogram(ch, height, width);
            }

            //get new choice from the menu function.
            ans = menu();
        }
    return 0;

}
//pre-conditions: none
//post conditions: prints menu, propompts user for choice, returned once valid choice is entered.
int menu () {
    int choice = 0;
    printf("which choice would you like?\n");
    printf("1. normal right triangle, left justified\n");
    printf("2. print a right triangle backwards\n");
    printf("3. Print a pyramid\n");
    printf("4. print a parallelogram\n");
    printf("5. quit\n");

    //Loop until a valid choice is entered.
    while(1) {
        scanf("%d", &choice);
        if (choice < TRI || choice > QUIT) {
            printf("sorry that is not a valid choice.");

        }
        else {
            break;
        }
   return choice;
    }

}

//pre-conditions: c is a printable char. and n >= 0
//post c will be printed n times.
void print_chars(char c, int n) {
    int i;
    for(i=0; i<n; i++) {
        printf("%c", c);
    }
}
//c is a printable char.
//a triangle with char c on n rows
void print_triangle(char c, int n) {
    int i;
    for (i=1; i<=n; i++) {
    print_chars(c, i);
    printf("\n");
    }
}
//backward triangle design
void print_back_triangle(char c, int n){
    int i;
    for(i=n; i>0; i--){
        print_chars(c, i);
        printf("\n");
    }

}
//backward triangle
void print_side_pyramid(char c, int n) {
    print_triangle(c, n);
    print_back_triangle(c, n-1);
}

//parallelogram

void print_parallelogram(char c, int height, int width) {
 int i;

 for (i=0; i<height; i++) {
    print_chars(' ', i);
    print_chars(c, width);
    printf("\n");
 }

}






