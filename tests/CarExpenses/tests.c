#include <stdbool.h>
#include <stdio.h>
#include "../../header/car_expenses.h"
#include "../../header/trip.h"

allCosts createZeroCosts()
{
    allCosts cost;
    cost.allowed = 0;
    cost.total = 0;

    return cost;
}

void getValidFloatTest()
{
    printf("\nYou'll be asked to re-enter a number until you enter a nonnegative number.\n\n");

    float validated = getValidFloat("Enter a float: ");
    printf("\nYou entered %f.\n\n", validated);
}

void getValidYesNoTest()
{
    printf("You'll be asked to re-enter your response until you enter 'yes' or 'no'.\n\n");

    if (getValidYesNo("Enter 'yes' or 'no': "))
    {
        printf("\nYou entered 'yes'.\n\n");
    }
    else
    {
        printf("\nYou entered 'no'.\n\n");
    }
}

void privateCarTest()
{
    printf("Miles driven and parking fee must be nonnegative. Miles are reimbursed at $0.27/mile. Parking fee is capped at $6.\n\n");

    allCosts cost = createZeroCosts();
    privateCar(&cost);

    printf("\n$0.27 * miles + parking = $%.2f reimbursed out of $%.2f total\n\n", cost.allowed / 100.0f, cost.total / 100.0f);
}

void taxiTest()
{
    printf("Taxi fees must be nonnegative and capped at $10.\n\n");

    allCosts cost = createZeroCosts();
    taxi(&cost);

    printf("\nTaxi fees reimbursed: $%.2f (out of $%.2f total)\n\n", cost.allowed / 100.0f, cost.total / 100.0f);
}

void rentalTest()
{
    printf("Rental car fees must be nonnegative.\n\n");

    allCosts cost = createZeroCosts();
    rental(&cost);

    printf("\nAll rental fees reimbursed: $%.2f\n\n", cost.total / 100.0f);
}

void calculateCarExpensesTest()
{
    Trip trp;
    trp.daysSpentOnTrip = 5;
    printf("The central calculation function should use input validation and correctly sum the costs of all vehicle types of the trip.\n");
    float total = calculateCarExpenses(&trp);

    printf("\nReimbursed expenses of that trip: $%.2f (out of $%.2f total)\n\n", trp.allowedCarCost, trp.totalCarCost);
}

int main()
{
    calculateCarExpensesTest();
    getValidFloatTest();
    getValidYesNoTest();
    privateCarTest();
    taxiTest();
    rentalTest();

    return 0;
}