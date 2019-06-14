/*Christopher Badolato
COP 3223 003
11/11/2016
This program will run an entered input file to run a gala for an auction and a raffle.
Printing out your total revenue, how many tickets have been sold and to which person they were sold to.
It will print our bid item, which person bought the item, and for how much they bought it for.
finally it will show the winners of the raffle and the auction.
 */

#include <stdio.h>
#include <string.h>

//Constants to be used.
//MAXSIZE is the maximum size of all strings
//MAXAUCTIONITEMS is the maximum number of items in the auction
//MAXRAFFLE is the maximum number of available raffle tickets
#define MAXSIZE 100
#define MAXAUCTIONITEMS 1000
#define MAXRAFFLE 1000

//Function prototypes - do not change these
void initRaffle(int raffles[MAXRAFFLE]);
void initAuction(float auction[2][MAXAUCTIONITEMS]);
void buyTickets(float * totalRevenue, int * ticketsSold, int numTickets, float price);
void buyRaffle(float * totalRevenue, int raffles[MAXRAFFLE], int availTickets, int numTickets, int person);
void bid(float auction[2][MAXAUCTIONITEMS], float bid, int auctionNumber, int person, int flag);
float awardAuction(float auction[2][MAXAUCTIONITEMS], int auctionNumber);
void awardRaffle(int raffles[MAXRAFFLE], int raffleNumber, int winner);

//Main function
int main() {
    FILE * ifp;
    char filename[MAXSIZE], event[MAXSIZE], item[MAXSIZE];
    float presale, dayOf, totalRevenue = 0;
    float auctions[2][MAXAUCTIONITEMS];
    int raffles[MAXRAFFLE];
    int numPresale, numAuctions, numRaffle, numPrizes, numEvents;
    int i, j, ticketsSold = 0, auctionFlag = 1;

    printf("Please enter the input file name.\n");
    scanf("%s", filename);

    ifp = fopen(filename, "r");

    fscanf(ifp, "%f%f%d", &presale, &dayOf, &numPresale);

    totalRevenue += numPresale * presale;
    ticketsSold = numPresale;

    fscanf(ifp, "%d", &numAuctions);
    fscanf(ifp, "%d%d", &numRaffle, &numPrizes);
    fscanf(ifp, "%d", &numEvents);

    initRaffle(raffles);
    initAuction(auctions);




    for (i=0; i<numEvents; i++) {
        fscanf(ifp, "%s", event);

        if (strcmp(event, "BUY") == 0) {
            fscanf(ifp, "%s", item);
            if (strcmp(item, "TICKET") == 0) {
                int numTickets;
                fscanf(ifp, "%d", &numTickets);
                buyTickets(&totalRevenue, &ticketsSold, numTickets, dayOf);

            }
            else if (strcmp(item, "RAFFLE") == 0){
                int numTickets, person;
                fscanf(ifp, "%d%d", &numTickets, &person);
                buyRaffle(&totalRevenue, raffles, numRaffle, numTickets, person);
            }
        }
        else if (strcmp(event, "BIDITEM") == 0) {
            int itemNumber, person;
            float amount;
            fscanf(ifp, "%d%d%f", &itemNumber, &person, &amount);
            bid(auctions, amount, itemNumber, person, auctionFlag);
        }
        else if (strcmp(event, "CLOSEAUCTION") == 0) {
            printf("CLOSE AUCTION.\n");
            auctionFlag = 0;
        }
        else if (strcmp(event, "AWARD") == 0) {
            fscanf(ifp, "%s", item);
            if (strcmp(item, "AUCTION") == 0) {
                int auctionNumber;
                fscanf(ifp, "%d", &auctionNumber);
                totalRevenue += awardAuction(auctions, auctionNumber);
            }
            else if (strcmp(item, "RAFFLE") == 0){
                int raffleNumber, winner;
                fscanf(ifp, "%d%d", &raffleNumber, &winner);
                awardRaffle(raffles, raffleNumber, winner);
            }
        }
        else {
            printf("TOTALREVENUE is $%.2f.\n", totalRevenue);
        }
    }

    fclose(ifp);
    return 0;
}

// Pre-conditions: raffles is the collection of all possible raffle tickets
// Post-condition: Each raffle ticket should have a default owner number
//                      that indicates it has not been sold yet
//
// What to do in this function: Each index number represents a different
// ticket number for the Raffle.  The value in the array at that index is
// the ticket's owner (an index that represents a person at the Fundraising
// Gala).Initialize all the values in the array to a integer that indicates

