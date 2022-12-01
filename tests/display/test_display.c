#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../header/trip.h"
#include "../../header/display.h"

void displayFees(struct Trip *tripPointer){
    printf("daysSpentOnTrip: %d\n", tripPointer->daysSpentOnTrip);
    printf("timeOfDeparture: %.2f\n", tripPointer->timeOfDeparture);
    printf("timeOfArrival: %.2f\n", tripPointer->timeOfArrival);
    printf("airfare: $%.2f\n", tripPointer->airfare);
    printf("allowedCarCost: $%.2f\n", tripPointer->allowedCarCost);
    printf("totalCarCost: $%.2f\n", tripPointer->totalCarCost);
    printf("conferenceFees: $%.2f\n", tripPointer->conferenceFees);
    printf("hotelFees: $%.2f\n", tripPointer->hotelFees);
    printf("hotelFeesAllowable: $%.2f\n", tripPointer->hotelFeesAllowable);
    printf("mealFees: $%.2f\n", tripPointer->mealFees);
    printf("mealFeesAllowable: $%.2f\n", tripPointer->mealFeesAllowable);
}

int main()
{
    struct Trip testTrips[3];
    struct Trip* tripPointers[3] = {&testTrips[0], &testTrips[1], &testTrips[2]};
    time_t t;
    srand((unsigned) time(&t));
    for (int i = 0; i < 3; i++) {
        tripPointers[i]->daysSpentOnTrip = rand() % 12 + 3;
        tripPointers[i]->timeOfDeparture = rand() % 24;
        tripPointers[i]->timeOfArrival = rand() % 24;
        tripPointers[i]->airfare = (rand() % 400 + 100);
        tripPointers[i]->allowedCarCost = (rand() % 10000 + 10000) / 100.0;
        tripPointers[i]->totalCarCost = (rand() % 15000 + 10000) / 100.0;
        tripPointers[i]->conferenceFees = (rand() % 10000 + 10000) / 100.0;
        tripPointers[i]->hotelFees = tripPointers[i]->daysSpentOnTrip * (rand() % 9000 + 5000) / 100.0;
        tripPointers[i]->hotelFeesAllowable = tripPointers[i]->daysSpentOnTrip * 90;
        tripPointers[i]->mealFees = (rand() % 3900 + 500) / 100.0;
        if (tripPointers[i]->timeOfDeparture < 7) {
            tripPointers[i]->mealFeesAllowable += 9;
        } else if (tripPointers[i]->timeOfDeparture < 12) {
            tripPointers[i]->mealFeesAllowable += 12;
        } else if (tripPointers[i]->timeOfDeparture < 18) {
            tripPointers[i]->mealFeesAllowable += 15;
        }

        if (tripPointers[i]->timeOfArrival > 19) {
            tripPointers[i]->mealFeesAllowable += 15;
        } else if (tripPointers[i]->timeOfArrival > 13) {
            tripPointers[i]->mealFeesAllowable += 12;
        } else if (tripPointers[i]->timeOfArrival > 8) {
            tripPointers[i]->mealFeesAllowable += 9;
        }

        printf("Test %d:\n", i + 1);
        displayFees(tripPointers[i]);
        displayToUser(tripPointers[i]);
        puts("");
    }
    return 0;
}