#include "../header/trip.h"
#include "../header/flight_expenses.h"
#include <stdio.h>

// this function will check the user input for days spent and update the values
void daysSpent(struct FlightExpenses *flight){
    int input;
    int validInput;

    do
    {
        printf("how many days did you spend on the trip: ");
        validInput = scanf("%d",&input);
        fflush(stdin);
    } while (validInput != 1 || input < 1);
    flight->days = input;
}

// this function will check the input of the user for arrival and update its var
void arrivalTime(struct FlightExpenses *flight){
    float input;
    int validInput;

    do
    {
        printf("\nWhat time did your plane arrive: ");
        validInput = scanf("%f",&input);
        fflush(stdin);
    } while (validInput != 1 || input < 0 || input > 24);
    flight->arrival = input;
}
// this function will check the input of the user for departure and update its var
void departingTime(struct FlightExpenses *flight){
    float input;
    int validInput;

    do
    {
        printf("\nWhat time did your plane depart: ");
        validInput = scanf("%f",&input);
        fflush(stdin);
    } while (validInput != 1 || input < 0 || input > 24);
    flight->departure = input;
}
// this function will check the input of the user for airfair and update its var
void airfareCost(struct FlightExpenses *flight){
    float input;
    int validInput;

    do
    {
        printf("\nwhat was the cost of the airfare: ");
        validInput = scanf("%f",&input);
        fflush(stdin);
    } while (validInput != 1 || input < 0 );
    flight->airfareCost = input;
}



/* COMMENT THIS NEEDS TO BE REWORKED. 
    If i enter any bad input it breaks. word into a text etc.
    you need to handle situations when i put garbage in the input 
    string. You should flush the input and then immediatly prompt for good input not wait until end.
    likewise,*/
int calculateFlightExpenses(struct Trip *tripPointer){
    struct FlightExpenses flight;
    daysSpent(&flight);
    departingTime(&flight);
    arrivalTime(&flight);
    airfareCost(&flight);
    
    do
    {
        printf("departing time cannot be ahead of arrival time, please reenter values");
        departingTime(&flight);
        arrivalTime(&flight);
    } while (flight.days == 1 && flight.arrival < flight.departure);
    
    
    
    
    printf("days is:%d\n",flight.days);
    printf("arrival is:%f\n",flight.arrival);
    printf("departure is:%f\n",flight.departure);
    printf("airfareCost is:%f\n",flight.airfareCost);
    
    tripPointer->daysSpentOnTrip = flight.days;
    tripPointer->timeOfDeparture = flight.departure;
    tripPointer->timeOfArrival = flight.arrival;
    tripPointer->airfare = flight.airfareCost;
    return 0;
}