// the ticket has not been sold yet.
void initRaffle(int raffles[MAXRAFFLE]) {
    int i;
        //initialize all values the raffles array to -1
    for(i=0; i<MAXRAFFLE; i++) {
        raffles[i] = -1;
    }
    return;
}

// Pre-conditions: auction is the collection of all possible auction items
// Post-condition: Each auction should have a default price of 0 and a default
//                 bidder number that indicates it has not been bid on yet
//
// What to do in this function: Each index number represents a different
// auction item for the Raffle.  Select one row of the two-dimensional
// array to be for bids; the other row will be for people (the current highest
// bidder).  Initialize all bids to zero and initialize all people to a number
// that indicates the item has not been bid on yet

void initAuction(float auction[2][MAXAUCTIONITEMS]) {
    int i, count = 1;
            //initialize all bid values to 0 and all person values to 1,2,3,4...MAXAUCTION.
        for(i=0; i<MAXAUCTIONITEMS; i++){
            auction[0][i] = 0;
            auction[1][i] = count++;
        }

        return;
}

// Pre-conditions: totalRevenue is a pointer to the total amount that the Gala has earned
//                 ticketsSold is a pointer to the current number of tickets sold
//                 numTickets is the number of tickets that the person would like to purchase
//                 price is the current cost of the tickets (the DayOf price)
// Post-condition: Sells numTickets to the current person at price and updates the number
//                      of tickets sold and the current total revenue
//
// What to do in this function: Calculate the cost of the tickets and add it to the total
// revenue.  Print out the ticket numbers that were sold to the screen.  Update the number
// of tickets that have been sold.

void buyTickets(float * totalRevenue, int * ticketsSold, int numTickets, float price) {

    double total_ticket_cost = 1;
    int tix_before_sale, tix_after_sale;

        //calculates tickets sold and total revenue from ticket sales only.
        //points back to the values in main changing the total revenue and tickets sold.
    tix_before_sale = *ticketsSold;
    tix_after_sale = tix_before_sale + numTickets;
    total_ticket_cost = (numTickets * price);
    *ticketsSold += numTickets;
    *totalRevenue += total_ticket_cost;
    printf("Tickets Sold %d-%d\n", tix_before_sale + 1, tix_after_sale + 1);

    return;

}

// Pre-conditions: totalRevenue is a pointer to the total amount that the Gala has earned
//                 raffles is an array of all possible raffle tickets
//                 availTickets is the number of raffle tickets available to be sold
//                 numTickets is the number of raffle tickets that the person would like to purchase
//                 person is the numerical identifier of the person attempting to buy tickets
// Post-condition: Sells numTickets to the current person if tickets are available, or sells as
//                      as many as are left, or sells none if no tickets are left.  Updates totalRevenue
//                      if any tickets are sold.  Each ticket sells for $2
//
// What to do in this function: The value stored in each index of raffles should be the number of the
// person that bought that ticket.  For example if person 35 holds raffle tickets 11-15, then elements 11-15
// of raffles should all be equal to 35.
//
// Traverse to the next available ticket in the raffles array, if it exists.  If it does not exist, print
// out that no tickets will be given to this person.  If it does exist, check to see if there are enough
// tickets left for the person to get the full number they are looking for.  If there are not enough for
// the full amount, give them all the tickets that are left.  Print out which tickets they are given.
// Update totalRevenue with the number of tickets sold at $2 each.

