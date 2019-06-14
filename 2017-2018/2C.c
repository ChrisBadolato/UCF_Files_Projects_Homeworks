//Christopher Badolato
//ENC 3211 03
//Ch432391
//9/27/18

#include<stdio.h>
void main(){
        //Initalize variables for each product.
    int productNumber;
    int numberSold, product1Sold = 0, product2Sold = 0, product3Sold = 0, product4Sold = 0, product5Sold = 0;
    float product1 = 0,product2 = 0,product3 = 0,product4 = 0,product5 = 0, total = 0;
        //To start,we need to get the first product entered this allows the second switch to work with the while loop.
        //this way we can continue to loop until -1 is entered we will just jump to the  end of the code and
        //print the totals.
    printf("Please enter the product number between 1 and 5. -1 to end: ");
    scanf("%d", &productNumber);
    switch(productNumber){
            //Each case matches with corresponding product numbers entered by the user.
            //each one will get the number of each product sold and add it to the total number of each product
            //we need to multiply our number sold by the price of the selected item. Then
            //add that to the total products sold(product1) value.
            //we do this for each product.
        case 1:
                //get number sold.
            printf("Please enter quantity sold: ");
            scanf("%d", &numberSold);
                //add to the number of products sold.
            product1Sold = product1Sold + numberSold;
                //calculate the total price so far for the current product.
            product1 = product1 + (numberSold * 2.98);
            break;
        case 2:
            printf("Please enter quantity sold: ");
            scanf("%d", &numberSold);
            product2Sold = product2Sold + numberSold;
            product2 = product2 + (numberSold * 4.50);
            break;
        case 3:
            printf("Please enter quantity sold: ");
            scanf("%d", &numberSold);
            product3Sold = product3Sold + numberSold;
            product3 = product3 + (numberSold * 9.98);
            break;
        case 4:
            printf("Please enter quantity sold: ");
            scanf("%d", &numberSold);
            product4Sold = product4Sold + numberSold;
            product4 = product4 + (numberSold * 4.49);
            break;
        case 5:
            printf("Please enter quantity sold: ");
            scanf("%d", &numberSold);
            product5Sold = product5Sold + numberSold;
            product5 = product5 + (numberSold * 6.87);
            break;
        default:
            break;
    }
        //now after we've got the first value if they didn't type -1 to quit we will follow through
        //with the rest of the code. Which is the same as above except if our "productNumber" is -1
        //we will stop collecting products entered by the user and print the totals.
    while(productNumber != -1){
        printf("Please enter the product number between 1 and 5. -1 to end: ");
        scanf("%d", &productNumber);
        switch(productNumber){
            case 1:
                printf("Please enter quantity sold: ");
                scanf("%d", &numberSold);
                product1Sold = product1Sold + numberSold;
                product1 = product1 + (numberSold * 2.98);
                break;
            case 2:
                printf("Please enter quantity sold: ");
                scanf("%d", &numberSold);
                product2Sold = product2Sold + numberSold;
                product2 = product2 + (numberSold * 4.50);
                break;
            case 3:
                printf("Please enter quantity sold: ");
                scanf("%d", &numberSold);
                product3Sold = product3Sold + numberSold;
                product3 = product3 + (numberSold * 9.98);
                break;
            case 4:
                printf("Please enter quantity sold: ");
                scanf("%d", &numberSold);
                product4Sold = product4Sold + numberSold;
                product4 = product4 + (numberSold * 4.49);
                break;
            case 5:
                printf("Please enter quantity sold: ");
                scanf("%d", &numberSold);
                product5Sold = product5Sold + numberSold;
                product5 = product5 + (numberSold * 6.87);
                break;
            default:
                break;
        }

    }
        //finally we will calculate the total of all the final product values.
        //and print them out for the user see.
    total = total + product1 + product2 + product3 + product4 + product5;

    printf("\nProduct    Qty  Sales");
    printf("\nProduct 1:  %d   %.2f ", product1Sold, product1);
    printf("\nProduct 2:  %d   %.2f ", product2Sold, product2);
    printf("\nProduct 3:  %d   %.2f ", product3Sold, product3);
    printf("\nProduct 4:  %d   %.2f ", product4Sold, product4);
    printf("\nProduct 5:  %d   %.2f ", product5Sold, product5);
    printf("\n\nTotal: %.2f ", total);

    return 0;
}
