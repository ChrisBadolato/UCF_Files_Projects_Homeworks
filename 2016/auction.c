//Christopher Badolato
//COP 3223 003
//10/14/2016
/*This program will take in a user inputted file and create an array that will display
the highest bid values from an auction. Then add them up and show total donations to
the charity.
*/


#include <stdio.h>

int main () {

        //Variable declaration
    int i, j, header, num_bids;
        //array used for our highest bid values.
    float current_bid, bids_total, highest_bid[100];
         //string used for our file name
    char file_name[30];
    FILE *ifp;

        //prompts user to input file name containing the auction data.
        //opens and reads the file
    printf("Please enter your file name containing your auction data.\n");
    scanf("%s", file_name);
    ifp = fopen(file_name, "r");

        //scans the file for header value
    fscanf(ifp, "%d", &header);

        //loops though header value and scans for the total number of bids
    for(i=0; i<header; i++) {
        fscanf(ifp, "%d", &num_bids);
        highest_bid[i] = 0;

         //loops through the number of bid values and scans each current auction bid.
        for(j=0; j<num_bids; j++) {
            fscanf(ifp, "%f", &current_bid);

                //If current bid is larger than your highest bid, it becomes the highest bid.
                //highest bid is then saved as that element value under index "i" in the array.
            if(current_bid > highest_bid[i]) {
                highest_bid[i] = current_bid;
            }
        }
    }
        //We then loop through each index value printing out our auction number and how much it sold for.
        //Also we add the bids up at each step in the loop to get our final total of each highest bid.
    for (i=0; i<header; i++) {
        printf("Auction number %d sold for $%.2f!\n",i+1 ,highest_bid[i]);
        bids_total += highest_bid[i];
    }
        //final total of highest bids outputted.
    printf("Your silent auction raised $%.2f!", bids_total);
    printf("\n");
        //file close
    fclose(ifp);

    system("pause");

    return 0;
}
