#include <stdio.h>
#include "../header/trip.h"

void displayToUser(struct Trip *tripPointer) {
    float totalExpenses = tripPointer->airfare + tripPointer->totalCarCost + tripPointer->conferenceFees 
            + tripPointer->hotelFees + tripPointer->mealFees;
    float totalAllowedExpenses = tripPointer->airfare + tripPointer->allowedCarCost + tripPointer->conferenceFees 
            + tripPointer->hotelFeesAllowable + tripPointer->mealFeesAllowable;

    printf("================================\n");
    printf("Total Expenses: $%.2f\n", totalExpenses);
    printf("Allowed Expenses: $%.2f\n", totalAllowedExpenses);
    if (totalExpenses > totalAllowedExpenses) {
        printf("Reimbursement Required: $%.2f\n", totalExpenses - totalAllowedExpenses);
    } else if (totalExpenses < totalAllowedExpenses) {
        printf("Amount Saved: $%.2f\n", totalAllowedExpenses - totalExpenses);
    }
}