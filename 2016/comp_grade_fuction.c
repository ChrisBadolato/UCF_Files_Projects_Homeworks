#include <stdio.h>

int Comp_Grade(char grade);

int main () {

char let;
printf("Enter your grade.\n");
scanf(" %c", &let);
printf("you earned %d points.\n", Comp_Grade(let));

return 0;
}

int Comp_Grade(char grade) {
if (grade == 'A') {
    return 4;
}
else if (grade == 'B') {
    return 3;
}
else if (grade == 'C') {
    return 2;
}
else if (grade == 'D') {
    return 1;
}
else if (grade == 'F') {
    return 0;
}
else {
    return -1;
}

}
