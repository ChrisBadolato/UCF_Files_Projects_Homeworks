/*
Christopher Badolato
cop3223 003
12/2/16
This program will organize our information from three different races, a marathon, a 5k and 10k.
(1) Processing Individual Registrations
    Each individual will be processed into our person structure and saved as an array of persons called individuals
    this will be sent around our program for different use.

(2) Processing Team Registrations
    Each team will be processed into the array of teams. Each individual within that team will be processed as an individual on the individual array.
    I was not sure what to do if a team with a size smaller than 5 were to register.
    In the directions it says team size can not be less than 5 or greater than 50, but not what to do if the
    amount was outside of the interval.

(3) Processing the running events
    Each persons running event will be scanned in and printed out as either 5k, 10k, or marathon.
    their times will also be saved into our person structure.

(4) Calculating total donations
    our final total will be calculated with each donation from every person along with the fee they paid to register for the race.
    receiving the wrong value for my total donations calculations. Could not figure out the reason why.
*/

#include <stdio.h>

#define TEAMS 200
#define RUNNERS 10000
#define LENGTH 20
#define TEAMSIZE 50

    //structures
struct person {
    char name[LENGTH];
    int number;
    int age;
    int event;
    float money;
    float time;
};

struct team {
	char name[LENGTH];
	int nummembers;
	float money;
	struct person members[TEAMSIZE];
};

    //Structure for age groups added to compare age groups with the age of the individuals running the marathon.
struct agegroup {
    int start_age;
    int end_age;
    float time;

};

    //function prototypes
void print_indv(struct person indv);
void print_team(struct team teams);
void comparison(struct person indviduals[], struct agegroup age[]);
void team_money(struct team teams[]);
void team_member_money(struct team teams[]);
void most_raised(struct person indviduals[], int indv_count);

    //main function