void buyRaffle(float * totalRevenue, int raffles[MAXRAFFLE], int availTickets, int numTickets, int person) {
    int i, j;
        //if we have no available tickets, none will be given out
    if(availTickets == 0) {
        printf("NO RAFFLE TICKETS given to PERSON %d\n", person);
        return;
       }
        //if they don't want any tickets none will be purchased.
    if(numTickets == 0) {
        printf("No tickets were purchased.\n");
        return;
       }
        //we can only have 1000 raffle tickets sold.
    for(i=0; i<MAXRAFFLE; i++) {
            //if our value at raffles is -1 then we have not sold raffle tickets yet.
        if (raffles[i] == -1) {
                //if our number of tickets purchased is below 100
            if(numTickets <= availTickets) {
                    //go to spot on array raffle place person value at that place to purchase those tickets.
                for(j=i; j < (i+numTickets); j++) {
                    raffles[j] = person;
                        // requests can be fulfilled.
                    if(j == i + numTickets - 1){
                        printf("RAFFLE TICKETS %d - %d given to PERSON %d \n", i, j, person);
                            //adds Total Revenue to Total Revenue in main.
                        *totalRevenue += (numTickets * 2);
                        return;
                    }
                }
            }
                // if there are not enough raffle tickets remaining.
            else if (numTickets + i > MAXRAFFLE) {
                    //fill in the spot on the array with person value.
                    //until the end of the raffle array at MAXRAFFLE
                for(j=i; j<MAXRAFFLE; j++){
                    raffles[j] = person;
                        //if j is equal to 999 no more raffle tickets remain.
                    if(j == MAXRAFFLE - 1) {
                        printf("RAFFLE TICKETS %d - %d given to PERSON %d\n", i, MAXRAFFLE, person);
                        *totalRevenue += (2 * (MAXRAFFLE - i));
                        return;
                    }
                }
            }
            else {
                    //if user asks for an amount of tickets over availTickets they will be given the amount up to availTickets
                for(j=i; j<availTickets; j++){
                    raffles[j] = person;
                        //no more than availTickets will be sold.
                        //it will add what it can to total revenue.
                    if(j == availTickets - 1 ) {
                        printf("RAFFLE TICKETS %d - %d given to PERSON %d\n", i, j, person);
                        *totalRevenue += (2 * availTickets);
                        return;
                    }
                }
            }
        }
    }
        printf("NO RAFFLE TICKETS given to PERSON %d\n", person);
        return;
}

// Pre-conditions: auction is an 2D array that holds the current highest bid and the person with
//                 the highest bid
//                 bid is a new proposed bid
//                 auctionNumber is the numerical identifier for the item being bid on
//                 person is the numerical identifier of the person attempting to bid
//                 flag is a value that indicates whether or not bids are still being accepted
// Post-condition: Updates the auctions with a new high bid if present
//                      Will not accept new bids that are not higher than old bids
//                      Will not accept new bids if the auctions are closed
//
// What to do in this function: Check to see if the auctions are still open based on flag
//
// If bids are still being accepted, check to see if bid is higher than the current bid for
// the auction.  If it is higher, update the auction with the new bid and the new person number
// Print out the result of either accepted or rejected

void bid(float auction[2][MAXAUCTIONITEMS], float bid, int auctionNumber, int person, int flag) {

        //if our flag is less than or equal to zero, the auction will close.
    if (flag <= 0) {
                    return;
    }
        //if our current bid is greater than our previous highest bid the new value will be place
        //at that auction index number in the array auction.
    if (bid > auction[0][auctionNumber]) {
        printf("BIDITEM %d ACCEPTED for PERSON %d at %.2f DOLLARS\n", auctionNumber, person, bid);
        auction[0][auctionNumber] = bid;
        auction[1][auctionNumber] = person;
    }
        //If your bid is lower than the current value, the bid will be rejected.
    else {
        printf("BIDITEM %d REJECTED for PERSON %d at %.2f DOLLARS\n",auctionNumber, person, bid);
    }
    return;
}



// Pre-conditions: auction is an 2D array that holds the current highest bid and the person with
//                 the highest bid
//                 auctionNumber is the numerical identifier for the item being awarded
// Post-condition: Returns the value of the highest bid for the auction specified by auction number
//
// What to do in this function: Check to see if the auction identified by auctionNumber has any
// bids.  If so, award the auction to the person with the highest bid.  If not, print out that
// there have been no bids for this item.  Return the appropriate value to be added to totalRevenue

float awardAuction(float auction[2][MAXAUCTIONITEMS], int auctionNumber) {

        //if our bid number is equal to 0, there has not been a bid on that auction number.
    if (auction[0][auctionNumber] == 0) {
        printf("NO BIDS FOR AUCTION ITEM %d.\n", auctionNumber);
    }
        //any other value in the bid row will have a bid value
    else {
        printf("AUCTION ITEM %d WON BY PERSON %.0f for $%.2f\n", auctionNumber, auction[1][auctionNumber], auction[0][auctionNumber]);
    }
        //we need to award the person with the highest bid.
    return auction[0][auctionNumber];
}

// Pre-conditions: raffles is an array of all possible raffle tickets
//                 winner is the winning ticket number
//                 raffleNumber is the current raffle being held
//
// Post-condition: prints out the numerical identifier of the person who
//                 holds the winning ticket number

void awardRaffle(int raffles[MAXRAFFLE], int raffleNumber, int winner) {

        //prints our raffle number and the number of the winner, which is taken from our raffles array at position "winner"
    printf("AWARD RAFFLE %d TO PERSON %d\n", raffleNumber, raffles[winner]);

}
