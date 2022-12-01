
// Tomes, Christopher - Team Leader - responsible for describing program flow, writing main, colaborating between branches, and validating merge conflictions. 


// main.c
/*
Travel Expensese program.
main will be responsible for receiving user input and passing it off to help functions located in associated files.
Calculate and Display total travel expenses.
*/
#include <stdio.h>
#include "../header/trip.h"
#include "../header/car_expenses.h"
#include "../header/flight_expenses.h"
#include "../header/display.h"
#include "../header/conference_fee.h"



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
    printf("Running Calculate flight expenses:\n");
    calculateFlightExpenses(tripPointer);
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
    printf("Running Calculate car expenses:\n");
    calculateCarExpenses(tripPointer);
    /*
    Person 3.
    Conference/Seminar registration fees?

    Hotel expenses?
        only permit 90$ per night for lodging.
    Meal costs?
    Permitted meals:
        Departure day: Breakfast before 7am | Lunch before noon. | Dinner before 6pm  "Time of Departure"
        Arrival day:   Breakfast before 8am | Lunch before 1pm. | Dinner before 7pm "Time of Arrival"
        cost of allowable meals: $9 for breakfast | $12 for lunch | $16 for dinner.
    */

       printf("Running Conference and meal expenses:\n");
       calculateConferenceExpenses(tripPointer);
    /*
        Person 4.
    Display to User:
        Total expenses.
        Total allowable expenses.
        The excess the businessperson must reimburse if there is any.
        The amount saved if the expenses were under total allowed.
    */
   //displaying to user.
    displayToUser(tripPointer);
    
    return 0;
}