int main () {

    FILE * ifp;
        //Here we are creating our arrays of structures
        //individual is our array of "person" which will store individual persons information.
        //all_teams is our arry of "teams" which will store our teams.
        //finally our age group struct, added to simplify passing over our age groups to our functions.
    struct person individual[RUNNERS];
    struct team all_teams[TEAMS];
    struct agegroup age_groups[10];
        //variable declaration
        //our team_count keeps track of how many teams we have total.
        //our individual count keeps track of each individual person added.
    char filename[LENGTH], racer_type[LENGTH], indv_name[LENGTH];
    float early_reg_cost, regular_reg_cost, team_reg_cost, total_donations = 0;
    int early_buyers, reg_total, regular_buyers, lower_price_buyers;
    int i, j, team_count = 0, indv_count = 0;
        //scans our input file
    printf("Please enter the input file name.\n");
    scanf("%s", filename);

    ifp = fopen(filename, "r");

    fscanf(ifp, "%f%f", &early_reg_cost, &regular_reg_cost);
    fscanf(ifp, "%f", &team_reg_cost);
    fscanf(ifp, "%d", &early_buyers);
        //for our number of early buyers first we check to see if they are an individual or part of a team.
    for (i=0; i<early_buyers; i++) {
        fscanf(ifp, "%s", racer_type);
            //if INDV is read in by our program, the value from the strcmp will equal 0.
        if (strcmp(racer_type, "INDV") == 0) {
            //This scan grabs our values for our structure person.
            //indv_count starts at 0, scanning in each individuals information to be stored in our person structure.
        fscanf(ifp, "%s %d %d %f", individual[indv_count].name, &individual[indv_count].age, &individual[indv_count].event, &individual[indv_count].money);
            //we want each individuals number to match for scanning in the times for each runner later in the program.
        individual[indv_count].number = indv_count + 1;
        print_indv(individual[indv_count]);
            //for each individual added to the individuals array we want to add to our individual counter.
        indv_count++;
        }
            //if our program reads TEAM our strcmp will be equal to 0 showing that we are at a team name and number of members.
        else if (strcmp(racer_type, "TEAM") == 0) {
            //Here our team name and number of members of that team will be scanned in to our array of teams.
        fscanf(ifp, "%s\n", all_teams[team_count].name);
        fscanf(ifp, "%d", &all_teams[team_count].nummembers);
                //we need another for loop here to scan in each member within each team.
                //we store them on our members structure that is within our all_team array of structures.
            for(j=0; j<all_teams[team_count].nummembers; j++){
                fscanf(ifp, "%s %d %d %f", all_teams[team_count].members[j].name, &(all_teams[team_count].members[j].age), &(all_teams[team_count].members[j].event), &(all_teams[team_count].members[j].money));
                    //here we update our member number for each individual within each team.
                all_teams[team_count].members[j].number = indv_count + 1;
                    //here our individuals array is updated with the members of each team.
                    //this allows for each member to match its corresponding member number for later in the program.
                individual[indv_count] = all_teams[team_count].members[j];
                    //we need to add each individual persons donation, within our specific team.
                    //this will be each teams total donation after the program has run through.
                all_teams[team_count].money += all_teams[team_count].members[j].money;
                    //add this individual to our counter.
                indv_count++;
            }
            //prints our information about each team with our all_teams array.
        print_team(all_teams[team_count]);
            //adds to our total teams counter.
        team_count++;
        }
    }
        //we can now scan in our regular priced buyers.
    fscanf(ifp, "%d", &regular_buyers);
        //we need to save our total lower priced buyers (team members and early individuals).
    lower_price_buyers = indv_count;
        //now we must loop through our next values while also scanning in each person to their respective position on the individual array.
        //the loop goes passed our earlier registers and adds our regular buyers to match the corresponding member number.
    for(i=lower_price_buyers; i<(regular_buyers + lower_price_buyers); i++){
        fscanf(ifp, "%s %d %d %f", individual[i].name, &individual[i].age, &individual[i].event, &individual[i].money);
            //each individual race number is updated to correspond with the array they were scanned into.
        individual[indv_count].number = indv_count + 1;
            //our regular priced individuals are printed. sending our individuals array to our print function.
        print_indv(individual[indv_count]);
            //individual counter is updated.
        indv_count++;
    }
        // here we can in our values for each individuals number and the time they took for the race.
    for(i=0; i<indv_count; i++) {
        fscanf(ifp, "%d %f", &individual[i].number, &individual[i].time);
    }
        //this loop scans in our values to our age group structures.
        //They are scanned into an array of age_groups.
    for(i=0; i<10; i++) {
        fscanf(ifp, "%d %d %f", &age_groups[i].start_age, &age_groups[i].end_age, &age_groups[i].time);
    }
        //Finally after all of our numbers have been correctly scanned into the program we call our functions
        //comparison will take our individual array and our age_groups array.
    comparison(individual, age_groups);
        //each team will be compared to see whom donated the most money.
    team_money(all_teams);
        //Each team member who donated the most will be printed.
    team_member_money(all_teams);
        //the individual who rasied the most will be printed.
    most_raised(individual, indv_count);
        //our total amount ofdonations from each individual will be added together.
    for(i=0; i<indv_count + 1; i++) {
        total_donations += individual[i].money;
    }
        //with our scanned in information, and our totals for early buys, regular buyers and out total team count. We can solve for our total donation amount.
    total_donations += (lower_price_buyers * early_reg_cost);
    total_donations += (regular_buyers * regular_reg_cost);
    total_donations += (team_count * team_reg_cost);
        //prints total donation value.
    printf("You have raise %f for charity!", total_donations);
    fclose(ifp);
    return 0;
}

//Post condition: This function will print out our individual persons name, event type and their assigned number.
//if their corresponding event number is 5, it will print their event type (5k). 10 to 10k and 42(or anything else) to marathon.
//Pre-conditions: We will need our person struct for this print.
//While we are looping in main, we want to print each individuals event type.
void print_indv(struct person indv) {


    if(indv.event == 5) {
            printf("%s registered for the 5k: They have been assigned number %d.\n", indv.name, indv.number);
    }
    else if(indv.event == 10) {
            printf("%s has registered for the 10k: They have been assigned number %d.\n", indv.name, indv.number);

    }
    else {
        printf("%s has registered for the Marathon: They have been assigned number %d.\n", indv.name,  indv.number);
    }
    return;
}

//Post condition: We need this function to print out our team names and the number of members.
//each team member will be sent to our individuals print function.
//which loops for each individual on the team showing their name, event and number they've been assigned.
//Pre-conditions: we need our values from our team structure to print the team names and number of members.
void print_team(struct team teams) {
    int i;
    printf("%s team registered for the event! they have %d members:\n", teams.name, teams.nummembers);
    for(i=0; i<teams.nummembers; i++) {
        print_indv(teams.members[i]);
    }
    return;
}

