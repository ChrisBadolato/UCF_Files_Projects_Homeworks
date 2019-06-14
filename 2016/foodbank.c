//Christopher Badolato
//10/29/16
//COP 3223 003
/*This program will allow the user to make food donation and requests to a food bank
it will then process your donations and requests printing a table of the results.
*/
#include <stdio.h>
int main () {
        //Array size declaration and character string.
    int status[2][5];
    char food_type[5][20] = {"Protein", "Dairy", "Grains", "Vegetables", "Fruits"};
        //Variable declarations
    int i, j, food_donations, food_requests, menu_choice;
    int donation_amount, request_amount;

        //Initializing the status array to 0
    for(i=0; i<2; i++) {
        for(j=0; j<5; j++) {
            status[i][j] = 0;
        }
    }
        //While loop for main menu to stay open until told to quit with 5.
    while (menu_choice != 5) {

    printf("\nWelcome to the Food Bank Management Program!\n");
    printf("What would you like to do?\n");
    printf("\t 1 - Enter a Donation.\n");
    printf("\t 2 - Enter a Request.\n");
    printf("\t 3 - Fulfill Requests\n");
    printf("\t 4 - Print a status report\n");
    printf("\t 5 - Quit\n");
    scanf("%d", &menu_choice);

        //first menu option
    if(menu_choice == 1) {
        printf("What would you like to donate?\n");
            //for loop through the string to create selection menu
        for(i=0; i<5; i++) {
            printf("\t %d. %s\n", i, food_type[i]);
        }
            //scans which food type to be donated
        scanf("%d", &food_donations);
        printf("Type a donation amount.\n");
            //scans the donation amount
        scanf("%d", &donation_amount);
            //entered food donation number brings you to the correct index within the array.
            //in this case the donations row of the array.
            //it will then add the entered donation amount into that index spot.
        status[0][food_donations] += donation_amount;
        printf("Donation added\n");
    }
        //second menu option
    else if (menu_choice == 2) {
        printf("What would you like to request?\n");
            //selection menu
        for(i=0; i<5; i++) {
            printf("\t %d. %s\n", i, food_type[i]);
        }
            //scans which food to be requested
        scanf("%d", &food_requests);
        printf("Type a request amount.\n");
            //scans a request amount
        scanf("%d", &request_amount);
            //Entered request is saved into the second row of the array at the entered food request index.
            //adds request amount to the index value.
        status[1][food_requests] += request_amount;
        printf("Request added\n");
    }
        //third menu choice
    else if (menu_choice == 3) {
            //loops through each column
        for(j=0; j<5; j++){
                //checks if requests are greater than donations and donations greater than zero
            if (status[1][j] > status[0][j] && status[0][j] > 0) {
                    //if so, donations are subtracted from the total requests
                printf("%s request can be partially fulfilled\n", food_type[j]);
                status[1][j] -= status[0][j];
                    //donations are then reset to 0.
                status[0][j] -= status[0][j];
            }
                //If the donation is 0 and requests are not 0
            else if (status[0][j] == 0 && status[1][j] != 0 ) {
                printf("%s request cannot be fulfulled\n", food_type[j]);
            }
                //If requests are greater than the donations then subtract donations from requests.
            else if (status[0][j] > status[1][j] ) {
                status[1][j] -= status[0][j];
                    //if there are 0 requests we do not want to subtract donations.
                if (status[1][j] < 0){
                    status[1][j] = 0;
                }
            }
        }
    }
        //fourth main menu choice
    else if (menu_choice == 4){
            //loops through all the values of j
        for(j=0; j<5; j++){
                //prints a table of each food type, donation, and request for the user to see.
            printf("%s: \tDonations:%d \tRequests:%d\n", food_type[j], status[0][j], status[1][j]);
        }
    }
    //Will not allow any number less than 0 or greater than 5 within the menu.
    else if (menu_choice >= 4 || menu_choice < 0) {
        printf("This is not valid option.\n");
    }
    }
    //Final output after quitting the while loop.
    printf("Thank you for stopping at our foodbank!\n");

    system("pause");

    return 0;
}

