#include <stdio.h>
#include <stdbool.h>
#include "CarExpenses.h"

// all calculations done in cents to avoid floating point imprecisions
float calculateCarExpenses(char vehicleType[])
{
    int costs = 0;

    while (true)
    {
        if (vehicleType == "Private")
        {
            costs += privateCar();
        }
        else if (vehicleType == "Taxi")
        {
            costs += taxi();
        }
        else if (vehicleType == "Rental")
        {
            costs += rental();
        }
        else
        {
            break;
        }
    }

    return costs / 100;
}

int privateCar()
{
    int cost = 0;

    // fee for mileage
    float milesDriven;
    printf("Miles driven: ");
    scanf("%f", &milesDriven);
    cost += milesDriven * 27;

    // parking (max $6)
    float parkingFee;
    printf("Parking fee (only up to $6 will be reimbursed.): ");
    scanf("%f", &parkingFee);

    if (parkingFee > 6)
    {
        parkingFee = 6;
    }
    cost += parkingFee * 100;

    return cost;
}

int taxi()
{
    float taxiFee;
    printf("Total taxi fee: ");
    scanf("%f", &taxiFee);

    if (taxiFee > 10)
    {
        taxiFee = 10;
    }

    return taxiFee * 100;
}

int rental()
{
    float rentalFee;
    printf("Rental fee: ");
    scanf("%f", &rentalFee);

    return rentalFee * 100;
}