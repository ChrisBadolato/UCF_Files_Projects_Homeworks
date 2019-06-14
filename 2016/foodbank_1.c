int main () {
    int status[2][5];
    int i, j, food_donations, food_requests, menu_choice, requests_total;
    int donation_amount, request_amount;
    int difference;
    char food_type[5][20] = {"Protein", "Dairy", "Grains", "Vegetables", "Fruits"};

    for(i=0; i<2; i++) {
        for(j=0; j<5; j++) {
            status[i][j] = 0;
    printf("%d", status[i][j]);
        }
    }


    while (menu_choice != 5) {

    printf("\nWelcome to the Food Bank Management Program!\n");
    printf("What would you like to do?\n");
    printf("\t 1 - Enter a Donation.\n");
    printf("\t 2 - Enter a Request.\n");
    printf("\t 3 - Fulfill Requests\n");
    printf("\t 4 - Print a status report\n");
    printf("\t 5 - Quit\n");
    scanf("%d", &menu_choice);



    if(menu_choice == 1) {

        printf("What would you like to donate?\n");

        for(i=0; i<5; i++) {
            printf("\t %d. %s\n", i, food_type[i]);
        }
        scanf("%d", &food_donations);
        printf("Type a donation amount.\n");
        scanf("%d", &donation_amount);
        status[0][food_donations] += donation_amount;
        printf("Donation added\n");
    }

    else if (menu_choice == 2) {
        printf("What would you like to request?\n");

        for(i=0; i<5; i++) {
            printf("\t %d. %s\n", i, food_type[i]);
        }
        scanf("%d", &food_requests);
        printf("Type a request amount.\n");
        scanf("%d", &request_amount);
        status[1][food_requests] += request_amount;
        printf("Request added\n");
    }

    else if (menu_choice == 3) {
        for(j=0; j<5; j++){
            difference = status[0][j] - status[1][j];
            if (difference < 0 ) {
                printf("request %s cannot be fulfulled\n", food_type[j]);
            }
            else {
                printf("request %s can be filled\n", food_type[j]);
            }
        }
    }
    else if (menu_choice == 4){
        for(i=0; i<5; i++){
            printf("%s: \t Donations:%d \t Requests:%d\n", food_type[i], status[0][i], status[1][i]);
        }
    }
    else {
        printf("this is no valid input.\n");
    }

        }
    printf("Thank you for stopping at our foodbank!");
    return 0;
    }

