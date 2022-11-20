#include <stdio.h>
#include "../CarExpenses.h"

void getValidFloatTest()
{
    printf("\nYou'll be asked to re-enter a number until you enter a nonnegative number.\n\n");

    float validated = getValidFloat("Enter a float: ");
    printf("\nYou entered %f.\n\n", validated);
}

void privateCarTest()
{
    printf("Miles driven and parking fee must be nonnegative. Miles are reimbursed at $0.27/mile. Parking fee is capped at $6.\n\n");
    int cost = privateCar();

    printf("\n$0.27 * miles + parking = $%.2f reimbursed\n\n", cost / 100.0f);
}

void taxiTest()
{
    printf("Taxi fees must be nonnegative and capped at $10.\n\n");
    int cost = taxi();

    printf("\nTaxi fees reimbursed: $%.2f\n\n", cost / 100.0f);
}

void rentalTest()
{
    printf("Rental car fees must be nonnegative.\n\n");
    int cost = rental();

    printf("\nRental fees reimbursed: $%.2f\n\n", cost / 100.0f);
}

void calculateCarExpensesTest()
{
    printf("The central calculation function should use input validation and correctly sum the costs of all vehicle types of the trip.\n\n");
    float total = calculateCarExpenses();

    printf("\nTotal expenses of that trip: $%.2f\n\n", total);
}

int main()
{
    getValidFloatTest();
    privateCarTest();
    taxiTest();
    rentalTest();
    calculateCarExpensesTest();

    return 0;
}