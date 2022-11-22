//#include <../header/trip.h>
#include "../header/flightExpenses.h"
#include <stdio.h>

// declare the struct
struct flightExpenses flight;
// this function will ask the user for input and then will return the user input
int userInput(){
    //this section will ask the user for number of days on trip;
    printf("how many days did you spend on the trip: ");
    scanf("%d",&flight.days);
    printf("\n");
    // this section will ask the user for the airfare amount;
    printf("how much did the airfare cost?(must enter a postive number ex: 111.11): ");
    scanf("%f",&flight.airfareCost);
    printf("\n");
    // this section will as the user for the departing time;
    printf("at what time did your plane depart(must use 24 hour format ex: 4:15 pm would 16.15) : ");
    scanf("%f",&flight.departure);
    printf("\n");
    // this section will ask the user for the arriving time;
    printf("at what time did your plane arrive(must use 24 hour format ex: 4:15 pm would 16.15) :");
    scanf("%f",&flight.arrival);
    printf("\n");
    return 0;
} // userInput, will get the user input and update the struct from the header filee...


//this function will check if the input is correct
int checkInput(int days, float arrival, float departure, float airfareCost){
    //this will check if the input for days is invalid
    if (days <= 0){
        printf("cannot enter value less than one day\n");
        printf("value enterd %d \n\n",days);
        return 0;
    } 
    // this will check if the user entered a negative number for the airfare
    if (airfareCost < 0) {
        printf("the value of the airfare cannout be a negative value\n");
        printf("value enterd %f \n\n",airfareCost);
        return 0;
    }
    //this will check if the user enetered a invalid input for the hours depareted and arrived
    if (arrival < 0 || arrival > 24 || departure < 0 || departure >24){
        printf("entered a wrong value for departure or arrival\n\n");
        return 0;
    }
    return 1;
}// checkInput, will return 1 if input is valid, will return a 0



int main(){
    //must update four variable
    // days spent on trip
    // time of departure
    // time of arrival
    // airfare amount
    // must check this conditions
    // the days on trip cannot be lower than 1
    // the airfare amount cannout be negative
    // must only accept valid time for time of departure and arrival
    // note the time of departure and arrival are going to be in 24h format
    
    // this will declare the struct with the variables we need
    struct flightExpenses flight;

    //some testing variables
    int input_days = 6;
    float input_arrival = 13.4;
    float input_departure = 17.5;
    float input_airfareCost = -240;
    userInput();
    /*if(checkInput(input_days,input_arrival,input_departure,input_airfareCost)==1){
        printf("hello");
    }
    else {
        printf("error: invalid input detected.\n");
        printf("Please enter valid input again.\n\n");
    }*/
    

    return 0;
}
