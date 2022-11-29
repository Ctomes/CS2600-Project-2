#include <stdio.h>
#include "../header/trip.h"
#include "../header/conferenceFee.h"

int main()
{
    printf("This program will impliment a trip calcular for Project 2 CS2600\n");
    Trip trip;
    Trip *tripPointer = &trip;

    // sample case setting
    tripPointer->daysSpentOnTrip=3;
    tripPointer->timeOfDeparture=10.55;
    tripPointer->timeOfArrival=16.30;
    tripPointer->airfare = 100.20;


    calculateConferenceExpenses(tripPointer);

    printf("This is called after calculateConferenceExpenses is called \n\n");
    printf("conference fees $%.2f\n", &tripPointer->conferenceFees);
    printf("conference fees allowable $%.2f\n", &tripPointer->conferenceFeesAllowable);
    printf("hotel fees $%.2f\n", &tripPointer->hotelFees);
    printf("hotel fees allowable $%.2f\n", &tripPointer->hotelFeesAllowable);
    printf("meal fees $%.2f\n", &tripPointer->mealFees);
    printf("meal fees allowable fees $%.2f\n", &tripPointer->mealFeesAllowable);

    printf("Airfare: $%.02f\nDays spent on trip: %d \nDeparture: %.02f, Arrival: %.02f\n",trip.airfare,trip.daysSpentOnTrip,trip.timeOfDeparture, trip.timeOfArrival);
    return 0;



}