#include <stdio.h>
#include <string.h>
#include "../header/trip.h"
#include "../header/car_expenses.h"


// calls calculation functions for each vehicle type
// all calculations done in cents to avoid floating point imprecisions
int calculateCarExpenses(struct Trip *tripPointer)
{
    allCosts costs;
    costs.total = 0;
    costs.allowed = 0;

    char vehicleType[10] = "tmp";
    int valid;

    do
    {
        if (!strcasecmp(vehicleType, "private"))
        {
            privateCar(&costs);
        }
        else if (!strcasecmp(vehicleType, "taxi"))
        {
            taxi(&costs);
        }
        else if (!strcasecmp(vehicleType, "rental"))
        {
            rental(&costs);
        }

        printf("\nPlease enter the vehicle type.\n\tprivate | taxi | rental | end (to finish calculations): ");
        valid = scanf("%s", vehicleType);
        fflush(stdin);
    } while (valid != 1 || strcasecmp(vehicleType, "end"));

    tripPointer->allowedCarCost = costs.allowed / 100.0f;
    tripPointer->totalCarCost = costs.total / 100.0f;

    return 0;
}

// re-prompts user with given message until nonnegative float given
float getValidFloat(char msg[])
{
    float valid;
    int goodScan;

    do
    {
        printf("%s",msg);
        goodScan = scanf("%f", &valid);
        fflush(stdin);
    } while (goodScan != 1 || valid < 0);

    return valid;
}

// calculates mileage and parking expenses for private cars
void privateCar(struct allCosts *costs)
{
    // fee for mileage
    float milesDriven = getValidFloat("Miles driven: ") * 27;
    costs->total += milesDriven;
    costs->allowed += milesDriven;

    // parking (max $6)
    printf("\n");
    float parkingFee = getValidFloat("Parking fee (only up to $6 will be reimbursed.): ") * 100;
    costs->total += parkingFee;

    if (parkingFee > 600)
    {
        costs->allowed += 600.0;
    }
    else
    {
        costs->allowed += parkingFee;
    }
}

// limits and returns taxi fees
void taxi(struct allCosts *costs)
{
    float taxiFee = getValidFloat("Total taxi fee (only up to $10 will be reimbursed.): ") * 100;
    costs->total += taxiFee;

    if (taxiFee > 1000)
    {
        costs->allowed += 1000;
    }
    else
    {
        costs->allowed += taxiFee;
    }
}

// prompts for rental fees
void rental(struct allCosts *costs)
{
    float rentalFee = getValidFloat("Rental fee: ") * 100;
    costs->total += rentalFee;
    costs->allowed += rentalFee;
}