//Post condition:this function will find and print out our winners of each race, their name, and their time.
//This function will also compare our runners with their age group times to see if they qualify for the next marathon.
//Pre-conditions: To complete these tasks we need our individuals array of our person structure and also our age array of age groups.
void comparison(struct person individuals[], struct agegroup age[]) {
        //we will need an array of qualified runners.
    int i, j, qualifiers[RUNNERS];
        //declare fastest_5k and fastest_10k as type "person"
    struct person fastest_5k;
    struct person fastest_10k;
        //initialize our fastest race times to 0.
    fastest_5k.time = 0;
    fastest_10k.time = 0;
        //for every runner in the race we first check to see which race they are apart of, if they are not part of the 5k or 10k
        //They are automatically in the Marathon and we will jump to the next for loop.
    for(i=0; i<RUNNERS; i++){
            qualifiers[i] = 0;
        if(individuals[i].event == 5) {
                //if our individuals time is greater than the previous fastest 5k time
                //we will change our fastest 5k time to our individual.
                //they are saved as the fastest individual for 5k.
            if(individuals[i].time > fastest_5k.time) {
                fastest_5k = individuals[i];
            }
        }
        if(individuals[i].event == 10) {
                //same as above, if our individuals time is greater than the previous
                //that individual will have the fastest 10k time.
            if(individuals[i].time > fastest_10k.time) {
                fastest_10k = individuals[i];
            }
        }
    }
        //we print our racer and their time.
    printf("5k Race: %s has the fastest time with %.2f minutes!\n", fastest_5k.name, fastest_5k.time);
    printf("10k Race %s have the fastest time with %.2f minutes!\n", fastest_10k.name, fastest_10k.time);
        //we are checking to see if our individual qualifies for the marathon by comparing the individuals age, to the corresponding age group.
    for(i=0; i<RUNNERS; i++){
        if(individuals[i].event == 42) {
            for(j=0; j<10; j++) {
                    //if our individual marathon runners age is  greater than the starting age and less then the ending age, our program will decide which age group
                    //that person should be a part of.
                if(individuals[i].age >= age[j].start_age && individuals[i].age <= age[j].end_age) {
                        //if their individual times are greater than the age times, they will qualify for the Marathon.
                    if(individuals[i].time <= age[j].time){
                            printf("%s has qualified for the Marathon with a time of %f.\n", individuals[i].name, individuals[i].time);

                    }
                }
            }
        }
    }
}

//Post condition:Here we will check to see which team has donated the most money and print out their name and the amount the raised
//Pre-conditions:We only need our teams array of team structure for this function.
void team_money(struct team teams[]) {
        //declare most_money as type "team"
    struct team most_money;
    most_money.money = 0;
    int i;
    for(i=0; i<TEAMS; i++) {
            //if our current teams money is greater than the previous teams, most_money will become the team that donated the most.
        if(teams[i].money > most_money.money) {
            most_money  = teams[i];
        }
    }
    printf("The %s team raise the most money with a team donation of $%.2f\n",most_money.name, most_money.money);

}

//Post condition:We must loop through each team member to see who has donated the most for each team.
//Pre-conditions we need our teams structure with our teams array for this function
void team_member_money(struct team teams[]) {
    int i, j;
    struct person member_money;

        for(i=0; i<TEAMS; i++) {
            member_money.money = 0;
                //as we loop through each team we also much loop through each member of the team.
            for(j=0; j < teams[i].nummembers; j++){
                    //if our current member_money value is less than our team members money
                    //team members money becomes the new highest value.
                if(member_money.money < teams[i].members[j].money) {
                    member_money = teams[i].members[j];
                }
            }
            //since our value will be greater than 0 once our loop finishes it will print which member of which team has donated the most money.
            //along with how much they donated.
            if(member_money.money != 0){
            printf("%s raise the most money on team %s with a donation of $%.2f\n", member_money.name, teams[i].name, member_money.money);

            }
        }

}

//Post condition:Finally we will check to see which individual raised the most.
//Pre-conditions: we need our individuals array of our person structure, and our integer for our total individuals.
void most_raised(struct person individuals[], int indv_count) {
        //defines indv as type person.
    struct person indv;
    int i;
    indv.money = 0;
        //for each individual we want to check to see if the amount they donated is greater than the previous persons.
        //if it is we save it to compare it next loop.
    for(i=0; i< indv_count + 1; i++) {
            if(individuals[i].money > indv.money) {
                indv = individuals[i];
            }
    }
    printf("%s raised $%.2f!\n", indv.name, indv.money);
}
