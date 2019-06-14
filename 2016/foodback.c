//
//
//
//
#include <stdio.h>


int main () {
    int status[2][5];
    int i, j, food_donations, food_requests, menu_choice, requests_total;
    int protein, dairy, grains, vegetables, fruits, difference;
    char food_type[5][20] = {"Protein", "Dairy", "Grains", "Vegetables", "Fruits"};

    for(i=0; i<2; i++) {
        for(j=0; j<5; j++) {
            status[i][j] = 0;
    printf("%d", status[i][j]);
        }
    }



    printf("\nWelcome to the Food Bank Management Program!\n");
    printf("What would you like to do?\n");
    printf("\t 1 - Enter a Donation.\n");
    printf("\t 2 - Enter a Request.\n");
    printf("\t 3 - Fulfill Requests\n");
    printf("\t 4 - Print a status report\n");
    printf("\t 5 - Quit\n");
    scanf("%d", &menu_choice);

    while (menu_choice != 5) {

        switch(menu_choice) {

            //take in each food type donation

    case 1:


        printf("What would you like to donate?\n");
        printf("\t 0. %s\n", food_type[0]);
        printf("\t 1. %s\n", food_type[1]);
        printf("\t 2. %s\n", food_type[2]);
        printf("\t 3. %s\n", food_type[3]);
        printf("\t 4. %s\n", food_type[4]);
        printf("\t 5. Main Menu\n");
        scanf("%d", &food_donations);


        while (food_donations) {

            switch (food_donations) {

            case 0:
            printf("How many would you like to donate?\n");
            scanf("%d", &protein);
            status[0][0] += protein;
            printf("Donation added\n");
            break;

            case 1:
            printf("How many would you like to donate?");
            scanf("%d", &dairy);
            status[0][1] += dairy;
            printf("Donation added\n");
            break;


            case 2:
            printf("How many would you like to donate?");
            scanf("%d", &grains);
            status[0][2] += grains;
            printf("Donation added\n");
            break;

            case 3:

            printf("How many would you like to donate?");
            scanf("%d", &vegetables);
            status[0][3] += vegetables;
            printf("Donation added\n");
            break;


            case 4:
            printf("How many would you like to donate?");
            scanf("%d", &fruits);
            status[0][4] += fruits;
            printf("Donation added\n");
            break;

            default:
                break;

            }
        }


        //take in each food type request

    case 2:
        printf("What would you like to request?\n");
        printf("\t 0. %s\n", food_type[0]);
        printf("\t 1. %s\n", food_type[1]);
        printf("\t 2. %s\n", food_type[2]);
        printf("\t 3. %s\n", food_type[3]);
        printf("\t 4. %s\n", food_type[4]);
        scanf("%d", &food_requests);

            switch (food_requests) {

            case 0:
            printf("How many would you like to take?\n");
            scanf("%d", &protein);
            status[1][0] += protein;
            printf("request taken\n");

            case 1:
            printf("How many would you like to take?\n");
            scanf("%d", &dairy);
            status[1][1] += dairy;
            printf("request taken\n");


            case 2:
            printf("How many would you like to take?\n");
            scanf("%d", &grains);
            status[1][2] += grains;
            printf("request taken\n");


            case 3:
            printf("How many would you like to take\n?");
            scanf("%d", &vegetables);
            status[1][3] += vegetables;
            printf("request taken\n");


            case 4:
            printf("How many would you like to take?\n");
            scanf("%d", &fruits);
            status[1][4] += fruits;

            printf("request taken\n");

            default:
                break;
            }


    break;


        //fulfill requests


    case 3:



            for(j=0; j<5; j++)

            difference = status[0][j] - status[1][j];

        if (difference < 0 ) {
            printf("request cannot be fulfulled\n");

        }
        else {
            printf("request can be filled\n");


        }

            break;




        //print status report
    case 4:

            for(j=0; j<5; j++) {
            printf("%s: \t Donations: %d\t requests %d", food_type[j], status[0][j], status[1][j]);

        }


        //quit
    default:
        break;


    }



}
printf("difference: %d", difference);


return 0;
}

