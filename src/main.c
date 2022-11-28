
// Tomes, Chris

// main.c
/*
Travel Expensese program.
main will be responsible for receiving user input and passing it off to help functions located in associated files.
Calculate and Display total travel expenses.

typedef struct trip {
    int daysSpentOnTrip;
    float timeOfDeparture;
    float timeOfArrival;
    float airfare;

    (not needed here)
        car vehicleType;
        float rentalCost;
        int milesDrivenInPrivateCar;
        float parkingFees;
        float taxiFees;

    float conferenceFees;
    float hotelFees;
    float mealFees;


} trip;

THE QUESTIONS:

PERSON 1.
--------
Ask user for total number of days spent on trip?

Ask user for time of departure on the first day of the trip AND time of arrival back on last day?

Ask for round trip airfare?

int calculateFlightExpenses(struct trip trip); pass a struct trip to function; should validate above input and store it.

PERSON 2.
Ask for cost of car rentals?

Private Vehicle used?
    -How many miles? expense =  .27$ per mile.

    Parking fees?
        only permit $6 per day.

Taxi fees?
    only permit $10 per day.

int calculateCarExpenses(struct trip trip); pass a struct trip to function; should validate above input and store it.

Person 3.
Conference/Seminar registration fees?

Hotel expenses?
    only permit 90$ per night for lodging.

int calculateConferenceExpenses(struct trip trip);
Person 4.
--------
Meal costs?

Permitted meals:
    Departure day: Breakfast before 7am | Lunch before noon. | Dinner before 6pm  "Time of Departure"
    Arrival day:   Breakfast before 8am | Lunch before 1pm. | Dinner before 7pm "Time of Arrival"

    cost of allowable meals: $9 for breakfast | $12 for lunch | $16 for dinner.


int calculateMealExpenses(struct trip trip);
float getTotalExpenses;
float getAllowableExpenses;
float getAmountSaved;

Display to User:
    Total expenses.
    Total allowable expenses.
    The excess the businessperson must reimburse if there is any.
    The amount saved if the expenses were under total allowed.


Input Validation:
    no negatives permitted.
    no less than 1's for days on tripe.
    only valid times for arrival/departure.
*/

#include <stdio.h>
#include "../header/trip.h"
#include "../header/car_expenses.h"

int main()
{
    printf("This program will impliment a trip calcular for Project 2 CS2600\n");
    Trip trip;
    Trip *tripPointer = &trip;

    /*
    PERSON 1.
    --------
    Ask user for total number of days spent on trip?
    Ask user for time of departure on the first day of the trip AND time of arrival back on last day?
    Ask for round trip airfare?
    int calculateFlightExpenses(struct trip trip); pass a struct trip to function; should validate above input and store it.
    */
    //calculateFlightExpenses(tripPointer);
    // simulate behavior:
    tripPointer->daysSpentOnTrip = 4;
    tripPointer->timeOfDeparture = 10.55;
    tripPointer->timeOfArrival = 16.30;
    tripPointer->airfare = 100.20;
    /*
    PERSON 2.
    Ask for cost of car rentals?
    Private Vehicle used?
        -How many miles? expense =  .27$ per mile.
    Parking fees?
        only permit $6 per day.
    Taxi fees?
        only permit $10 per day.
    */
    calculateCarExpenses(tripPointer);
    // simulate behavior:
    //tripPointer->rentalCost = 0;
    //tripPointer->milesDrivenInPrivateCar = 10;
    //tripPointer->parkingFees = 15;
    //tripPointer->taxiFees = 0;
    /*
    Person 3.
    Conference/Seminar registration fees?

    Hotel expenses?
        only permit 90$ per night for lodging.
    */
    //calculateConferenceExpenses(tripPointer);
    // simulate behavior:
    tripPointer->conferenceFees = 20;
    tripPointer->hotelFees = 360.99;
    tripPointer->mealFees = 25;
    /*
    Person 4.
    --------
    Meal costs?
    Permitted meals:
        Departure day: Breakfast before 7am | Lunch before noon. | Dinner before 6pm  "Time of Departure"
        Arrival day:   Breakfast before 8am | Lunch before 1pm. | Dinner before 7pm "Time of Arrival"
        cost of allowable meals: $9 for breakfast | $12 for lunch | $16 for dinner.
    */
    //calculateMealExpenses(tripPointer);
    /*
    Display to User:
        Total expenses.
        Total allowable expenses.
        The excess the businessperson must reimburse if there is any.
        The amount saved if the expenses were under total allowed.
    */
    //displayToUser(tripPointer);

    // showing a print:
    printf("Airfare: $%.02f\nDays spent on trip: %d \nDeparture: %.02f, Arrival: %.02f\n", trip.airfare, trip.daysSpentOnTrip, trip.timeOfDeparture, trip.timeOfArrival);
    return 0;
}