#include <stdbool.h>
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
    int entryCount = 0;

    for (int i = 0; i < tripPointer->daysSpentOnTrip; i++)
    {
        printf("\n\nPlease enter 'yes' or 'no' for each vehicle type used on day %d.\n", i + 1);

        if (getValidYesNo("\nPrivate car?: "))
        {
            privateCar(&costs);
        }

        if (getValidYesNo("\nTaxi?: "))
        {
            taxi(&costs);
        }

        if (getValidYesNo("\nRental?: "))
        {
            rental(&costs);
        }
    }

    tripPointer->allowedCarCost = costs.allowed / 100.0f;
    tripPointer->totalCarCost = costs.total / 100.0f;

    return 0;
}

// re-prompts user with given message until either yes or no is entered
bool getValidYesNo(char msg[])
{
    char response[4];
    int goodScan;

    do
    {
        printf(msg);
        goodScan = scanf("%s", response);
        fflush(stdin);
    } while (goodScan != 1 || (strcasecmp(response, "yes") && strcasecmp(response, "no")));

    if (!(strcasecmp(response, "yes")))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// re-prompts user with given message until nonnegative float given
float getValidFloat(char msg[])
{
    float valid;
    int goodScan;

    do
    {
        printf(msg);
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

    // parking (max $6 allowed)
    float parkingFee = getValidFloat("Parking fee ($6 will be reimbursed.): ") * 100;
    costs->allowed += 600;
    costs->total += parkingFee;
}

// limits and returns taxi fees
void taxi(struct allCosts *costs)
{
    float taxiFee = getValidFloat("Total taxi fee ($10 will be reimbursed.): ") * 100;
    costs->allowed += 1000;
    costs->total += taxiFee;
}

// prompts for rental fees
void rental(struct allCosts *costs)
{
    float rentalFee = getValidFloat("Rental fee: ") * 100;
    costs->total += rentalFee;
    costs->allowed += rentalFee;
}