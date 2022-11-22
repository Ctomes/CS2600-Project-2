//#include <../header/trip.h>
//#include <../header/flightExpneses.h>
#include <stdio.h>
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
    

    //some testing variables
    int input_days = 6;
    float input_arrival = 13.4;
    float input_departure = 17.5;
    float input_airfareCost = -240;
    if(checkInput(input_days,input_arrival,input_departure,input_airfareCost)==1){
        printf("hello");
    }
    else {
        printf("error: invalid input detected.\n");
        printf("Please enter valid input again.\n\n");
    }
    

    return 0;
}
