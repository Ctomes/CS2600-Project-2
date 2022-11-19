#include <stdio.h>
#include <stdbool.h>
#include "CarExpenses.h"

// all calculations done in cents to avoid floating point imprecisions
float calculateCarExpenses()
{
    int costs = 0;
    char vehicleType[10];

    do
    {
        printf("Please enter the vehicle type. (enter end to stop): ");
        scanf("%s", vehicleType);

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
    } while (vehicleType != "end");

    return costs / 100;
}

int privateCar()
{
    int cost = 0;

    // fee for mileage
    float milesDriven = getValidFloat("Miles driven: ");
    cost += milesDriven * 27;

    // parking (max $6)
    float parkingFee = getValidFloat("Parking fee (only up to $6 will be reimbursed.): ");

    if (parkingFee > 6)
    {
        parkingFee = 6;
    }
    cost += parkingFee * 100;

    return cost;
}

int taxi()
{
    float taxiFee = getValidFloat("Total taxi fee (only up to $10 will be reimbursed.): ");

    if (taxiFee > 10)
    {
        taxiFee = 10;
    }

    return taxiFee * 100;
}

int rental()
{
    float rentalFee = getValidFloat("Rental fee: ");

    return rentalFee * 100;
}

float getValidFloat(char msg[])
{
    float valid;

    do
    {
        printf(msg);
        scanf("%f", valid);
    } while (valid < 0);

    return valid;
}